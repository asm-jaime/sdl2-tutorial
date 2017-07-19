#include "defs.h"

typedef struct Game {
  SDL_Renderer *render;
} Game;

typedef struct Sprites {
  SDL_Surface *image;
} Sprites;

typedef struct Entity {
  int x, y;
  SDL_Surface *sprite;
} Entity;

typedef struct Control {
  int up, down, left, right;
} Control;
