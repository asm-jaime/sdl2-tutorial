#include "defs.h"

typedef struct Game {
  SDL_Renderer *render;
} Game;

typedef struct Sprites {
  SDL_Surface *image;
} Sprites;

typedef struct Textures {
  SDL_Texture *texture;
} Textures;

typedef struct Entity {
  int x, y, w, h;
  SDL_Texture *texture;
} Entity;

typedef struct Control {
  int up, down, left, right;
} Control;
