#include "rules.h"
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
            int n = count_neighbors(grid, c, r);
            bool aliveNow = isAlive(grid.data, grid.numRows, c, r);
            if(cell_alive(aliveNow, n)) {
                update[c][r] = 'X';
            } else {
                update[c][r] = ' ';
            }
        }
    }
    memcpy(grid.data, &update, sizeof(char) * grid.numRows * grid.numRows);
}

bool isAlive(char* data, int numRows, int col, int row) {
    char x = *((data+ col * numRows) + row);
    return x == 'X';
}

bool notMe(int c, int r, int col, int row) {
    return r != row || c != col;
}

bool inGrid(int c, int r, int numCols, int numRows) {
    return c > -1 && r > -1 && c < numCols && r < numRows;
}

int count_neighbors(struct Grid grid, int col, int row) {
    int count = 0;
    for (int c = col - 1; c <= col + 1; ++c) {
        for (int r = row - 1; r <= row + 1; ++r) {
            if(notMe(c,r,col,row) && inGrid(c, r, grid.numCols, grid.numRows)) {
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

void setLivingCell(struct Grid grid, int col, int row) {
    *((grid.data + col * grid.numRows) + row) = 'X';
}

void setDeadCell(struct Grid grid, int col, int row) {
    *((grid.data + col * grid.numRows) + row) = 'X';
}

void setRow(struct Grid grid, int row, char* columns) {
    int numColsToSet = strlen(columns);
    for (int c = 0; c < numColsToSet; ++c) {
        char mark = columns[c];
        if(mark == 'X') {
            setLivingCell(grid, c, row);
        } else {
            setDeadCell(grid, c, row);
        }
    }
}

void setGrid(struct Grid grid, int numRows, ...) {
    va_list ap; 

    va_start(ap, numRows); 
  
    for (int r = 0; r < numRows; ++r) {
        char* row = va_arg(ap, char*); 
        setRow(grid, r, row);
    }
  
    va_end(ap); 
  
}

