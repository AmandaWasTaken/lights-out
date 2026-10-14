#include "window.h"
#include "game.h"
#include "grid.h"
#include "colors.h"
#include <raylib.h>
#include <stdio.h>


static void render_moves(Window* win){

	const size_t text_padding_x = 20;
	const size_t text_padding_y = 25;
	const size_t font_size = 32;
	char moves[16];

	snprintf(moves, sizeof(moves), "%s %i", "Moves", win->moves);
	DrawText(moves, text_padding_x, text_padding_y, font_size, RED);
}

static void crouch(Window* win){

	const int crouch_height = win->cell_h / 2;

	for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
    	Cell* cell = &win->grid.cells[i];

    	if (IsKeyDown(KEY_LEFT_SHIFT)) {
    	    cell->rect.height = crouch_height;
    	    cell->rect.y = cell->orig_y + (win->cell_h - crouch_height);
    	} else {
    	    cell->rect.height = win->cell_h;
    	    cell->rect.y = cell->orig_y;
    	}
	}
}

static void reset_game(Window* win){

	free_grid(win);
	win->has_won = false;
	init_grid(win);
}

static void poll_inputs(Window* win){

	if(IsKeyDown(KEY_LEFT_SHIFT) || IsKeyReleased(KEY_LEFT_SHIFT)){
		crouch(win);
	}

	if(IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_R)){
		reset_game(win);
	}
	
	if(!IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || win->has_won) return;

	Vector2 mouse_pos = GetMousePosition();

	for(size_t i = 0; i < win->grid_w; i++){
		for(size_t j = 0; j < win->grid_h; j++){

			size_t idx = i * win->grid_w + j;
			if(CheckCollisionPointRec(mouse_pos, win->grid.cells[idx].rect)){
				toggle_cell(&(win->grid), i, j);
				win->moves++;
				return;
			}
		}
	}
}

static bool game_over(Window* win){
	
	for(int i = 0; i < win->grid_w * win->grid_h; i++){
		if(win->grid.cells[i].is_on == true) return false;
	}
	return true;
}

static void draw_win_text(Window* win){
	
	const char* text = "You Won";
	const char* reset_text = "CTRL + R to start a new game";
	const size_t font_size = 128;
	const size_t text_width = MeasureText(text, font_size);
	const int text_pos_x = (win->width - text_width) / 2;
	const int text_pos_y = font_size * 2;
	const int reset_text_pos_x = (win->width - MeasureText(reset_text, 32)) / 2;

	DrawText(text, text_pos_x, text_pos_y, font_size, GREEN);
	DrawText(reset_text, reset_text_pos_x, text_pos_y + font_size, 32, GREEN);
}

static void render_reset_text(Window* win){
	
	const char* text = "CTRL + R to start a new game";
	const size_t font_size = 16;
	const size_t text_width = MeasureText(text, font_size);
	const size_t text_padding_x = 24;
	
	const int text_pos_y = win->height - font_size * 2;
	const int text_pos_x = win->width - text_width - text_padding_x;
	DrawText(text, text_pos_x, text_pos_y, font_size, GREEN);

}

void game(Window* win){

	init_grid(win);

	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BG_COLOR);

		poll_inputs(win);
		render_grid(win);
		render_moves(win);
		render_reset_text(win);

		if(game_over(win)){
			win->has_won = true;
		}

		if(win->has_won){
			draw_win_text(win);
		}

		EndDrawing();
	}

	CloseWindow();
}
