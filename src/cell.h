#pragma once

#include <stdbool.h>
#include <raylib.h>

#define CELL_WIDTH 125
#define CELL_HEIGHT 125

#define CELL_ON_COL CLITERAL(Color) {255, 255, 255, 255}
#define CELL_OFF_COL CLITERAL(Color) {0, 0, 0, 255} 

// gradient colors
#define CELL_COLOR_TOP CLITERAL (Color) {0, 0, 0, 255}
#define CELL_COLOR_BOT CLITERAL (Color) {255, 255, 255, 255}


typedef struct {
	Rectangle rect;
	float orig_y;
	int width;
	int height;
	bool is_on;
} Cell;
