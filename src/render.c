#include "render.h"
#include <stdio.h>

void defaultPreDisplay();
void defaultPostDisplay();
void defaultDisplayCell(struct Point point, char mark);
void defaultEndRow();

struct displayFunctionPointers displayFunctionPointers = {
    &defaultPreDisplay,
    &defaultEndRow,
    &defaultPostDisplay,
    &defaultDisplayCell
    };

void display(struct Grid grid) {
    int c, r; 
    (*displayFunctionPointers.preDisplayFunction)();
    for (r = 0; r < grid.numRows; r++) {
        for (c = 0; c < grid.numCols; c++) {
            struct Point point = {.x=c, .y=r};
            char mark = getCell(grid, point);
            (*displayFunctionPointers.displayCellFunction)(point, mark);
        }
        (*displayFunctionPointers.endRowFunction)();
    }
    (*displayFunctionPointers.postDisplayFunction)();
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

void overrideDisplay(struct displayFunctionPointers fp) {
    if(fp.displayCellFunction) {
        displayFunctionPointers.displayCellFunction = fp.displayCellFunction;
    }

    if(fp.preDisplayFunction) {
        displayFunctionPointers.preDisplayFunction = fp.preDisplayFunction;
    }

    if(fp.endRowFunction) {
        displayFunctionPointers.endRowFunction = fp.endRowFunction;
    }

    if(fp.postDisplayFunction) {
        displayFunctionPointers.postDisplayFunction = fp.postDisplayFunction;
    }
}


// TODO: move to test support
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
