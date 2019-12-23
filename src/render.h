#ifndef _RENDER_H_
#define _RENDER_H_

#include "grid.h"

void display(struct Grid grid);
void rowAsString(char* buffer, struct Grid grid, int rowIndex);

struct displayFunctionPointers {
    void (*preDisplayFunction)(void); 
    void (*endRowFunction)(void); 
    void (*postDisplayFunction)(void); 
    void (*displayCellFunction)(struct Point point, char mark);
};

// TODO: struct of function pointers?
void defaultPreDisplay();
void defaultPostDisplay();
void defaultDisplayCell(struct Point point, char mark);
void defaultEndRow();

#endif