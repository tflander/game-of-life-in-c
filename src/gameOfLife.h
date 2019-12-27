#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include "grid.h"

// struct Grid createEmptyGrid(int numRows, int numColumns);
// struct Grid createRandomGrid(int numRows, int numColumns, int seed);
// void wipeGrid(struct Grid grid);
void randomizeGrid(struct Grid grid);

void tick(struct Grid grid);

// void destroyGrid(struct Grid grid);

#endif