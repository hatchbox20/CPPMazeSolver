#include "Maze.h"

using namespace std;

int main() {
    // Construct new maze with text file
    Maze maze("test3.txt");

    // Solve maze
    maze.Solve();

    return 0;
}