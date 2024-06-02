#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Structure for game objects like paddles and ball
typedef struct {
    float x, y;
    float width, height;
    float velocity_x, velocity_y;
} GameObject;

// Structure for game state including paddles, ball, and scores
typedef struct {
    GameObject paddle1;     // Player 1 paddle
    GameObject paddle2;     // Player 2 paddle
    GameObject ball;        // Ball
    int score1;             // Score for player 1
    int score2;             // Score for player 2
} GameState;

// Enumeration for game states
typedef enum {
    STATE_START_SCREEN,    // Start screen state
    STATE_PLAYING,         // Playing state
} GameStateEnum;

// Function prototypes
void initGame(GameState *gameState);
void updateGame(GameState *gameState);
void handleEvents(SDL_Event *event, int *running, GameState *gameState);

#endif // GAME_H
