#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_video.h"
#include "base.h"

int main(void)
{
  int rps = 60; //Renders per-second
  int pps = 120; //Processes per-second
  int p = 0;

  init();

  backgroundColor = createColor(0,0,0,255);

  //Setting up a varible to control when the game runs
  bool running = true; //Duh! Can't run the game without this being true!

  //Main game loop which contains, well, everything!
  while(running)
  {
    //Then a wee little event loop for keystrokes, mouse movements, and etc...
    while(SDL_PollEvent(&event))
    {
      //Shuts down the game when the user tries to quit
      if(event.type == SDL_QUIT)
      {
        running = false;
      }
    }
    //Runs all of the pre-rendering code here
    if(p % rps == 0)
    {
      clear();
    }

    //Draws all pre-renders
    if(p % rps == 1)
    {
      SDL_RenderPresent(ren);
    }

    //Steps the p variable
    if(p < pps)
    {
      p++;
    }
    else
    {
      p = 0;
    }

    //Adds a delay that makes the program run at a frequency of variable pps
    SDL_Delay(1000/pps);
  }

  SDL_DestroyWindow(win);
  return 0;
}
