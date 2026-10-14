#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include "game.h"
#include "window.h"

void foo(void) { return; }

int main(int argc, char** argv){

	srand((int) &foo);

	Window win = {
		.grid_w = 5,
		.grid_h = 5,
		.cell_h = CELL_HEIGHT,
		.cell_w = CELL_WIDTH,
		.width = 720, 
		.height = 900, 
		.title = "Lights Out",
		.has_won = false,
	};

	InitWindow(win.width, win.height, win.title);
	SetTargetFPS(60);
	game(&win);

    return 0;
}
