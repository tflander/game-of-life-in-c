#include "render.h"
#include <stdio.h>

void (*preDisplayFunction)(void) = &preDisplay; 
void (*endRowFunction)(void) = &endRow; 
void (*postDisplayFunction)(void) = &postDisplay; 
void (*displayCellFunction)(struct Point point, char mark) = &displayCell;

void display(struct Grid grid) {
    int c, r; 
    (*preDisplayFunction)();
    for (r = 0; r < grid.numRows; r++) {
        for (c = 0; c < grid.numCols; c++) {
            struct Point point = {.x=c, .y=r};
            char x = getCell(grid, point);
            (*displayCellFunction)(point, x);
        }
        (*endRowFunction)();
    }
    (*postDisplayFunction)();
}

void preDisplay() {
    printf("\n\n");
}

void postDisplay() {
    printf("\n");
}

void displayCell(struct Point point, char mark) {
    if (mark == ' ') {
        mark = '.';
    }
    printf("%c ", mark); 
}

void endRow() {
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
