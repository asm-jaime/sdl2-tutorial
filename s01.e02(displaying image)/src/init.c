#include "init.h"

static Win win = NULL;

void init(char *title) {
  /* Initialise SDL Video */
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Could not initialize SDL: %s\n", SDL_GetError());
    exit(1);
  };

  /* Open a GAME_W x GAME_H screen */
  win = SDL_CreateWindow(title, -1, -1, GAME_W, GAME_H, 0);
  render = SDL_CreateRenderer(win, 0, SDL_RENDERER_PRESENTVSYNC);
  SDL_RenderSetLogicalSize(render, GAME_W, GAME_H);

  if (win == NULL) {
    printf("Couldn't set screen mode to %d x %d: %s\n",
        GAME_W, GAME_H, SDL_GetError());
    exit(1);
  };
}

void cleanup() {
  /* Shut down SDL */
  SDL_DestroyTexture(clipperTexture);
  SDL_FreeSurface(clipperImage);
  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
