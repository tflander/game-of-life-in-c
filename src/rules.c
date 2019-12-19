#include "rules.h"
#include "grid.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

bool cell_alive(bool alive_now, int neighbors)
{
    if (alive_now)
        return neighbors > 1 && neighbors < 4;
    else 
        return neighbors == 3;
}

void tick(struct Grid grid) {
    char update[grid.numCols][grid.numRows];
    for(int c = 0; c < grid.numCols; ++c) {
        for(int r = 0; r < grid.numRows; ++r) {
            struct Point point = {.x=c, .y=r};
            int n = count_neighbors(grid, point);
            bool aliveNow = isAlive(grid, point);
            if(cell_alive(aliveNow, n)) {
                update[c][r] = 'X';
            } else {
                update[c][r] = ' ';
            }
        }
    }
    memcpy(grid.data, &update, sizeof(char) * grid.numRows * grid.numRows);
}

bool isAlive(struct Grid grid, struct Point point) {
    char x = *((grid.data + point.x * grid.numRows) + point.y);
    return x == 'X';
}

bool notMe(int c, int r, int col, int row) {
    return r != row || c != col;
}

bool inGrid(int c, int r, int numCols, int numRows) {
    return c > -1 && r > -1 && c < numCols && r < numRows;
}

int count_neighbors(struct Grid grid, struct Point point) {
    int count = 0;
    for (int c = point.x - 1; c <= point.x + 1; ++c) {
        for (int r = point.y - 1; r <= point.y + 1; ++r) {
            if(notMe(c,r,point.x,point.y) && inGrid(c, r, grid.numCols, grid.numRows)) {
                char x = *((grid.data+c*grid.numRows) + r);
                if(x == 'X') {
                    ++count;
                }
            }
        }
    }
    return count;
}

void print(struct Grid grid) {
    int c, r; 
    printf("\n");
    for (r = 0; r < grid.numRows; r++) {
        for (c = 0; c < grid.numCols; c++) {
            char x = *((grid.data+c*grid.numRows) + r);
            if (x == ' ') {
                x = '.';
            }
            printf("%c ", x); 
        }
        printf("\n");
    }
}


void wipeGrid(struct Grid grid) {
    for(int c = 0; c < grid.numCols; ++c) {
        for(int r = 0; r < grid.numRows; ++r) {
            *((grid.data +c*grid.numRows) + r) = ' ';
        }
    }
}

void setCell(struct Grid grid, struct Point point, bool isLive) {
    char mark = isLive ? 'X' : ' ';
    *((grid.data + point.x * grid.numRows) + point.y) = mark;
}

void setLivingCell(struct Grid grid, struct Point point) {
    setCell(grid, point, true);
}

void setDeadCell(struct Grid grid, struct Point point) {
    setCell(grid, point, false);
}

void setRow(struct Grid grid, int row, char* columns) {
    int numColsToSet = strlen(columns);
    for (int c = 0; c < numColsToSet; ++c) {
        char mark = columns[c];
        if(mark == 'X') {
            setLivingCell(grid, (struct Point){.x=c, .y=row});
        } else {
            setDeadCell(grid, (struct Point){.x=c, .y=row});
        }
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

void rowAsString(char* buffer, struct Grid grid, int rowIndex) {
    buffer[grid.numCols + 1] = 0;
    for (int c = 0; c < grid.numCols; ++c) {
        if(isAlive(grid, (struct Point){c, rowIndex})) {
            buffer[c] = 'X';
        } else {
            buffer[c] = '.';
        }
    }
}
