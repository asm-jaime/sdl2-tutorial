#include "init.h"

static Win win = NULL;

void init(char *title) {
  /* Initialise SDL Video */
  if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) {
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

  /* Set the audio rate to 22050, 16 bit stereo, 2 channels and a 4096 byte buffer */
  if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != 0) {
    printf("Could not open audio: %s\n", Mix_GetError());
    exit(1);
  };
}

void cleanup() {
  /* Shut down SDL */
  SDL_DestroyTexture(clipperTexture);
  SDL_FreeSurface(clipperImage);
  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(win);
  /* Free the sound effect */
  if (seaSong != NULL) {
    Mix_FreeChunk(seaSong);
  };
  /* Close the mixer */
  Mix_CloseAudio();
  SDL_Quit();
}
