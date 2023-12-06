/**
 * Dapper Dasher is a runner game where the character dashes out of the way of flying hazards!
 * 
*/

#include "includes/raylib.h"
#include "includes/player.h"
#include "includes/nebula.h"

// Globals
const int WIN_W{512}; // Window Width
const int WIN_H{380}; // Window Height
const int FPS{30}; // Game FPS
const int GRAVITY{1'000}; // Free fall gravity (pixels/second)/second). ' is ignored by the compiler but makes it easier to read.

// Prototypes
void initializeWindow();
Player createPlayer();
Nebula createNebula();
void displayPlayer(Player*);
void playerCtr(Player*);
void isPlayerFalling(Player*);
void displayNebula(Nebula*);
void closeGame(Player*, Nebula*);

/** Game entry point.
 * 
*/
int main(){
    // Start game and display player
    initializeWindow();

    Player player = createPlayer();
    Nebula nebula = createNebula();

    // Game loop
    while( !WindowShouldClose() ){
        BeginDrawing();
        ClearBackground(WHITE);

        playerCtr(&player);
        displayPlayer(&player);
        displayNebula(&nebula);

        EndDrawing();
    }

    closeGame(&player, &nebula);
}

/** Initialize the game window.
 * @return void
*/
void initializeWindow(){
    InitWindow(WIN_W, WIN_H, "Dapper Dasher!");
    
    // Set the games FPS
    SetTargetFPS(FPS);
}

/** Create player object.
 * @return  Player object
*/
Player createPlayer(){
    Player player;
    player.pos.x = 0;
    player.pos.y = WIN_H - player.HEIGHT;
    player.speed = player.BASE_SPEED;
    player.texture = LoadTexture("../assets/art/entities/scarfy/scarfy.png");

    return player;
}

/** Create a nebula
 * @return  Nebula object
*/
Nebula createNebula(){
    Nebula nebula;
    nebula.texture = LoadTexture("../assets/art/entities/nebula/nebula_spritesheet.png");
    nebula.pos.x = float(WIN_W - nebula.WIDTH);
    nebula.pos.y = float(WIN_H - nebula.HEIGHT);

    return nebula;
}

/** Display player.
 * @param   player object
 * @return  void
*/
void displayPlayer(Player* player){
    // Delta Time, time since last frame.
    float dT = GetFrameTime();
    
    // Animate player
    if(player->isMoving){
        // Set animation frame if player is running or jumping
        if(!player->isInAir){
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
            player->textureFrame.x = 0 * player->WIDTH;
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
void playerCtr(Player* player){
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
    if( IsKeyPressed(KEY_SPACE) && !player->isInAir ){
        player->pos.y -= player->JUMP_HEIGHT;
        // player->speed += player->BASE_SPEED * 2; // Increase speed when jumping
        player->isInAir = true;
    };
    
    // Check if player is higher than floor height and apply gravity
    if(player->isInAir){ isPlayerFalling(player); }
    
}

/** Player is falling, update position.
 * @param   player  player object
*/
void isPlayerFalling(Player* player){
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
            player->isInAir = false;
        }
        
        // Update player fall velocity
        player->fallVelocity += (GRAVITY * dT);
}

/** Display nebula
 * @param   Nebula object to display
*/
void displayNebula(Nebula* nebula){
    float dT = GetFrameTime();

    // Animate nebula
    if(nebula->runningTime >= nebula->UPDATE_TIME){
        int frame = 1;
        
        // Reset running time
        nebula->runningTime = 0;

        if(frame <= (nebula->texture.width / nebula->SPRITE_SHEET_HOR_FRAMES)){
            nebula->textureFrame.x += (frame * nebula->WIDTH);
            frame++;
        } else {
            frame = 0;
        }
    }

    // increate run time
    nebula->runningTime += dT;

    // Update position
    if(nebula->pos.x > (0 - nebula->WIDTH)){
        nebula->pos.x -= nebula->SPEED * dT;
    } else {
        nebula->pos.x = WIN_W;
    }

    // display nebula
    DrawTextureRec(nebula->texture, nebula->textureFrame, nebula->pos, WHITE);
}

/** Close game window.
 * @return void
*/
void closeGame(Player* player, Nebula* nebula){
    // Clear texture from memory
    UnloadTexture(player->texture);
    UnloadTexture(nebula->texture);
    
    CloseWindow();
}
