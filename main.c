#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "base.h"

struct ctrls
{
	ctrl up;
 	ctrl down;
	ctrl right;
	ctrl left;
} ctrls;

int main(void)
{
	ctrls.up.key = SDLK_w;
	ctrls.down.key = SDLK_s;
	ctrls.right.key = SDLK_d;
	ctrls.left.key = SDLK_a;

	double scale;

	struct winsize{
		int x;
		int y;
	} winsize;

	rps = 60; // fps cap (125/2) = 62.5 get over it
	pps = 120; // processes per second
	p = 0; //iterative variable for multitasking stuff
	float tang = 0; //target angle for the player
	float sang = 90;
	float tvel;
	init();

	obj playerShip = createShip("resources/sprites/ship-body.png", OBJ_PLAYER, 10, 100); //Creates the a ship as the player

	playerShip.pos.ang = 90;
	playerShip.vel.ang = 0;


	backgroundColor = createColor(0,0,0,255);

	bool running = true;

	while(running)
	{

		SDL_GetWindowSize(win, &winsize.x, &winsize.y);

		scale = winsize.x < winsize.y ? winsize.x/(float)30 : winsize.y < winsize.x ? winsize.y/(float)30 : winsize.x/(float)30;

		playerShip.scale = scale;

		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				running = false;
			}

			if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == ctrls.up.key)
				{
					ctrls.up.value = 1;
				}
				if(event.key.keysym.sym == ctrls.down.key)
				{
					ctrls.down.value = 1;
				}
				if(event.key.keysym.sym == ctrls.right.key)
				{
					ctrls.right.value = 1;
				}
				if(event.key.keysym.sym == ctrls.left.key)
				{
					ctrls.left.value = 1;
				}
			}

			if(event.type == SDL_KEYUP)
			{
				if(event.key.keysym.sym == ctrls.up.key)
				{
					ctrls.up.value = 0;
				}
				if(event.key.keysym.sym == ctrls.down.key)
				{
					ctrls.down.value = 0;
				}
				if(event.key.keysym.sym == ctrls.right.key)
				{
					ctrls.right.value = 0;
				}
				if(event.key.keysym.sym == ctrls.left.key)
				{
					ctrls.left.value = 0;
				}
			}

		}

		if(ctrls.up.value || ctrls.down.value || ctrls.right.value || ctrls.left.value)
		{
			tang = (ctrls.down.value*180 + ctrls.right.value*90 - ctrls.left.value*90)/(ctrls.up.value + ctrls.down.value + ctrls.right.value + ctrls.left.value);
		}

		/*if(fabsf(playerShip.vel.ang) <= 1)
		{
			sang = playerShip.pos.ang;
		}
		tvel = -fnegf(tang - playerShip.pos.ang)*(tang - playerShip.pos.ang + fabsf(tang+sang-playerShip.pos.ang*2));
		applyForce(&playerShip,vect(0,0,((tang+sang-playerShip.pos.ang*2) + (tvel - playerShip.vel.ang))*playerShip.mass));
*/
		applyForce(&playerShip,vect(0,0,((tang-playerShip.pos.ang)*100 -fabsf(playerShip.vel.ang)*playerShip.vel.ang)*playerShip.mass));

		tick(&playerShip);

		// runs all of the pre-rendering code here
		if(p % (int)(pps/rps) == 0)
		{
			clear();
			drawShip(playerShip);
		}

		// draws all pre-renders
		if(p % (int)(pps/rps) == 1 || pps <= rps)
		{
			SDL_RenderPresent(ren);
		}

		// steps the p variable
		if(p < pps)
		{
			p++;
		}
		else
		{
			p = 0;
		}
		printf("                tva:%f      \r", tvel);
		printf("va:%f\r",playerShip.vel.ang);
		fflush(stdout);

		// adds a delay that makes the program run at a frequency of variable pps
		SDL_Delay(1000/pps);
	}
	SDL_DestroyWindow(win);
}
