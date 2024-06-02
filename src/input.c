#include "input.h"

void handleKeyDown(SDL_Keycode key, GameObject *paddle) {
    switch (key) {
        // Move paddle left when 'A' or Left Arrow is pressed
        case SDLK_a:
        case SDLK_LEFT:
            paddle->velocity_x = -5.0f;
            break;
            // Move paddle right when 'D' or Right Arrow is pressed
        case SDLK_d:
        case SDLK_RIGHT:
            paddle->velocity_x = 5.0f;
            break;
            // Default case for completeness (optional)
        default:
            break;
    }
}

void handleKeyUp(SDL_Keycode key, GameObject *paddle) {
    switch (key) {
        // Stop moving paddle if 'A' or Left Arrow is released
        case SDLK_a:
        case SDLK_LEFT:
            // Stop moving paddle if 'D' or Right Arrow is released
        case SDLK_d:
        case SDLK_RIGHT:
            paddle->velocity_x = 0.0f;
            break;
            // Default case for completeness (optional)
        default:
            break;
    }
}