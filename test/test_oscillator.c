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

struct Grid gridForPinwheel;


TEST_GROUP(Oscillator);

TEST_SETUP(Oscillator) {
    gridForPinwheel = createEmptyGrid(12, 12);
}
TEST_TEAR_DOWN(Oscillator) {
    destroyGrid(gridForPinwheel);
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

    tick(&gridForPinwheel);
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
        tick(&gridForPinwheel);
        display(gridForPinwheel);
    }
}

TEST_GROUP_RUNNER(Oscillator)
{
    RUN_TEST_CASE(Oscillator, pinwheel);
}

