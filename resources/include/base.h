#include "SDL2/SDL.h"

#ifndef BASE_H_
#define BASE_H_

#define TYPE_SHIP 1
#define TYPE_BODY 2 //body just means celestial body: a planet, star, commet, and maybe even asteroids
#define OBJ_PLAYER 4

typedef struct color
{
  Uint8 r;
  Uint8 g;
  Uint8 b;
  Uint8 a;
} color;

typedef struct vec
{
  float x;
  float y;
  float ang;
} vec;

typedef struct obj
{
  vec pos;
  vec vel;
  int mass;
  char texture[128];
  int flags;
} obj;

color backgroundColor;

color createColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

SDL_Window *win;

SDL_Renderer *ren;

//Making a varible for events like keypresses, mouse movements, etc...
SDL_Event event;

void init();

void setDrawColor(color in);

void clear();

obj createShip(char sprite[]);

int drawShip(obj ship);

#endif
