#ifndef NEBULA_H // If NEBULA.H is not defined
#define NEBULA_H // Define NEBULA.H with the below

#include "raylib.h"

// Using struct as all variables will be public
struct Nebula{
    // Properties
    const int WIDTH{100};
    const int HEIGHT{100};
    const int SPEED{100};
    const float UPDATE_TIME{1.0/12.0}; // Ammount of time that should pass between each animation frame. 1/12 will update the frame 12 times per second.
    const int SPRITE_SHEET_HOR_FRAMES{8}; // Number of horizontal frames in the sprite sheet
    const int SPRITE_SHEET_VER_FRAMES{8}; // Number of row frames in the sprite sheet

    // Texture sprite sheet. Must be loaded after the Window is created.
    Texture2D texture{};

    // Texture frame
    Rectangle textureFrame{
        .x{0.0},
        .y{0.0},
        .width{float(WIDTH)},
        .height{float(HEIGHT)}
    };
    
    // Position on screen
    Vector2 pos{
        .x{0.0},
        .y{0.0}
    };
    
    // float runningTime{0}; // deprecated
};

#endif // End define block