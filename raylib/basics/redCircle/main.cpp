#include "raylib.h"

int main(){
	int width = 300;
	int height = 400;

	InitWindow(width, height, "Circle");

	while( !WindowShouldClose() ){
		BeginDrawing();
		ClearBackground(GRAY);

		int posX = width/2;
		int posY = height/2;
		int radius = width/4;
		
		DrawCircle(posX, posY, radius, BLUE);

		EndDrawing();
	}
}
