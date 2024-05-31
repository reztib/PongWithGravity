#include "input.h"

// Handle key down events
void handleKeyDown(SDL_Keycode key, GameObject *paddle) {
    switch (key) {
        // Move paddle left
        case SDLK_a:
        case SDLK_LEFT:
            paddle->velocity_x = -5;
            break;
            // Move paddle right
        case SDLK_d:
        case SDLK_RIGHT:
            paddle->velocity_x = 5;
            break;
            // Default case for completeness (optional)
        default:
            break;
    }
}

// Handle key up events
void handleKeyUp(SDL_Keycode key, GameObject *paddle) {
    switch (key) {
        // Stop moving paddle if the left key is released
        case SDLK_a:
        case SDLK_LEFT:
            // Stop moving paddle if the right key is released
        case SDLK_d:
        case SDLK_RIGHT:
            paddle->velocity_x = 0;
            break;
            // Default case for completeness (optional)
        default:
            break;
    }
}
