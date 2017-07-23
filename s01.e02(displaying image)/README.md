# displaying image

This tutorial explain how to display an image in SDL2.
(based on http://www.parallelrealities.co.uk/2011/09/basic-game-tutorial-2-displaying-image.html).

## build it
  * `make && ./build/tutorial02.out`

## control
  * pressing `Escape` or  closing the window for exit the program.

## structure

  * `res.img` this folder contain a image for displaying.

If you look in the `src` then here is 2 new files: `graphics.c` and `graphics.h`, full structure:
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

We start up SDL2 window with `Parallel Realities Tutorial 2` and show `ship.bmp` on main screen.
Before then `drawImage()` will show `ship.bmp` the IMG_Load function
(this is from SDL_image and allows us to load JPEGs and PNGs) in `loadImage()` should loading `.bmp` file to memory.
`updateScreen()` will be draw `.bmp` in main while.
When closes our window, `cleanup()`, `SDL_DEstroyTexture()`, `FreeSurface()`, `SDL_DestroyRenderer()`,
`SDL_DestroyWindow()` and `SDL_Quit()` will free all resources, shuts down SDL2 and exits our program.
