#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


#define MAX_ENTITIES 20
#define MAX_RELOAD_TIME 20

#define PLAYER_SPEED 3
#define BULLET_SPEED 10

enum {
  PLAYER_TEXTURE,
  BULLET_TEXTURE,
  MAX_TEXTURES
};

enum {
  BULLET_SOUND,
  MAX_SOUNDS
};
