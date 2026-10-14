#pragma once

#include <raylib.h>
#include <stdbool.h>
#include "grid.h"

typedef struct Window {
	Grid grid;
	int grid_w;
	int grid_h;
	int cell_w;
	int cell_h;

	int width;
	int height;
	int moves;
	bool has_won;
	char* title;
} Window;
