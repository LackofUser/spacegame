#include "base.h"
#include <string.h>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_render.h"

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

obj createShip(char sprite[])
{
  obj out;
  strcpy(out.texture,sprite);
  out.flags = TYPE_SHIP;
  return out;
}

int drawShip(obj ship)
{
  if(ship.flags & TYPE_SHIP != 1)
  {
    fprintf(stderr,"obj is not of type ship\n");
    return -2;
  }
  SDL_Surface *buff = IMG_Load(ship.texture);
  SDL_Texture *draw = SDL_CreateTextureFromSurface(ren,buff);
  SDL_Rect pos;
  if(buff == NULL)
  {
    buff = IMG_Load("resources/sprites/null.png");
  }
  if(buff == NULL)
  {
    fprintf(stderr,"Could not load %s: %s\n",ship.texture,SDL_GetError());
    return -1;
  }
  if(ship.flags & OBJ_PLAYER)
  {
    pos.w = buff->w;
    pos.h = buff->h;
    SDL_GetWindowSize(win,&pos.x,&pos.y);
    pos.x = pos.x/2 - pos.w/2;
    pos.y = pos.y/2 - pos.h/2;
  }
  else
  {
    pos.w = buff->w;
    pos.h = buff->h;
    pos.x = ship.pos.x - pos.w/2;
    pos.y = ship.pos.y - pos.h/2;
  }
  SDL_RenderCopyEx(ren, draw, NULL, &pos, ship.pos.ang, NULL, 0);
  return 0;
}
