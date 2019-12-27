#ifndef _GRID_H_
#define _GRID_H_

#include <stdbool.h>

struct Point {
    int x;
    int y;
};

struct Grid {
    char* data;
    int numRows;
    int numCols;
};

void setCell(struct Grid grid, struct Point point, bool isLive);
void setLivingCell(struct Grid grid, struct Point point);
bool isAlive(struct Grid grid, struct Point point);
void wipeGrid(struct Grid grid);
void randomizeGrid(struct Grid grid, int seed);
char getCell(struct Grid grid, struct Point point);

void setRow(struct Grid grid, int row, char* columns);
void setGrid(struct Grid grid, ...);

#endif
