#include "base.h"
#include <string.h>
#include <math.h>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_render.h"

texts = 0;

color createColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  color out;
  out.r = r;
  out.g = g;
  out.b = b;
  out.a = a;
  return out;
}

void init()
{
  //Starting up good 'ol SDL2 with video
  SDL_Init(SDL_INIT_VIDEO);

  //Gota have a window for a game right? (Don't worry: win does not stand for winblows)
  win = SDL_CreateWindow("spacegame",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 640, 400, SDL_WINDOW_RESIZABLE);

  //Creating a renderer to draw stuff like textures
  ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
}

void setDrawColor(color in)
{
  SDL_SetRenderDrawColor(ren,in.r,in.g,in.b,in.a);
}

void clear()
{
  setDrawColor(backgroundColor);
  SDL_RenderClear(ren);
}

obj createShip(char sprite[], int flags, double scale, double mass)
{
  SDL_Surface *buff = IMG_Load(sprite);
  if(buff == NULL)
  {
    if(BASE_DEBUG)
    {
      puts("could not find original texture: loading fallback");
    }
    buff = IMG_Load("resources/sprites/null-ship.png");
  }
  if(buff == NULL)
  {
    fprintf(stderr,"Could not load resources/sprites/null-ship.png: %s\n",SDL_GetError());
  }
  SDL_Texture *outt = SDL_CreateTextureFromSurface(ren,buff);
  obj out;
  out.flags = TYPE_SHIP | flags;
  out.scale = scale;
  out.texture = outt;
  out.mass = mass;
  return out;
}

int loadTexture(char tex[])
{
  SDL_Surface *buff = IMG_Load(tex);
  if(buff == NULL)
  {
    if(BASE_DEBUG)
    {
      puts("could not find original texture: loading fallback");
    }
    buff = IMG_Load("resources/sprites/null-ship.png");
  }
  if(buff == NULL)
  {
    fprintf(stderr,"Could not load resources/sprites/null-ship.png: %s\n",SDL_GetError());
  }
  texture out;
  out.data = SDL_CreateTextureFromSurface(ren,buff);
  strcpy(out.file,tex);
  textures[texts] = out;
  texts++;
}

int textureIndex(char tex[])
{
  int i = 0;
  while(i < MAX_TEX)
  {
    if(strcmp(textures[i].file,tex) == 0)
    {
      return i;
    }
    i++;
  }
  return -1;
}

int drawShip(obj *ship)
{
  if(ship->flags & TYPE_SHIP)
  {
  }
  else
  {
    fprintf(stderr,"ship is not a ship ¯\\_(ツ)_/¯\n");
    return -2;
  }

  SDL_Rect pos;
  int w, h;

  SDL_QueryTexture(ship->texture, NULL, NULL, &w, &h);

  if(ship->flags & OBJ_PLAYER)
  {
    pos.w = w*ship->scale;
    pos.h = h*ship->scale;
    SDL_GetWindowSize(win,&pos.x,&pos.y);
    pos.x = pos.x/2 - pos.w/2 - ship->vel.x;
    pos.y = pos.y/2 - pos.h/2 - ship->vel.y;
  }
  else
  {
    pos.w = w*ship->scale;
    pos.h = h*ship->scale;
    pos.x = ship->pos.x - pos.w/2;
    pos.y = ship->pos.y - pos.h/2;
  }
  SDL_RenderCopyEx(ren, ship->texture, NULL, &pos, ship->pos.ang, NULL, 0);
  return 0;
}

void applyForce(obj *subject, vec force)
{
  subject->vel.x += force.x/(subject->mass*pps);
  subject->vel.y += force.y/(subject->mass*pps);
  subject->vel.ang += force.ang/(subject->mass*pps);
}

void tick(obj *subject)
{
  subject->pos.x += subject->vel.x/pps;
  subject->pos.y += subject->vel.y/pps;
  subject->pos.ang += subject->vel.ang/pps;
}

vec vect(double x, double y, double ang)
{
  vec out;
  out.x = x;
  out.y = y;
  out.ang = ang;
  return out;
}

vec split(double magnitude, double direction)
{
  vec out;
  out.y = sin(direction*M_PI/180 - M_PI/2)*magnitude;
  out.x = cos(direction*M_PI/180 - M_PI/2)*magnitude;
  return out;
}

double fnegf(double a)
{
  return a > 0 ? 1 : a < 0 ? -1 : 0;
}

int minabs(int a, int b)
{
  if(abs(a) < abs(b))
  {
    return a;
  }
  else if(abs(b) < abs(a))
  {
    return b;
  }
  return a; //this is when the absolute values are the same
}

int maxabs(int a, int b)
{
  if(abs(a) > abs(b))
  {
    return a;
  }
  else if(abs(b) > abs(a))
  {
    return b;
  }
  return a; //this is when the absolute values are the same
}

double minabsf(double a, double b)
{
  if(fabs(a) < fabs(b))
  {
    return a;
  }
  else if(fabs(b) < fabs(a))
  {
    return b;
  }
  return a; //this is when the absolute values are the same
}

double maxabsf(double a, double b)
{
  if(fabs(a) > fabs(b))
  {
    return a;
  }
  else if(fabs(b) > fabs(a))
  {
    return b;
  }
  return a; //this is when the absolute values are the same
}
