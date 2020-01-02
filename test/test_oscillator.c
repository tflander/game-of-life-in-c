#include <stdbool.h>
#include <unity_fixture.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "gameOfLife.h"
#include "rules.h"
#include "render.h"
#include "neighbor_counter.h"
#include "support.h"

const int numColsForPinwheelTests = 12;
const int numRowsForPinwheelTests = 12;
char gridData[numRowsForPinwheelTests][numColsForPinwheelTests];
struct Grid gridForPinwheel = (struct Grid){(char*)gridData, numRowsForPinwheelTests, numColsForPinwheelTests};

TEST_GROUP(Oscillator);

void myPreDisplay() {
    printf("\nGame Of Life\n");
}

void myPostDisplay() {
    printf("^^^^^^^^^^^^^^\n");
}

void myDisplayCell(struct Point point, char mark) {
    printf("%c", mark);
}

void myEndRow() {
    printf("|\n");
}

TEST_SETUP(Oscillator) {

    struct displayFunctionPointers fp = {
        .displayCellFunction = myDisplayCell,
        .preDisplayFunction = myPreDisplay,
        .endRowFunction = myEndRow,
        .postDisplayFunction = myPostDisplay

    };
    overrideDisplay(fp);

    wipeGrid(gridForPinwheel);
}
TEST_TEAR_DOWN(Oscillator) {
}

TEST(Oscillator, pinwheel)
{
    setGrid(gridForPinwheel,
        "......XX....",
        "......XX....",
        "............",
        "....XXXX....",
        "XX.X..X.X...",
        "XX.XX...X...",
        "...X.X..X.XX",
        "...X....X.XX",
        "....XXXX....",
        "............",
        "....XX......",
        "....XX......"
    );

    tick(gridForPinwheel);
    display(gridForPinwheel);
    
    verifyGrid(gridForPinwheel,
        "......XX....",
        "......XX....",
        "............",
        "....XXXX....",
        "XX.X..X.X...",
        "XX.X.X..X...",
        "...X...XX.XX",
        "...X....X.XX",
        "....XXXX....",
        "............",
        "....XX......",
        "....XX......"
    );

    for (int i = 0; i < 10; ++i) {
        sleep(1);
        tick(gridForPinwheel);
        display(gridForPinwheel);
    }
}

TEST_GROUP_RUNNER(Oscillator)
{
    RUN_TEST_CASE(Oscillator, pinwheel);
}

