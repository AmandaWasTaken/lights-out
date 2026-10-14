#pragma once

#include <raylib.h>

#ifndef WHITE
	#define WHITE CLITERAL(Color){255, 255, 255, 0}
#endif

#define BG_COLOR CLITERAL(Color){ 13, 10, 84, 255}
#define BORDER_COLOR RED 

// These are currently unused because the 
// gradients are super unclear to tell which 
// cell is on but i'll try to make it work some time
// Cell is on
#define CELL_ON_TOP_LEFT   PINK
#define CELL_ON_TOP_RIGHT  BLACK 
#define CELL_ON_BOT_LEFT   BLACK 
#define CELL_ON_BOT_RIGHT  PINK 

// Cell is off
#define CELL_OFF_TOP_LEFT  BLACK 
#define CELL_OFF_TOP_RIGHT PINK 
#define CELL_OFF_BOT_LEFT  PINK 
#define CELL_OFF_BOT_RIGHT BLACK 
//
