#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_video.h"
#include "base.h"

int rps = 30;
int pps = 100;
int p = 0;
int main(void)
{
  //Starting up good 'ol SDL2 with video
  SDL_Init(SDL_INIT_VIDEO);

  //Gota have a window for a game right? (Don't worry: win does not stand for winblows)
  SDL_Window *win = SDL_CreateWindow("spacegame",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 640, 400, SDL_WINDOW_RESIZABLE);

  //Creating a renderer to draw stuff like textures
  SDL_Renderer *ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);

  //Making a varible for events like keypresses, mouse movements, etc...
  SDL_Event event;

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

    }

    //Draws all pre-renders
    if(p % rps == 1)
    {
      
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
