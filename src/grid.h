#pragma once

#include <raylib.h>
#include <stdbool.h>
#include "cell.h"

#define GRID_PADDING 2
#define MAX_WIDTH    8
#define MAX_HEIGHT   8
#define MIN_WIDTH    3
#define MIN_HEIGHT	 3

typedef struct {
	Cell* cells; 
} Grid;

typedef struct Window Window;

void init_grid(Window* win);
void render_grid(const Window* win);
void free_grid(Window* win);
