#include "game.h"
#include "input.h"
#include "config.h"

void initGame(GameState *gameState) {
    gameState->paddle.x = (PLAYING_FIELD_WIDTH - gameState->paddle.width) / 2;
    gameState->paddle.y = PLAYING_FIELD_HEIGHT - 30.0f;
    gameState->paddle.width = 100.0f;
    gameState->paddle.height = 20.0f;
    gameState->paddle.velocity_x = 0.0f;

    gameState->ball.x = (PLAYING_FIELD_WIDTH - gameState->ball.width) / 2;
    gameState->ball.y = (PLAYING_FIELD_HEIGHT - gameState->ball.height) / 2;
    gameState->ball.width = 20.0f;
    gameState->ball.height = 20.0f;
    gameState->ball.velocity_x = 2.0f;
    gameState->ball.velocity_y = -5.0f;

    gameState->score = 0;  // Initialize score
}

void updateGame(GameState *gameState) {
    GameObject *paddle = &gameState->paddle;
    GameObject *ball = &gameState->ball;
    const float GRAVITY = 0.1f;

    paddle->x += paddle->velocity_x;
    if (paddle->x < 0) paddle->x = 0;
    if (paddle->x + paddle->width > PLAYING_FIELD_WIDTH) paddle->x = PLAYING_FIELD_WIDTH - paddle->width;

    ball->velocity_y += GRAVITY;
    ball->x += ball->velocity_x;
    ball->y += ball->velocity_y;

    if (ball->x < 0 || ball->x + ball->width > PLAYING_FIELD_WIDTH) {
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

    if (ball->y + ball->height > PLAYING_FIELD_HEIGHT) {
        ball->x = (PLAYING_FIELD_WIDTH - ball->width) / 2;
        ball->y = (PLAYING_FIELD_HEIGHT - ball->height) / 2;
        ball->velocity_x = 2.0f;
        ball->velocity_y = -5.0f;
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
