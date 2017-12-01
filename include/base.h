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

#endif
