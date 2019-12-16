#include "rules.h"
#include <stdio.h>

bool cell_alive(bool alive_now, int neighbors)
{
    if (alive_now)
        return neighbors > 1 && neighbors < 4;
    else 
        return neighbors == 3;
}

int count_neighbors(int col, int row) {
    return 0;
}

void print(char* data, int numCols, int numRows) 
{ 
    int c, r; 
    printf("\n");
    for (r = 0; r < numRows; r++) {
        for (c = 0; c < numCols; c++) {
            char x = *((data+c*numRows) + r);
            if (x == ' ') {
                x = '.';
            }
            printf("%c ", x); 
        }
        printf("\n");
    }
} 

void wipeGrid(char* data, int numCols, int numRows) {
    for(int c = 0; c < numCols; ++c) {
        for(int r = 0; r < numRows; ++r) {
            *((data+c*numRows) + r) = ' ';
        }
    }
}

void setLivingCell(char* data, int numRows, int col, int row) {
    *((data+col*numRows) + row) = 'X';
}

