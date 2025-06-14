#include "raylib.h"

using namespace std;

int main(){
    int winW = 300;
    int winH = 400;

    // Create window
    InitWindow(winW, winH, "Window");

    // Define circle
    int circlePositionX = winW/2;
    int circlePositionY = winH/2;
    int circleRadius = winW/8;

    // Set FPS to refresh
    SetTargetFPS(60);

    while( !WindowShouldClose() ){
        BeginDrawing();
        ClearBackground(GRAY);

        DrawRectangle(50,50,200, 100, PURPLE);

        // Draw circle in center of window
        DrawCircle(circlePositionX,circlePositionY,circleRadius,PURPLE);

        // Update circle position down if not trailing off drawing
        if(IsKeyDown(KEY_DOWN) && circlePositionY<=(winH-circleRadius) ){
            circlePositionY++;
        }

        // Update circle position up if not trailing off drawing
        if(IsKeyDown(KEY_UP) && circlePositionY>=circleRadius){
            circlePositionY--;
        }
        
        // Update circle position left if not trailing off drawing
        if(IsKeyDown(KEY_LEFT) && circlePositionX>=circleRadius){
            circlePositionX--;
        }
        
        // Update circle position right if not trailing off drawing
        if(IsKeyDown(KEY_RIGHT) && circlePositionX<=(winW-circleRadius) ){
            circlePositionX++;
        }

        EndDrawing();    
    }
}