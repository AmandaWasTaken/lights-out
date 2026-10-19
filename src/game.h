#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include "window.h"


void game(Window* win);
void toggle_cell(Grid* grid, int row, int col, int w, int h);
#endif
