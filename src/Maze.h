//
// Created by John Hatcher on 2021-02-21.
//

#ifndef ASSIGNMENT_2_MAZE_H
#define ASSIGNMENT_2_MAZE_H

#include <string>
#include <iostream>
#include "Node.h"
#include "MazeStack.h"

using namespace std;

class Maze {
private:

    char** maze;

    // Hard coded size
    const int rows = 51;
    const int cols = 51;

    bool solved = false;

    string file;

    // Hard coded end position
    MazePosition end = MazePosition(rows - 2, cols - 1);

    // enum to represent the cardinal directions
    enum directions { right, down, left, up };

public:
    Maze(const string &fileName);
    void CreateArray();

    void Move(int move, MazeStack *mazeStack, MazePosition *pos);
    void Path(MazeStack *mazeStack, MazePosition *pos);
    void Solve();
    bool IsMove(MazePosition *here, int direction);

    void PrintMaze();
    void SaveMazeToFile();
    void CleanMaze();
};


#endif //ASSIGNMENT_2_MAZE_H
