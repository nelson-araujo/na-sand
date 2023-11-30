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


// Prototypes
void startGame();

void displayPlayer(Player*);
void updatePlayerCtr(Player*);
void closeGame();

/** Game entry point.
 * 
*/
int main(){
    Player player;

    startGame();

    // Player position
    player.posX = 0;
    player.posY = WIN_H - player.HEIGHT;

    while( !WindowShouldClose() ){
        BeginDrawing();
        ClearBackground(WHITE);

        updatePlayerCtr(&player);
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
 * @param   player object
 * @return  void
*/
void displayPlayer(Player* player){
    DrawRectangle(player->posX, player->posY, player->WIDTH, player->HEIGHT, BLACK);
}

/** Update player controls
 * @param   playerPosX    Pointer to player x position on window.
 * @param   playerPosY    Pointer to player y position on window.
*/
void updatePlayerCtr(Player* player){
    // Movement
    if( IsKeyDown(KEY_RIGHT) ){ player->posX += player->speed; };
    if( IsKeyDown(KEY_LEFT) ){ player->posX -= player->speed; };

    // Jump
    if( IsKeyPressed(KEY_SPACE) ){
        player->posY -= player->JUMP_HEIGHT;
    };
    
    if( IsKeyReleased(KEY_SPACE) ){
        player->posY += player->JUMP_HEIGHT; 
    };
    
}