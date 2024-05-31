#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h> // Include SDL header
#include "game.h"     // Include game header for GameObject structure

// Function to initialize SDL, create window, and renderer
int initSDL(SDL_Window **window, SDL_Renderer **renderer);

// Function to render game objects (paddle and ball)
void render(SDL_Renderer *renderer, GameObject *paddle, GameObject *ball);

// Function to clean up SDL resources (window and renderer)
void cleanup(SDL_Window *window, SDL_Renderer *renderer);

#endif // GRAPHICS_H
