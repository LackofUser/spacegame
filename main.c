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
		}

		// draws all pre-renders
		if(p % rps == 1)
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

		// adds a delay that makes the program run at a frequency of variable pps
		SDL_Delay(1000/pps);
	}
	SDL_DestroyWindow(win);
}
