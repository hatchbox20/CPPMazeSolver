//
// Created by John Hatcher on 2021-02-21.
//

#ifndef ASSIGNMENT_2_MAZEPOSITION_H
#define ASSIGNMENT_2_MAZEPOSITION_H

#include <ostream>
using namespace std;

class MazePosition {
public:
    int col = 0;
    int row = 1;

    MazePosition();
    MazePosition(int row, int col);
    MazePosition(const MazePosition& pos);
    bool IsEqual(MazePosition pos);

    friend ostream& operator<<(ostream& output, MazePosition pos);
};


#endif //ASSIGNMENT_2_MAZEPOSITION_H
