#include "audio.h"

Mix_Chunk *loadSound(char *name) {
  /* Load the sound specified by the filename */
  Mix_Chunk *sfx = Mix_LoadWAV(name);

  if (sfx == NULL)  {
    printf("Failed to load sound %s\n", name);
  };
  return sfx;
}

void playSound(Mix_Chunk *sfx) {
  /* Play the sound on the first free channel and only play it once */
  Mix_PlayChannel(-1, sfx, 0);
}
