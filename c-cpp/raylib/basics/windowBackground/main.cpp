#include "raylib.h"

int main(){
	int width = 350;
	int height = 350;

	// create window
	InitWindow(width,height, "Windows1");

	for(int i=0 ; i<1000 ; i++){
		BeginDrawing();
		ClearBackground(RED);
		EndDrawing();
	}
}
