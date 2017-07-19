#include "init.h"

static Win win = NULL;

void init(char *title) {
  /* Initialise SDL Video */
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Could not initialize SDL: %s\n", SDL_GetError());
    exit(1);
  };

  /* Open a window with SCREEN_WIDTH x SCREEN_HEIGHT */
  win = SDL_CreateWindow(title, -1, -1, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  game.render = SDL_CreateRenderer(win, 0, SDL_RENDERER_PRESENTVSYNC);
  SDL_RenderSetLogicalSize(game.render, SCREEN_WIDTH, SCREEN_HEIGHT);

  if (win == NULL) {
    printf("Couldn't set screen mode to %d x %d: %s\n",
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
    exit(1);
  };
}

void cleanup() {
  /* Shut down SDL */
  freeSprites();
  SDL_DestroyRenderer(game.render);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
