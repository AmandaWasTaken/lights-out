#pragma once

#include <raylib.h>
#include <stdbool.h>
#include "cell.h"

#define GRID_WIDTH 5
#define GRID_HEIGHT 5
#define GRID_PADDING 2

typedef struct {
	Cell* cells; 
} Grid;

typedef struct Window Window;

void init_grid(Window* win);
void render_grid(const Window* win);
void free_grid(Window* win);
