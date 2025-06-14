#include "raylib.h"

int main(){
	int width = 400;
	int height = 400;

	InitWindow(width,height,"My Window");

	// Keep window open until x or esc is pressed	
	while( !WindowShouldClose() ){
		BeginDrawing();
		ClearBackground(BLUE);
		EndDrawing();
	}
}
