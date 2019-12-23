#include "render.h"
#include <stdio.h>

struct displayFunctionPointers defaultDisplayFunctionPointers = {
    &defaultPreDisplay,
    &defaultEndRow,
    &defaultPostDisplay,
    &defaultDisplayCell
    };

void display(struct Grid grid) {
    int c, r; 
    (*defaultDisplayFunctionPointers.preDisplayFunction)();
    for (r = 0; r < grid.numRows; r++) {
        for (c = 0; c < grid.numCols; c++) {
            struct Point point = {.x=c, .y=r};
            char x = getCell(grid, point);
            (*defaultDisplayFunctionPointers.displayCellFunction)(point, x);
        }
        (*defaultDisplayFunctionPointers.endRowFunction)();
    }
    (*defaultDisplayFunctionPointers.postDisplayFunction)();
}

void defaultPreDisplay() {
    printf("\n\n");
}

void defaultPostDisplay() {
    printf("\n");
}

void defaultDisplayCell(struct Point point, char mark) {
    if (mark == ' ') {
        mark = '.';
    }
    printf("%c ", mark); 
}

void defaultEndRow() {
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
