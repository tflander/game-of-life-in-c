# Conway's Game of Life - C Learning Lab

## Game Rules
The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
1. Any live cell with two or three live neighbours lives on to the next generation.
1. Any live cell with more than three live neighbours dies, as if by overpopulation.
1. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed; births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick. Each generation is a pure function of the preceding one. The rules continue to be applied repeatedly to create further generations.

## How To Build and Run Tests

The first time you build, do the following:

    ~/workspace/life $ mkdir build
    ~/workspace/life $ cd build
    ~/workspace/life/build $ cmake ..

This should generate a long string of text.

### Running Tests

    ~/workspace/life/build $ make && test/game-of-life-test

This should generate a very nice looking build message, and provided that your build was successful, run your tests.

### When You Add New Files

If you add new files

    cmake ..

## Testing Tools

For our example we are using the [Unity](https://github.com/ThrowTheSwitch/Unity) testing suite.  Their documentation is excellent, and we strongly encourage you to read it.

If you need to update the test suite you can run the `source-library.sh` in the test folder.  It will download the latest version of the test suite for you and install it to the test folder.