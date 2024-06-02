#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"

int initSDL(SDL_Window **window, SDL_Renderer **renderer);
void render(SDL_Renderer *renderer, GameState *gameState, TTF_Font *font);
void renderStartScreen(SDL_Renderer *renderer, TTF_Font *font); // Declare renderStartScreen function
void renderScore(SDL_Renderer *renderer, TTF_Font *font, const char *label, int score, int x, int y);
void cleanup(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font);

#endif // GRAPHICS_H
