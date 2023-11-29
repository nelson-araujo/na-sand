#include "stdio.h"
#include "raylib.h"	// raylib library
#include <stdlib.h> // srand and rand
#include <time.h>	// time

const Color BG_COLOR = GetColor(0x4d545eff);	// Background color
const int FPS = 60;								// Windows refresh rate
const int MOVE_SPEED = 3;						// Speed of the exe
const int WIN_W = 1024;							// Window width
const int WIN_H = 576;							// Window height

int main(){
	//  Initialize random seed
	srand(time(NULL));

	// Collision detected
	bool collWithAxe = false;

	// Axe size
	int axeW = 40;
	int axeH = 40;
	// Axe position
	int axePosX =  WIN_W/2 - axeW;
	int axePosY =  WIN_H/2 - axeH;

	// Enemy
	int enemyW{50};
	int enemyH{50};
	// Enemy location
	int enemyPosX{rand() % (WIN_W-enemyW)};
	int enemyPosY{rand() % (WIN_H-enemyH)};
	
	
	// Create window
	InitWindow(WIN_W, WIN_H, "Axe Game");

	// Set framerate
	SetTargetFPS(FPS);

	while( !WindowShouldClose() ){
		BeginDrawing();
		ClearBackground(BG_COLOR);
		DrawText("Axe Game", 0, 0, 20, GRAY);

		// Display Axe
		DrawRectangle(axePosX, axePosY, axeW, axeH, BLACK);

		// Display Enemy
		DrawRectangle(enemyPosX, enemyPosY, enemyW, enemyH, BLUE);
		
		// Collision detection
		// Axe collision box
		int axeCollLeftX = axePosX;
		int axeCollRightX = axePosX + axeW;
		int axeCollTopY = axePosY;
		int axeCollBottomY = axePosY + axeH;

		// Enemy collision box
		int enemyCollLeftX{enemyPosX};
		int enemyCollRightX{enemyPosX + enemyW};
		int enemyCollTopY{enemyPosY};
		int enemyCollBottomY{enemyPosY + enemyH};

		// Collision detection
		if(	axeCollLeftX <= enemyCollRightX &&
			axeCollRightX >=enemyCollLeftX &&
			axeCollTopY <= enemyCollBottomY &&
			axeCollBottomY >= enemyCollTopY)
			{
			collWithAxe=true;
		};

		// Game logic
		if(collWithAxe){
			// End game
			DrawRectangle((WIN_W/2)-265, (WIN_H/2)-85, (WIN_W/2)+10 , 85, ORANGE);
			DrawText("GAME OVER!", (WIN_W/2)-255, (WIN_H/2)-75, 80, RED);

		} else {
			// Controls
			if(IsKeyDown(KEY_UP) && axePosY>=0){
				axePosY -= MOVE_SPEED;
			}
			if(IsKeyDown(KEY_DOWN) && axePosY<=WIN_H-axeH){
				axePosY += MOVE_SPEED;
			}
			if(IsKeyDown(KEY_LEFT) && axePosX>=0){
				axePosX -= MOVE_SPEED;
			}
			if(IsKeyDown(KEY_RIGHT) && axePosX<=WIN_W-axeW){
				axePosX += MOVE_SPEED;
			}
		}

		EndDrawing();
	}

}