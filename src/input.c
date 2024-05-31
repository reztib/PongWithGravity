#include "input.h"

// Handle key down events
void handleKeyDown(SDL_Keycode key, GameObject *paddle) {
    // Switch statement to handle different key codes
    switch (key) {
        // Move paddle left when 'A' or Left Arrow is pressed
        case SDLK_a:
        case SDLK_LEFT:
            paddle->velocity_x = -5;
            break;
            // Move paddle right when 'D' or Right Arrow is pressed
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
    // Switch statement to handle different key codes
    switch (key) {
        // Stop moving paddle if 'A' or Left Arrow is released
        case SDLK_a:
        case SDLK_LEFT:
            // Stop moving paddle if 'D' or Right Arrow is released
        case SDLK_d:
        case SDLK_RIGHT:
            paddle->velocity_x = 0;
            break;
            // Default case for completeness (optional)
        default:
            break;
    }
}
