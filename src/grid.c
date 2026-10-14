#include <raylib.h>
#include <stdio.h>
#include <cutils.h>
#include <stdbool.h>
#include "grid.h"
#include "window.h"
#include "colors.h"

void toggle_cell(Grid* grid, int row, int col){
	
	int idx = row * GRID_WIDTH + col;
	grid->cells[idx].is_on ^= true;

	if (row > 0) {
        idx = (row - 1) * GRID_WIDTH + col;
        grid->cells[idx].is_on ^= true;
    }

    if (row < GRID_HEIGHT - 1) {
        idx = (row + 1) * GRID_WIDTH + col;
        grid->cells[idx].is_on ^= true;
    }

    if (col > 0) {
        idx = row * GRID_WIDTH + (col - 1);
        grid->cells[idx].is_on ^= true;
    }

    if (col < GRID_WIDTH - 1) {
        idx = row * GRID_WIDTH + (col + 1);
        grid->cells[idx].is_on ^= true; 
    }
}

static Cell* get_cell(Grid* grid, int x, int y){
	return &grid->cells[x * GRID_WIDTH + y];
}

void init_grid(Window* win){

	win->moves = 0;
	win->grid.cells = malloc(sizeof(Cell) * GRID_WIDTH * GRID_HEIGHT);

	if(win->grid.cells == NULL){
		fprintf(stderr, "%s(): grid.cells is null\n");
		exit(1);
	}

	bool debug = false;

	int grid_width  = GRID_WIDTH * CELL_WIDTH + (GRID_WIDTH - 1) * GRID_PADDING;
	int grid_height = GRID_HEIGHT * CELL_HEIGHT + (GRID_HEIGHT - 1) * GRID_PADDING;

	int start_x = (win->width - grid_width) / 2;
	int start_y = (win->height - grid_height) / 2;

	for(int row = 0; row < GRID_HEIGHT; row++){
		for(int col = 0; col < GRID_WIDTH; col++){
	
			int idx = row * GRID_WIDTH + col;
			int x = start_x + col * (CELL_WIDTH + GRID_PADDING);
			int y = start_y + row * (CELL_HEIGHT + GRID_PADDING);

			win->grid.cells[idx] = (Cell){
				.rect = (Rectangle){
					x, y,
					CELL_WIDTH, CELL_HEIGHT,
				},
				.width = CELL_WIDTH,
				.height = CELL_HEIGHT,
				.is_on = false,
				.orig_y = y,
			};
		}
	}

	if(debug){ // free win board
		get_cell(&win->grid, 0, 4)->is_on = true;
		get_cell(&win->grid, 1, 3)->is_on = true;
		get_cell(&win->grid, 1, 4)->is_on = true;
		get_cell(&win->grid, 2, 4)->is_on = true;
	} else {

	const int moves = 30;
	for(int i = 0; i < moves; i++){
		int row = rand() % GRID_HEIGHT;
		int col = rand() % GRID_WIDTH;
		toggle_cell(&win->grid, row, col);
		}
	}
}

void render_grid(const Window* win){

	Color center;
	Color border_color = BG_COLOR;
	// haha 67
	border_color.b += 67;

	for(int row = 0; row < win->grid_h; row++){
		for(int col = 0; col < win->grid_w; col++){
			
			int idx = row * win->grid_w + col;
			Cell* cell = &win->grid.cells[idx];

			Vector2 pos  = (Vector2) {.x = cell->rect.x, .y = cell->rect.y };
			Vector2 size = (Vector2) {.x = cell->rect.width, .y = cell->rect.height};
			center = (Color) (cell->is_on ? WHITE : BLACK);

			DrawRectangleV(pos, size, center);
			DrawRectangleLinesEx(cell->rect, 2.5f, border_color);
		}
	} 
}

void free_grid(Window* win){	
	free(win->grid.cells);
	win->grid.cells = NULL;
}
