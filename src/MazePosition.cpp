//
// Created by John Hatcher on 2021-02-21.
//

#include "MazePosition.h"

// Construct/Destruct
MazePosition::MazePosition() : row(1), col(0) {}
MazePosition::MazePosition(int row, int col) : row(row), col(col) {}
MazePosition::MazePosition(const MazePosition& pos) : MazePosition(pos.row, pos.col) {}

// Overloaded output operator
ostream& operator<<(ostream& output, MazePosition pos) {
    output << "(" << pos.row << "," << pos.col << ")";
    return output;
}

// Check if two maze positions are equal by comparing the row and col properties
bool MazePosition::IsEqual(MazePosition pos) {
    return ((this->col == pos.col) && (this->row == pos.row));
}

