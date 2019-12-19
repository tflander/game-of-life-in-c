#ifndef _GRID_H_
#define _GRID_H_

#include <stdbool.h>

struct Point {
    int x;
    int y;
};

struct Grid {
    char* data;
    int numCols;
    int numRows;
};

void setLivingCell(struct Grid grid, struct Point point);
void setRow(struct Grid grid, int row, char* columns);
void setGrid(struct Grid grid, ...);
bool isAlive(struct Grid grid, struct Point point);
void wipeGrid(struct Grid grid);
void tick(struct Grid grid);


#endif
