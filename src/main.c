#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include "game.h"
#include "window.h"

void foo(void) { return; }

void usage(const char* name){
	
	fprintf(stderr, "Usage: <%s> width height\n", name);
	exit(1);
}

int main(int argc, char** argv){

	srand((int) &foo);

	if(argc < 3){
		usage(argv[0]);
	}

	char* end;
	int w = (int) strtol(argv[1], &end, 10);
	if(*end != '\0'){
		fprintf(stderr, "Conversion failed\n");
	}

	end = NULL;
	int h = (int) strtol(argv[2], &end, 10);
	if(*end != '\0'){
		fprintf(stderr, "Conversion failed\n");
	}

	// TODO
	if(w != h){
		fprintf(stderr, "Only NxN grid allowed for now\n");
		exit(1);
	}

	if(w > MAX_WIDTH || h > MAX_HEIGHT){
		fprintf(stderr, "Maximum grid size %ix%i\n", 
				MAX_WIDTH, MAX_HEIGHT);
		exit(1);
	}

	if(w < MIN_WIDTH || h < MIN_HEIGHT){
		fprintf(stderr, "Minimum grid size %ix%i\n",
				MIN_WIDTH, MIN_HEIGHT);
		exit(1);
	}

	Window win = {
		.grid_w = w,
		.grid_h = h,
		.cell_h = CELL_HEIGHT,
		.cell_w = CELL_WIDTH,
		.width = 720, 
		.height = 900, 
		.title = "Lights Out",
		.has_won = false,
	};

	if(win.grid_w > 5 || win.grid_h > 5){
		win.width += 300;
		win.height += 300;
	}

	InitWindow(win.width, win.height, win.title);
	SetTargetFPS(60);
	game(&win);

    return 0;
}
