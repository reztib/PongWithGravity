#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

typedef struct {
    float x, y;
    float width, height;
    float velocity_x, velocity_y;
} GameObject;

typedef struct {
    GameObject paddle, ball;
    int score;
} GameState;

typedef enum {
    STATE_START_SCREEN,
    STATE_PLAYING,
    STATE_GAME_OVER
} GameStateEnum;

void initGame(GameState *gameState);
void updateGame(GameState *gameState);
void handleEvents(SDL_Event *event, int *running, GameState *gameState);
void renderStartScreen(SDL_Renderer *renderer, TTF_Font *font);
void render(SDL_Renderer *renderer, GameState *gameState, TTF_Font *font);
void cleanup(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font);

#endif // GAME_H
