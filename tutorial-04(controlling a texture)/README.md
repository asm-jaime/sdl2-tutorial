# controlling a texture

This tutorial will demonstrate how to move a loaded image around a screen in SDL2.
(based on http://www.parallelrealities.co.uk/2011/09/basic-game-tutorial-4-controlling.html
and https://bitbucket.org/dandago/gigilabs/src/5bb5fa43afab/Sdl2SpriteSheets/Sdl2SpriteSheets/?at=master).

## build it
  * `make && ./build/tutorial04.out`

## control
  * pressing `Escape` or  closing the window for exit the program.
  * pressing arrow keys by `up/down/left/right`to control the ship (not the ones on the numeric pad).
  * the ship is constrained to the bounds of the window.

## structure

  * `res.img` this folder contain a image for displaying.

If you look in the `src` then here is 5 new files: `player.c`/`draw.c`/`structs.h`, full structure:
  * `main.h` standard main function.
  * `main.c` realisation.
  * `defs.h` all the includes required to compile the program.
  * `init.h` is where the most important function calls reside.
  * `init.c` realisation.
  * `input.h` is our event structure where we will store event information.
  * `input.c` realisation.
  * `graphics.h` load the image file, copy it to texture and show up.
  * `graphics.c` realisation.

## how it work

When closes our window, `cleanup()`, `SDL_DEstroyTexture()`, `FreeSurface()`, `SDL_DestroyRenderer()`,
`SDL_DestroyWindow()` and `SDL_Quit()` will free all resources, shuts down SDL2 and exits our program.
