//
// Created by John Hatcher on 2021-02-21.
//

#ifndef ASSIGNMENT_2_NODE_H
#define ASSIGNMENT_2_NODE_H

#include "MazePosition.h"

class Node {
public:
    MazePosition pos;
    Node *next;
    Node *prev;

    Node();

};

#endif //ASSIGNMENT_2_NODE_H
