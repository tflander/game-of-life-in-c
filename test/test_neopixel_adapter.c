#include <unity_fixture.h>
#include <stdbool.h>
#include "neopixel_adapter.h"
#include "gameOfLife.h"

struct Grid gridForAdapter;

TEST_GROUP(NeoPixelAdapter);

TEST_SETUP(NeoPixelAdapter) {
    const int numCols = 5;
    const int numRows = 4;
    gridForAdapter = createEmptyGrid(numRows, numCols);

}
TEST_TEAR_DOWN(NeoPixelAdapter) {}

TEST(NeoPixelAdapter, point_0_0_is_neopixel_0)
{
    TEST_ASSERT_EQUAL(0, strandOffsetForPoint(gridForAdapter, (struct Point){.x=0, .y=0}));
}

TEST_GROUP_RUNNER(NeoPixelAdapter)
{
    RUN_TEST_CASE(NeoPixelAdapter, point_0_0_is_neopixel_0);
}


