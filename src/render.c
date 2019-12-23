#include "render.h"
#include <stdio.h>

void display(struct Grid grid) {
    int c, r; 
    printf("\n\n");
    for (r = 0; r < grid.numRows; r++) {
        for (c = 0; c < grid.numCols; c++) {
            char x = getCell(grid, (struct Point){.x=c, .y=r});
            if (x == ' ') {
                x = '.';
            }
            printf("%c ", x); 
        }
        printf("\n");
    }
    printf("\n");
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
