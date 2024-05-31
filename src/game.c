#include "game.h"
#include "input.h"

void initGame(GameState *gameState) {
    gameState->paddle.x = 320 - 50;
    gameState->paddle.y = 450;
    gameState->paddle.width = 100;
    gameState->paddle.height = 20;
    gameState->paddle.velocity_x = 0;

    gameState->ball.x = 320 - 10;
    gameState->ball.y = 240 - 10;
    gameState->ball.width = 20;
    gameState->ball.height = 20;
    gameState->ball.velocity_x = 2;
    gameState->ball.velocity_y = -5;

    gameState->score = 0;  // Initialize score
}

void updateGame(GameState *gameState) {
    GameObject *paddle = &gameState->paddle;
    GameObject *ball = &gameState->ball;
    const float GRAVITY = 0.1f;

    paddle->x += paddle->velocity_x;
    if (paddle->x < 0) paddle->x = 0;
    if (paddle->x + paddle->width > 640) paddle->x = 640 - paddle->width;

    ball->velocity_y += GRAVITY;
    ball->x += ball->velocity_x;
    ball->y += ball->velocity_y;

    if (ball->x < 0 || ball->x + ball->width > 640) {
        ball->velocity_x = -ball->velocity_x;
    }
    if (ball->y < 0) {
        ball->velocity_y = -ball->velocity_y;
    }

    if (ball->y + ball->height >= paddle->y &&
        ball->x + ball->width >= paddle->x &&
        ball->x <= paddle->x + paddle->width) {
        ball->velocity_y = -ball->velocity_y;
        gameState->score++;  // Increment score when the ball hits the paddle
    }

    if (ball->y + ball->height > 480) {
        ball->x = 320 - 10;
        ball->y = 240 - 10;
        ball->velocity_x = 2;
        ball->velocity_y = -5;
        gameState->score--;  // Decrement score if the ball goes out of bounds
    }
}

void handleEvents(SDL_Event *event, int *running, GameState *gameState) {
    if (event->type == SDL_QUIT) {
        *running = 0;
    } else if (event->type == SDL_KEYDOWN) {
        handleKeyDown(event->key.keysym.sym, &gameState->paddle);
    } else if (event->type == SDL_KEYUP) {
        handleKeyUp(event->key.keysym.sym, &gameState->paddle);
    }
}
