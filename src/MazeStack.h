//
// Created by John Hatcher on 2021-02-21.
//

#ifndef ASSIGNMENT_2_MAZESTACK_H
#define ASSIGNMENT_2_MAZESTACK_H

#include <ostream>
#include "Node.h"


class MazeStack {
private:
    Node *first;
    Node *last;

public:
    MazeStack();
    ~MazeStack();

    void Push(MazePosition data);
    MazePosition Peek();
    MazePosition Pop();

    friend ostream& operator<<(ostream& output, MazeStack& stack);
};


#endif //ASSIGNMENT_2_MAZESTACK_H
