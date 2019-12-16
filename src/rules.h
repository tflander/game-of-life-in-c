#ifndef _RULES_H_
#define _RULES_H_

#include <stdbool.h>

struct Grid {
    char* data;
    int numCols;
    int numRows;
};

bool cell_alive(bool alive_now, int neighbors);
void setLivingCell(struct Grid grid, int col, int row);
void setRow(struct Grid grid, int row, char* columns);
void setGrid(struct Grid grid, ...);
bool isAlive(struct Grid grid, int col, int row);
void wipeGrid(struct Grid grid);
void print(struct Grid grid);
int count_neighbors(struct Grid grid, int col, int row);
void tick(struct Grid grid);
void rowAsString(char* buffer, struct Grid grid, int rowIndex);

#endif