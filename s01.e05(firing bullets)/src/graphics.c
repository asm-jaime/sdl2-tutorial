#include "graphics.h"

/* sprites */

SDL_Surface *loadImage(char *name) {/*{{{*/
  /* Load the image using SDL Image */
  SDL_Surface *temp = IMG_Load(name);

  if (temp == NULL) {
    printf("Failed to load image %s\n", name);
    return NULL;
  };

  /* Return the processed image */
  return temp;
}/*}}}*/

/* textures */

void loadTexture(int index, char *name) {/*{{{*/
  /* Load the image into the next slot in the sprite bank */
  if (index >= MAX_SPRITES || index < 0) {
    printf("Invalid index for sprite! Index: %d Maximum: %d\n", index, MAX_SPRITES);
    exit(1);
  };
  SDL_Surface *temp = loadImage(name);
  texture[index].texture = SDL_CreateTextureFromSurface(game.render, temp);

  SDL_FreeSurface(temp);
  if (texture[index].texture == NULL) {
    exit(1);
  };
}/*}}}*/

void drawTexture(SDL_Texture *texture, int x, int y) {/*{{{*/
  SDL_Rect dest;

  /* Set the blitting rectangle to the size of the src image */
  dest.x = x;
  dest.y = y;
  SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

  /* Clear the screen */
  SDL_RenderClear(game.render);

  /* copy texture to render */
  SDL_RenderCopy(game.render, texture, NULL, &dest);
}/*}}}*/

SDL_Texture *getTexture(int index) {/*{{{*/
  if (index >= MAX_TEXTURES || index < 0) {
    printf("Invalid index for texture! Index: %d Maximum: %d\n", index, MAX_TEXTURES);
    exit(1);
  };
  return texture[index].texture;
}/*}}}*/

void loadAllTextures() {/*{{{*/
  loadTexture(PLAYER_SPRITE, "res.img/ship.bmp");
}/*}}}*/

void freeTextures() {/*{{{*/
  /* Loop through the sprite bank and clear the images */
  for (int i=0; i<MAX_TEXTURES; i++) {
    if (texture[i].texture != NULL) {
      SDL_DestroyTexture(texture[i].texture);
    };
  };
}/*}}}*/
