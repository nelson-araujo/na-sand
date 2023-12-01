/**
 * Dapper Dasher is a runner game where the character dashes out of the way of flying hazards!
 * 
*/

#include "libs/raylib.h"
#include "player.h"

// Globals
const int WIN_W{512}; // Window Width
const int WIN_H{380}; // Window Height
const int FPS{30}; // Game FPS
const int GRAVITY{1}; // Free fall gravity (pixels/frame)/frame)


// Prototypes
void startGame();
void displayPlayer(Player*);
void updatePlayerCtr(Player*);
void closeGame();
void isFalling(Player*);

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
 * @param   player  player object
*/
void updatePlayerCtr(Player* player){
    // Movement
    if( IsKeyDown(KEY_RIGHT) ){ player->posX += player->speed; };
    if( IsKeyDown(KEY_LEFT) ){ player->posX -= player->speed; };

    // Jump
    if( IsKeyPressed(KEY_SPACE) ){
        player->posY -= player->JUMP_HEIGHT;
        player->isFalling = true;
    };
    
    // Check if player is higher than floor height and apply gravity
    if(player->isFalling){ isFalling(player); }
    
}

/** Player is falling, update position.
 * @param   player  player object
*/
void isFalling(Player* player){
        const int TERMINAL_VELOCITY{53};

        // Update player position
        if(player->posY < (WIN_H - player->HEIGHT) ){
            player->posY += player->fallVelocity;
        } else {
            player->posY = (WIN_H - player->HEIGHT);
            player->fallVelocity = 0;
            player->isFalling = false;
        }
        
        // Update player fall velocity
        player->fallVelocity += GRAVITY;
}