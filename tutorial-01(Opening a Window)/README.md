# Opening a Window

This tutorial will explain how to open a window in SDL2.

## build it
  * `make`

## structure

If you look in the src directory, you will see that there are 7 files:
  * `main.h` standard main function.
  * `main.c` realisation.
  * `defs.h` all the includes required to compile the program.
  * `init.h` is where the most important function calls reside.
  * `init.c` realisation.
  * `input.h` is our event structure where we will store event information.
  * `input.c` realisation.

## how it work

We start up SDL2 window with `Parallel Realities Tutorial 1` title and wait in `getInput()` to process messages.
`SDL_PollEvent()` wait key Escape as `SDLK_ESCAPE`.
When closes our window, `cleanup()` and `SDL_Quit()` shuts down SDL2 and exits our program.
