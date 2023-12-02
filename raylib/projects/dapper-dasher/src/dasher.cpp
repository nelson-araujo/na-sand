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
// const int GRAVITY{1}; // Free fall gravity (pixels/frame)/frame)
const int GRAVITY{1'000}; // Free fall gravity (pixels/second)/second). ' is ignored by the compiler but makes it easier to read.


// Prototypes
Player startGame();
void displayPlayer(Player*);
void updatePlayerCtr(Player*);
void closeGame(Player*);
void isFalling(Player*);

/** Game entry point.
 * 
*/
int main(){
    
    // Start game and create player
    Player player = startGame();

    // Game loop
    while( !WindowShouldClose() ){
        BeginDrawing();
        ClearBackground(WHITE);

        updatePlayerCtr(&player);
        displayPlayer(&player);

        EndDrawing();
    }

    closeGame(&player);
}

/** Start game window.
 * @return void
*/
Player startGame(){
    InitWindow(WIN_W, WIN_H, "Dapper Dasher!");
    
    // Create the player
    Player player;
    player.pos.x = 0;
    player.pos.y = WIN_H - player.HEIGHT;
    player.speed = player.BASE_SPEED;
    player.texture = LoadTexture("../assets/art/entities/scarfy/scarfy.png");

    // Set the games FPS
    SetTargetFPS(FPS);

    return player;
}

/** Close game window.
 * @return void
*/
void closeGame(Player* player){
    // Clear texture from memory
    UnloadTexture(player->texture);
    
    CloseWindow();
}

/** Display player.
 * @param   player object
 * @return  void
*/
void displayPlayer(Player* player){
    // DrawRectangle(player->pos.x, player->pos.y, player->WIDTH, player->HEIGHT, BLACK);
    DrawTextureRec(player->texture, player->textureRec, player->pos, WHITE);
}

/** Update player controls
 * @param   player  player object
*/
void updatePlayerCtr(Player* player){
    // Deta time, time since last frame.
    float dT = GetFrameTime();

    // Movement
    if( IsKeyDown(KEY_RIGHT) ){ player->pos.x += (player->speed * dT); };
    if( IsKeyDown(KEY_LEFT) ){ player->pos.x -= (player->speed * dT); };

    // Jump
    if( IsKeyPressed(KEY_SPACE) && !player->isFalling ){
        player->pos.y -= player->JUMP_HEIGHT;
        // player->speed += player->BASE_SPEED * 2; // Increase speed when jumping
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

        // Get delta time, time since last frame.
        float dT = GetFrameTime();

        // Update player position
        if(player->pos.y < (WIN_H - player->HEIGHT) ){
            player->pos.y += (player->fallVelocity * dT);
        } else {
            player->pos.y = (WIN_H - player->HEIGHT);
            player->speed = player->BASE_SPEED;
            player->fallVelocity = 0;
            player->isFalling = false;
        }
        
        // Update player fall velocity
        player->fallVelocity += (GRAVITY * dT);
}