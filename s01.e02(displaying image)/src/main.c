/* This tutorial will open a 640 x 480 screen,
 * load an image and display it at specified coordinates
 * and wait for the user to either close
 * the window or press escape */

#include "main.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern SDL_Surface *loadImage(char *);
extern void updateScreen(void);

int main(void) {
  int go;
  /* Start up SDL2 */
  init("Parallel Realities Tutorial 2");
  /* Call the cleanup function when the program exits */
  atexit(cleanup);
  go = 1;
  clipperImage = loadImage("../res.img/clipper.jpg");
  /* If we get back a NULL image, just exit */
  if (clipperImage == NULL) {
    exit(0);
  }

  /* Loop indefinitely for messages */
  while (go == 1) {
    getInput();
    updateScreen();
    /* Sleep briefly to stop sucking up all the CPU time */
    SDL_Delay(16);
  }

  /* Exit the program */
  exit(0);
}
