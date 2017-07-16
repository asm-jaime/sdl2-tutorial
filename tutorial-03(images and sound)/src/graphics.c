#include "graphics.h"

SDL_Surface *loadImage(char *name) {
  /* Load the image using SDL Image */
  SDL_Surface *temp = IMG_Load(name);

  if (temp == NULL) {
    printf("Failed to load image %s\n", name);
    return NULL;
  };

  /* Return the processed image */
  return temp;
}

void drawImage(SDL_Surface *image, int x, int y) {
  SDL_Rect dest;

  /* Set the blitting rectangle to the size of the src image */
  dest.x = x;
  dest.y = y;
  dest.w = image->w;
  dest.h = image->h;

  /* Blit the entire image onto the screen at coordinates x and y */
  SDL_Texture *texture = SDL_CreateTextureFromSurface(render, image);
  SDL_RenderCopy(render, texture, NULL, &dest);
}

void updateScreen() {
  /* Draw the image to 160, 120 */
  drawImage(clipperImage, 160, 120);

  /* Swap the image buffers */
  SDL_RenderPresent(render);
}
