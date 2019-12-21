#include "grid.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

bool isAlive(struct Grid grid, struct Point point) {
    return getCell(grid, point) == 'X';
}

void setCell(struct Grid grid, struct Point point, bool isLive) {
    char mark = isLive ? 'X' : ' ';
    grid.data[point.y][point.x] = mark;
}

char getCell(struct Grid grid, struct Point point) {
    return grid.data[point.y][point.x];
}

void setLivingCell(struct Grid grid, struct Point point) {
    setCell(grid, point, true);
}

void setDeadCell(struct Grid grid, struct Point point) {
    setCell(grid, point, false);
}

void wipeGrid(struct Grid grid) {
    for(int c = 0; c < grid.numCols; ++c) {
        for(int r = 0; r < grid.numRows; ++r) {
            struct Point point = {.x=c, .y=r};
            setDeadCell(grid, point);
        }
    }
}

void setRow(struct Grid grid, int row, char* columns) {
    int numColsToSet = strlen(columns);
    for (int c = 0; c < numColsToSet; ++c) {
        char mark = columns[c];
        setCell(grid, (struct Point){.x=c, .y=row}, (mark == 'X'));
    }
}

void setGrid(struct Grid grid, ...) {
    va_list ap; 
    va_start(ap, grid); 
  
    for (int r = 0; r < grid.numRows; ++r) {
        char* row = va_arg(ap, char*); 
        setRow(grid, r, row);
    }
  
    va_end(ap); 
}
