#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "base.h"

int main(void)
{
	int rps = 62; // fps cap (125/2) = 62.5 get over it
	int pps = 125; // processes per second
	int p = 0; //iterative variable for multitasking stuff
	init();

	obj playerShip = createShip("resources/sprites/null-ship.png",OBJ_PLAYER,3); //Creates the a ship as the player

	playerShip.pos.ang = 90;


	backgroundColor = createColor(0,0,0,255);

	bool running = true;

	while(running)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				running = false;
			}
		}

		playerShip.pos.ang += 1;
		if(playerShip.pos.ang >= 180)
		{
			playerShip.pos.ang = -180;
		}

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
		printf("p:%d   \r",p);
		fflush(stdout);

		// adds a delay that makes the program run at a frequency of variable pps
		SDL_Delay(1000/pps);
	}
	SDL_DestroyWindow(win);
}
