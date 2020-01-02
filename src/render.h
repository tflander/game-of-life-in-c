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

void overrideDisplay(struct displayFunctionPointers fp);

#endif