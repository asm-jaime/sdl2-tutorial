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

typedef struct Sound {
  Mix_Chunk *effect;
} Sound;


typedef struct Entity {
  int x, y, w, h;
  int active;
  int thinkTime;
  SDL_Texture *texture;
  void (*action)(void);
  void (*draw)(void);
} Entity;

typedef struct Control {
  int up, down, left, right, fire;
} Control;
