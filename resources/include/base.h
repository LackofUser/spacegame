#include "SDL2/SDL.h"

#ifndef BASE_H_
#define BASE_H_

#define MAX_OBJ 3
#define MAX_PAR 3
#define MAX_TEX 2

#define OBJ_PLAYER 1
#define TYPE_SHIP 2
#define TYPE_BODY 4 //body just means celestial body: a planet, star, commet, and maybe even asteroids
#define TYPE_ENTITY 8 //Things like debris, dust, and thruster effects
#define BASE_DEBUG 0

typedef struct texture
{
	SDL_Texture *data;
	char file[];
}

typedef struct ctrl
{
	SDL_Keycode key;
	double value;
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
  double x;
  double y;
  double ang;
} vec;

typedef struct obj
{
  vec pos;
  vec vel;
  double mass;
  SDL_Texture *texture;
  double scale;
  int flags;
} obj;

typedef struct particle
{
	vec pos;
	SDL_Texture *texture;
	double scale;
	obj *parent; //The particle will inherit the parent's velocity, it's a pointer so you don't have to update this child constantly
	bool local; //This just means that the position of the particle will be relative to the parent (if the parent exists)
} particle;

texture textures[MAX_TEX];
int texts = 0;

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

obj createShip(char sprite[], int flags, double scale, double mass);

int loadTexture(char tex[]);

int textureIndex(char tex[]);

int drawShip(obj ship);

void applyForce(obj *subject, vec force);

void tick(obj *subject);

vec vect(double x, double y, double ang);

vec split(double magnitude, double direction);

double fnegf(double a);

int minabs(int a, int b);

int maxabs(int a, int b);

double minabsf(double a, double b);

double maxabsf(double a, double b);

#endif
