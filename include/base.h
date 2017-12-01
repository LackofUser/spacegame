#include "SDL2/SDL.h"

#ifndef BASE_H_
#define BASE_H_

typedef struct color{
  Uint8 r;
  Uint8 g;
  Uint8 b;
  Uint8 a;
} color;

color backgroundColor;

color createColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

SDL_Window *win;

SDL_Renderer *ren;

//Making a varible for events like keypresses, mouse movements, etc...
SDL_Event event;

void init();

void setDrawColor(color in);

void clear();

#endif
