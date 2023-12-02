#ifndef PLAYER
#define PLAYER

class Player{
    private:
        
    public:
        const int WIDTH{128}; // Player width
        const int HEIGHT{128}; // Player height
        // const int BASE_SPEED{2}; // Player normal speed
        const int BASE_SPEED{200}; // Player normal speed
        const int JUMP_HEIGHT{this->HEIGHT}; // Player jump height

        // Texture sprite sheet. Must be loaded after the Window is created.
        Texture2D texture{};

        // Texture frame
        Rectangle textureRec{
            .x{0},
            .y{0},
            .width{WIDTH},
            .height{HEIGHT}
        };
        
        // Position on screen
        Vector2 pos{
            .x{0},
            .y{0}
        };

        bool isFalling{false}; // Is the player falling?
        int fallVelocity{0}; // Speed the player is failling
        // int posX{0};
        // int posY{0};
        int speed{0}; // Speed of player, initialized in loop to BASE_SPEED
};
#endif