#include "player.h"

extern int loadSprite(char *);
extern void drawImage(SDL_Surface *, int, int);
extern SDL_Surface *getSprite(int);

void initPlayer() {
  player.sprite = getSprite(PLAYER_SPRITE);

  player.x = SCREEN_WIDTH / 2;
  player.y = SCREEN_HEIGHT / 2;
}

void doPlayer() {
  if (input.up == 1)  {
    player.y -= 3;

    /* Don't allow the player to move off the screen */
    if (player.y < 0) {
      player.y = 0;
    };
  };

  if (input.down == 1) {
    player.y += 3;

    /* Don't allow the player to move off the screen */
    if (player.y + player.sprite->h >= SCREEN_HEIGHT)    {
      player.y = SCREEN_HEIGHT - (player.sprite->h + 1);
    };
  };

  if (input.left == 1) {
    player.x -= 3;

    /* Don't allow the player to move off the screen */
    if (player.x < 0) {
      player.x = 0;
    };
  };

  if (input.right == 1) {
    player.x += 3;

    /* Don't allow the player to move off the screen */
    if (player.x + player.sprite->w >= SCREEN_WIDTH) {
      player.x = SCREEN_WIDTH - (player.sprite->w + 1);
    };
  };
}

void drawPlayer() {
  /* Draw the image in the player structure */
  drawImage(player.sprite, player.x, player.y);
}
