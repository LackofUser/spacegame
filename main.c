#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "base.h"

int main(void)
{
	int rps = 60; // renders per second
	int pps = 120; // processes per second
	int p = 0; //iterative variable for multitasking stuff

	init();

	obj playerShip = createShip("resources/sprites/null-ship.png", OBJ_PLAYER,10); //Creates the a ship as the player

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
		// runs all of the pre-rendering code here
		if(p % rps == 0)
		{
			clear();
			drawShip(playerShip);
		}

		// draws all pre-renders
		if(p % rps == 1)
		{
			SDL_RenderPresent(ren);
		}

		// steps the p variable
		printf("p:%d\r",p);
		if(p < pps)
		{
			p++;
		}
		else
		{
			p = 0;
		}

		// adds a delay that makes the program run at a frequency of variable pps
		SDL_Delay(1000/pps);
	}
	SDL_DestroyWindow(win);
}
