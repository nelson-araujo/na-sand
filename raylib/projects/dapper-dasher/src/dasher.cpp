/**
 * Dapper Dasher is a runner game where the character dashes out of the way of flying hazards!
 * 
*/

#include "include/raylib.h"
#include "include/player.h"

// Globals
const int WIN_W{512}; // Window Width
const int WIN_H{380}; // Window Height
const int FPS{60}; // Game FPS
const int PLAYER_W{50}; // Player width
const int PLAYER_H{80}; // Player height
const int PLAYER_BASE_SPEED{2}; // Player movement speed


// Prototypes
void startGame();
// void displayPlayer(int*, int*);
void displayPlayer(Player*);
void updatePlayerCtr(int*, int*);
void closeGame();

/** Game entry point.
 * 
*/
int main(){
    Player player;


    startGame();

    // Player position
    int playerPosX{0};
    int playerPosY{WIN_H - PLAYER_H};

    while( !WindowShouldClose() ){
        BeginDrawing();
        ClearBackground(WHITE);

        // updatePlayerCtr(&playerPosX, &playerPosY);
        displayPlayer(&player);
        


        EndDrawing();
    }

    closeGame();
}

/** Start game window.
 * @return void
*/
void startGame(){
    InitWindow(WIN_W, WIN_H, "Dapper Dasher!");

    SetTargetFPS(FPS);
}

/** Close game window.
 * @return void
*/
void closeGame(){
    CloseWindow();
}

/** Display player.
 * @param   playerPosX    Pointer to player x position on window.
 * @param   playerPosY    Pointer to player y position on window.
*/
void displayPlayer(Player* player){
    DrawRectangle(player->posX, player->posY, player->WIDTH, player->HEIGHT, BLACK);
}

/** Update player controls
 * @param   playerPosX    Pointer to player x position on window.
 * @param   playerPosY    Pointer to player y position on window.
*/
void updatePlayerCtr(int* playerPosX, int* playerPosY){
    // Movement
    if(IsKeyDown(KEY_RIGHT)){ *playerPosX += PLAYER_BASE_SPEED; };
    if(IsKeyDown(KEY_LEFT)){ *playerPosX -= PLAYER_BASE_SPEED; };

    // Jump
    if(IsKeyDown(KEY_SPACE)){ *playerPosX += PLAYER_BASE_SPEED; };
    

}