/* This tutorial will open a 640 x 480 screen,
 * load an image and allow the user to control it
 * using the arrow keys. Pressing escape
 * or closing the window will exit the program  */

#include "main.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void draw(void);
extern void initPlayer(void);
extern void doPlayer(void);
extern void doEntities(void);
extern void loadAllTextures(void);
extern void delay(unsigned int);

int main(void) {
  unsigned int frameLimit = SDL_GetTicks() + 16;
  int go;
  /* Start up SDL */
  init("Parallel Realities Tutorial 4");

  /* Call the cleanup function when the program exits */
  atexit(cleanup);
  go = 1;

  /* Load all the sprites */
  loadAllTextures();

  /* Intialise the player */
  initPlayer();

  /* Loop indefinitely for messages */
  while (go == 1) {
    /* Get the input */
    getInput();

    /* Update the player's position */
    doPlayer();

    /* Draw everything */
    draw();

    /* Sleep briefly to stop sucking up all the CPU time */
    delay(frameLimit);
    frameLimit = SDL_GetTicks() + 16;
  };

  /* Exit the program */
  exit(0);
}
