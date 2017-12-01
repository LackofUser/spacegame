#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_video.h"

int main(void)
{
  //Starting up good 'ol SDL2 with video
  SDL_Init(SDL_INIT_VIDEO);

  //Gota have a window for a game right? (Don't worry: win does not stand for winblows)
  SDL_Window *win = SDL_CreateWindow("spacegame",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 640, 400, SDL_WINDOW_RESIZABLE);

  //Making a varible for events like keypresses, mouse movements, etc...
  SDL_Event event;

  //Setting up a varible to control when the game runs
  bool running = true; //Duh!

  //Main game loop which contains, well, everything!
  while(running)
  {
    //Then a wee little event loop for keystrokes mouse movements, and etc...
    while(SDL_PollEvent(&event))
    {
      //Shuts down the game when the user tries to quit
      if(event.type == SDL_QUIT)
      {
        running = false;
      }
    }
  }

  SDL_DestroyWindow(win);
  return 0;
}
