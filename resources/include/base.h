#include "SDL2/SDL.h"

#ifndef BASE_H_
#define BASE_H_

#define OBJ_PLAYER 1
#define TYPE_SHIP 2
#define TYPE_BODY 4 //body just means celestial body: a planet, star, commet, and maybe even asteroids
#define TYPE_ENTITY 8 //Things like debris, dust, and thruster effects
#define BASE_DEBUG 0

typedef struct ctrl
{
	SDL_Keycode key;
	float value;
} ctrl;

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
  float mass;
  SDL_Texture *texture;
  float scale;
  int flags;
} obj;

int rps;
int pps;
int p;

color backgroundColor;

color createColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

SDL_Window *win;

SDL_Renderer *ren;

//Making a varible for events like keypresses, mouse movements, etc...
SDL_Event event;

void init();

void setDrawColor(color in);

void clear();

obj createShip(char sprite[], int flags, float scale, float mass);

int drawShip(obj ship);

void applyForce(obj *subject, vec force);

void tick(obj *subject);

vec vect(float x, float y, float ang);

float fnegf(float a);

#endif
