#include "game.h"
#include "input.h"

// Initialize the game objects (paddle and ball)
void initGame(GameObject *paddle, GameObject *ball) {
    // Initialize paddle properties
    paddle->x = 320 - 50; // Center the paddle horizontally
    paddle->y = 450; // Place the paddle near the bottom of the screen
    paddle->width = 100; // Paddle width
    paddle->height = 20; // Paddle height
    paddle->velocity_x = 0; // Initially, the paddle is stationary

    // Initialize ball properties
    ball->x = 320 - 10; // Center the ball horizontally
    ball->y = 240 - 10; // Place the ball in the middle of the screen vertically
    ball->width = 20; // Ball width
    ball->height = 20; // Ball height
    ball->velocity_x = 2; // Initial horizontal velocity
    ball->velocity_y = -5; // Initial vertical velocity
}

// Update the game state
void updateGame(GameObject *paddle, GameObject *ball) {
    const float GRAVITY = 0.1f; // Define the gravity constant

    // Update paddle position based on its velocity
    paddle->x += paddle->velocity_x;
    // Ensure the paddle stays within screen bounds
    if (paddle->x < 0) paddle->x = 0;
    if (paddle->x + paddle->width > 640) paddle->x = 640 - paddle->width;

    // Apply gravity to the ball's vertical velocity
    ball->velocity_y += GRAVITY;
    // Update ball position based on its velocity
    ball->x += ball->velocity_x;
    ball->y += ball->velocity_y;

    // Ball collision with screen borders
    if (ball->x < 0 || ball->x + ball->width > 640) {
        ball->velocity_x = -ball->velocity_x; // Reverse horizontal velocity
    }
    if (ball->y < 0) {
        ball->velocity_y = -ball->velocity_y; // Reverse vertical velocity
    }

    // Ball collision with paddle
    if (ball->y + ball->height >= paddle->y &&
        ball->x + ball->width >= paddle->x &&
        ball->x <= paddle->x + paddle->width) {
        ball->velocity_y = -ball->velocity_y; // Reverse vertical velocity

    }

    // Ball goes off screen (bottom)
    if (ball->y + ball->height > 480) {
        // Reset ball position and velocity
        ball->x = 320 - 10;
        ball->y = 240 - 10;
        ball->velocity_x = 2;
        ball->velocity_y = -5;
    }
}

// Handle SDL events
void handleEvents(SDL_Event *event, int *running, GameObject *paddle) {
    if (event->type == SDL_QUIT) {
        *running = 0; // Set running to 0 to exit the game loop
    } else if (event->type == SDL_KEYDOWN) {
        handleKeyDown(event->key.keysym.sym, paddle); // Handle key down event
    } else if (event->type == SDL_KEYUP) {
        handleKeyUp(event->key.keysym.sym, paddle); // Handle key up event
    }
}
