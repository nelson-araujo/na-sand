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
    // Start game and display player
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
    // Delta Time, time since last frame.
    float dT = GetFrameTime();


    // float runningTime{player->UPDATE_TIME};
    
    // Animate player
    if(player->isMoving){
        if(player->runningTime >= player->UPDATE_TIME){
            int playerFrame = 1;
            
            // Reset running time
            player->runningTime = 0;

            if(playerFrame <= 6){
                player->textureFrame.x += (playerFrame * player->WIDTH);
                playerFrame++;
            } else {
                playerFrame = 0;
            }
        }
    } else {
        player->textureFrame.x = 5 * player->WIDTH;
    }

    DrawTextureRec(player->texture, player->textureFrame, player->pos, WHITE);

    // Increase running time
    player->runningTime += dT;
}

/** Update player controls
 * @param   player  player object
*/
void updatePlayerCtr(Player* player){
    // Deta time, time since last frame.
    float dT = GetFrameTime();

    // Movement
    if( IsKeyDown(KEY_RIGHT) ){
        player->isMoving = true;
        player->pos.x += (player->speed * dT);
    }

    if( IsKeyDown(KEY_LEFT) ){
        player->isMoving = true;
        player->pos.x -= (player->speed * dT);
    }

    if( IsKeyUp(KEY_RIGHT) && IsKeyUp(KEY_LEFT) ){
        player->isMoving = false;
    }

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