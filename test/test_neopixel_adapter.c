// #include <unity_fixture.h>
// #include <stdbool.h>
// #include "neopixel_adapter.h"
// #include "gameOfLife.h"

// struct Grid gridForAdapter;

// TEST_GROUP(NeoPixelAdapter);

// TEST_SETUP(NeoPixelAdapter) {
//     const int numCols = 5;
//     const int numRows = 4;
//     gridForAdapter = createEmptyGrid(numRows, numCols);

// }
// TEST_TEAR_DOWN(NeoPixelAdapter) {}

// TEST(NeoPixelAdapter, point_0_0_is_neopixel_0)
// {
//     TEST_ASSERT_EQUAL(0, strandOffsetForPoint(gridForAdapter, (struct Point){.x=0, .y=0}));
// }

// TEST(NeoPixelAdapter, point_1_0_is_neopixel_1)
// {
//     TEST_ASSERT_EQUAL(1, strandOffsetForPoint(gridForAdapter, (struct Point){.x=1, .y=0}));
// }

// TEST(NeoPixelAdapter, point_4_0_is_neopixel_4)
// {
//     TEST_ASSERT_EQUAL(4, strandOffsetForPoint(gridForAdapter, (struct Point){.x=4, .y=0}));
// }

// TEST(NeoPixelAdapter, point_4_1_is_neopixel_5)
// {
//     TEST_ASSERT_EQUAL(5, strandOffsetForPoint(gridForAdapter, (struct Point){.x=4, .y=1}));
// }

// TEST(NeoPixelAdapter, point_3_1_is_neopixel_6)
// {
//     TEST_ASSERT_EQUAL(6, strandOffsetForPoint(gridForAdapter, (struct Point){.x=3, .y=1}));
// }

// TEST(NeoPixelAdapter, point_0_1_is_neopixel_9)
// {
//     TEST_ASSERT_EQUAL(9, strandOffsetForPoint(gridForAdapter, (struct Point){.x=0, .y=1}));
// }

// TEST(NeoPixelAdapter, point_0_2_is_neopixel_10)
// {
//     TEST_ASSERT_EQUAL(10, strandOffsetForPoint(gridForAdapter, (struct Point){.x=0, .y=2}));
// }

// TEST_GROUP_RUNNER(NeoPixelAdapter)
// {
//     RUN_TEST_CASE(NeoPixelAdapter, point_0_0_is_neopixel_0);
//     RUN_TEST_CASE(NeoPixelAdapter, point_1_0_is_neopixel_1);
//     RUN_TEST_CASE(NeoPixelAdapter, point_4_1_is_neopixel_5);
//     RUN_TEST_CASE(NeoPixelAdapter, point_3_1_is_neopixel_6);
    
//     RUN_TEST_CASE(NeoPixelAdapter, point_0_1_is_neopixel_9);

//     RUN_TEST_CASE(NeoPixelAdapter, point_4_0_is_neopixel_4);
//     RUN_TEST_CASE(NeoPixelAdapter, point_0_2_is_neopixel_10);
// }


