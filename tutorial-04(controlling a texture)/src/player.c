#include "player.h"

extern int loadTexture(char *);
extern void drawTexture(SDL_Texture *, int, int);
extern SDL_Texture *getTexture(int);

void initPlayer() {
  player.texture = getTexture(PLAYER_SPRITE);
  SDL_QueryTexture(player.texture, NULL, NULL, &player.w, &player.h);
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
    if (player.y + player.h >= SCREEN_HEIGHT)    {
      player.y = SCREEN_HEIGHT - (player.h + 1);
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
    if (player.x + player.w >= SCREEN_WIDTH) {
      player.x = SCREEN_WIDTH - (player.w + 1);
    };
  };
}

void drawPlayer() {
  /* Draw the texture in the player structure */
  drawTexture(player.texture, player.x, player.y);
}
