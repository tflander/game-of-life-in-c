#ifndef _TEST_SUPPORT_H_
#define _TEST_SUPPORT_H_

#include "grid.h"

void verifyRow(struct Grid grid, int rowIndex, char* expected);
void verifyGrid(struct Grid grid, ...);

#endif