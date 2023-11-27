#include "raylib.h"
#include <unistd.h>

int main(){
	int width= 800;
	int height= 600;
	
	float root_beer = 1.99;
	double cheese_burger {5.99}; 
	bool shouldHaveLunch {};

	bool equal{ 4==9 }; // false
	bool notEual{ 4!=9 }; //true
	bool less{ 4<0 }; //true
	bool greater{ 4>9 }; // false
	bool lessEqual{ 4<=9 }; // true
	bool greaterEqual{ 4>=9 }; // false

	InitWindow(width,height,"My Window");

	sleep(3);
}
