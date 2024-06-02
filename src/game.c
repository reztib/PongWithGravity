#include "game.h"
#include "input.h"
#include "config.h"

void initGame(GameState *gameState) {
    // Initialize paddle1 at the bottom
    gameState->paddle1.x = (PLAYING_FIELD_WIDTH - 100.0f) / 2;
    gameState->paddle1.y = PLAYING_FIELD_HEIGHT - 30.0f;
    gameState->paddle1.width = 100.0f;
    gameState->paddle1.height = 20.0f;
    gameState->paddle1.velocity_x = 0.0f;
    gameState->paddle1.velocity_y = 0.0f;

    // Initialize paddle2 at the top
    gameState->paddle2.x = (PLAYING_FIELD_WIDTH - 100.0f) / 2;
    gameState->paddle2.y = 10.0f;
    gameState->paddle2.width = 100.0f;
    gameState->paddle2.height = 20.0f;
    gameState->paddle2.velocity_x = 0.0f;
    gameState->paddle2.velocity_y = 0.0f;

    // Initialize the ball at the center
    gameState->ball.x = (PLAYING_FIELD_WIDTH - gameState->ball.width) / 2;
    gameState->ball.y = (PLAYING_FIELD_HEIGHT - gameState->ball.height) / 2;
    gameState->ball.width = 20.0f;
    gameState->ball.height = 20.0f;
    gameState->ball.velocity_x = 2.0f;
    gameState->ball.velocity_y = -5.0f;

    // Initialize scores for both players
    gameState->score1 = 0;
    gameState->score2 = 0;
}

void updateGame(GameState *gameState) {
    // Get references to the game objects
    GameObject *paddle1 = &gameState->paddle1;
    GameObject *paddle2 = &gameState->paddle2;
    GameObject *ball = &gameState->ball;
    const float GRAVITY = 0.1f;

    // Update paddle1 position
    paddle1->x += paddle1->velocity_x;
    paddle1->y += paddle1->velocity_y;

    // Ensure paddle1 stays within the playing field
    if (paddle1->x < 0) paddle1->x = 0;
    if (paddle1->x + paddle1->width > PLAYING_FIELD_WIDTH) paddle1->x = PLAYING_FIELD_WIDTH - paddle1->width;
    if (paddle1->y < 0) paddle1->y = 0;
    if (paddle1->y + paddle1->height > PLAYING_FIELD_HEIGHT) paddle1->y = PLAYING_FIELD_HEIGHT - paddle1->height;

    // Update ball position and velocity
    ball->velocity_y += GRAVITY;
    ball->x += ball->velocity_x;
    ball->y += ball->velocity_y;

    // Handle ball collisions with walls
    if (ball->x < 0 || ball->x + ball->width > PLAYING_FIELD_WIDTH) {
        ball->velocity_x = -ball->velocity_x;
    }

    // Handle ball collision with the top wall (Player 1 scores)
    if (ball->y < 0) {
        ball->velocity_y = -ball->velocity_y;
        gameState->score1++;
    }

    // Handle ball collision with the bottom wall (Player 2 scores)
    if (ball->y + ball->height > PLAYING_FIELD_HEIGHT) {
        ball->velocity_y = -ball->velocity_y;
        gameState->score2++;
    }

    // Handle ball collision with paddle1
    if (ball->y + ball->height >= paddle1->y &&
        ball->x + ball->width >= paddle1->x &&
        ball->x <= paddle1->x + paddle1->width) {
        ball->velocity_y = -ball->velocity_y;
        ball->velocity_x += paddle1->velocity_x * 0.5f;
        ball->velocity_y += paddle1->velocity_y * 0.5f;
        ball->y = paddle1->y - ball->height;
    }

    // Handle ball collision with paddle2
    if (ball->y <= paddle2->y + paddle2->height &&
        ball->x + ball->width >= paddle2->x &&
        ball->x <= paddle2->x + paddle2->width) {
        ball->velocity_y = -ball->velocity_y;
        ball->velocity_x += paddle2->velocity_x * 0.5f;
        ball->velocity_y += paddle2->velocity_y * 0.5f;
        ball->y = paddle2->y + paddle2->height;
    }
}

void handleEvents(SDL_Event *event, int *running, GameState *gameState) {
    if (event->type == SDL_QUIT) {
        *running = 0;
    } else if (event->type == SDL_KEYDOWN) {
        handleKeyPressed(event->key.keysym.sym, &gameState->paddle1);
    } else if (event->type == SDL_KEYUP) {
        handleKeyReleased(event->key.keysym.sym, &gameState->paddle1);
    }
}
