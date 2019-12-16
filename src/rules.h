#ifndef _RULES_H_
#define _RULES_H_

#include <stdbool.h>

bool cell_alive(bool alive_now, int neighbors);
int count_neighbors(char* data, int numCols, int numRows, int col, int row);
void wipeGrid(char* data, int numCols, int numRows);
void print(char* data, int numCols, int numRows);
void setLivingCell(char* data, int numRows, int col, int row);
void tick(char* data, int numCols, int numRows);
bool isAlive(char* data, int numRows, int col, int row);

#endif