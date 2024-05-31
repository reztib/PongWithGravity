#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>  // Include SDL header for SDL functionalities
#include <SDL2/SDL_ttf.h>  // Include SDL_ttf header for font rendering
#include "game.h"  // Include the game header for accessing game state

// Function to initialize SDL and create window/renderer
int initSDL(SDL_Window **window, SDL_Renderer **renderer);

// Function to render game objects and score
void render(SDL_Renderer *renderer, GameState *gameState, TTF_Font *font);

// Function to clean up SDL resources
void cleanup(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font);

// Function to render the score on the screen
void renderScore(SDL_Renderer *renderer, TTF_Font *font, int score);

#endif // GRAPHICS_H
