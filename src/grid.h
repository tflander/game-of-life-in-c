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
void print(struct Grid grid);
int count_neighbors(struct Grid grid, struct Point point);
void tick(struct Grid grid);
void rowAsString(char* buffer, struct Grid grid, int rowIndex);


#endif
