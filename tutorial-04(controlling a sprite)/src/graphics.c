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

  /* Clear the screen */
  SDL_RenderClear(game.render);
  /* Create texture and render it to screen */
  SDL_Texture *texture = SDL_CreateTextureFromSurface(game.render, image);
  SDL_RenderCopy(game.render, texture, NULL, &dest);
  /* Destroy the temporary texture */
  SDL_DestroyTexture(texture);
}

void loadSprite(int index, char *name) {
  /* Load the image into the next slot in the sprite bank */
  if (index >= MAX_SPRITES || index < 0) {
    printf("Invalid index for sprite! Index: %d Maximum: %d\n", index, MAX_SPRITES);
    exit(1);
  };
  sprite[index].image = loadImage(name);

  if (sprite[index].image == NULL) {
    exit(1);
  };
}

SDL_Surface *getSprite(int index) {
  if (index >= MAX_SPRITES || index < 0) {
    printf("Invalid index for sprite! Index: %d Maximum: %d\n", index, MAX_SPRITES);
    exit(1);
  };
  return sprite[index].image;
}

void freeSprites() {
  int i;

  /* Loop through the sprite bank and clear the images */
  for (i=0;i<MAX_SPRITES;i++) {
    if (sprite[i].image != NULL) {
      SDL_FreeSurface(sprite[i].image);
    };
  };
}

void loadAllSprites() {
  loadSprite(PLAYER_SPRITE, "res.img/ship.bmp");
}
