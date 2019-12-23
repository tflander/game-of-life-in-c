#ifndef _RENDER_H_
#define _RENDER_H_

#include "grid.h"

void display(struct Grid grid);
void rowAsString(char* buffer, struct Grid grid, int rowIndex);

// TODO: struct of function pointers?
void preDisplay();
void postDisplay();
void displayCell(struct Point point, char mark);
void endRow();


#endif