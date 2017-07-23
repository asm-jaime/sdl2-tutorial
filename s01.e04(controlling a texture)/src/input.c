#include "input.h"

void getInput() {
  SDL_Event event;

  /* Loop through waiting messages and process them */
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      /* Closing the Window or pressing Escape will exit the program
       * Pressing the arrow keys will move the player */

      case SDL_QUIT:
        exit(0);
        break;

      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_UP:
            input.up = 1;
            break;

          case SDLK_DOWN:
            input.down = 1;
            break;

          case SDLK_LEFT:
            input.left = 1;
            break;

          case SDLK_RIGHT:
            input.right = 1;
            break;

          case SDLK_ESCAPE:
            exit(0);
            break;

          default:
          break;
        };
        break;

      case SDL_KEYUP:
        switch (event.key.keysym.sym) {
          case SDLK_UP:
            input.up = 0;
            break;

          case SDLK_DOWN:
            input.down = 0;
            break;

          case SDLK_LEFT:
            input.left = 0;
            break;

          case SDLK_RIGHT:
            input.right = 0;
            break;

          default:
            break;
        };
        break;
    };
  };
}
