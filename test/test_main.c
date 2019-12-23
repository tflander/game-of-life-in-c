#include "unity_fixture.h"

static void run_all_tests(void) { 
    RUN_TEST_GROUP(Rules); 
    RUN_TEST_GROUP(Grid); 
    RUN_TEST_GROUP(Oscillator); 
    RUN_TEST_GROUP(NeoPixelAdapter); 
}

int main(int argc, const char *argv[])
{
    return UnityMain(argc, argv, run_all_tests);
}