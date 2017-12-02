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
