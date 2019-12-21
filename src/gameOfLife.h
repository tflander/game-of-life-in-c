#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include "grid.h"

struct Grid createEmptyGrid(int numRows, int numColumns);

void tick(struct Grid* grid);

void destroyGrid(struct Grid grid);

#endif