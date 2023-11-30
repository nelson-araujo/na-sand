#ifndef PLAYER
#define PLAYER

class Player{
    private:
        ;
    public:
        const int WIDTH{50}; // Player width
        const int HEIGHT{80}; // Player height
        int posX{0};
        int posY{0};
        int speed{1};
};
#endif