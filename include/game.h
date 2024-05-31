#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

typedef struct {
    float x, y;
    float width, height;
    float velocity_x, velocity_y;
} GameObject;

typedef struct {
    GameObject paddle, ball;
    int score;
} GameState;

void initGame(GameState *gameState);
void updateGame(GameState *gameState);
void handleEvents(SDL_Event *event, int *running, GameState *gameState);

#endif // GAME_H
