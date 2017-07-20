# displaying image

This tutorial explain how to play a sound clip in SDL2.
(based on http://www.parallelrealities.co.uk/2011/09/basic-game-tutorial-3-images-and-sound.html).

## build it
  * `make && ./build/tutorial03.out`

## control
  * By pressing `Escape` or closing the window for exit the program.
  * By pressing `Space`, you can play a sound clip.

## structure

  * `res.img` the folder contain a image for displaying.
  * `res.sound` the folder contain the `sea.wav` file for play.

If you look in the `src` then here is 2 new files: `audio.c` and `audio.h`, full structure:
  * `main.h` standard main function.
  * `main.c` realisation.
  * `defs.h` all the includes required to compile the program.
  * `init.h` is where the most important function calls reside.
  * `init.c` realisation.
  * `input.h` is our event structure where we will store event information.
  * `input.c` realisation.
  * `graphics.h` load the image file, copy it to texture and show up.
  * `graphics.c` realisation.
  * `audio.h` load the sound file and play it.
  * `audio.c` realisation.

## how it work

`SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)`  initialise SDL's audio system in addition to its video system.
Mix_Chunk, which we will use to store the sound that we wish to play.
playSound will play the specified audio file by calling `Mix_PlayChannel(-1, sfx, 0)`.
When closes our window, `cleanup()` call `Mix_FreeChunk()` and `Mix_CloseAudio()` to free sound resources.
