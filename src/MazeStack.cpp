//
// Created by John Hatcher on 2021-02-21.
//

#include "MazeStack.h"

// Construct/Destruct
MazeStack::MazeStack() : first(nullptr), last(nullptr) {}

MazeStack::~MazeStack() {
    while (first != nullptr) {
        Pop();
    }
}

// Push an item onto the stack
void MazeStack::Push(MazePosition pos) {
    Node* node = new Node();
    node->pos = pos;
    node->prev = last;

    if (first == nullptr) {
        // add the first node
        first = node;
    } else {
        // add other node
        last->next = node;
    }

    last = node;
}

// Pop the last item off of the stack
MazePosition MazeStack::Pop() {

    // have a node to pop
    if (first != nullptr) {

        Node *node = last;

        // the previous pointer is the new last node
        last = last->prev;

        // if there is still a node in the stack
        if (last != nullptr) {
            // set the new last node to point to null
            last->next = node->next;
        }

        // we are removing the only node in the stack
        if (node == first) {
            first = nullptr;
        }

        MazePosition temp = node->pos;

        delete node;

        return temp;
    }
}

// Return the last item on the stack without removing
MazePosition MazeStack::Peek() {
    if (last != nullptr) {
        return last->pos;
    }
    return MazePosition();
}

// Overloaded output operator
ostream& operator<<(ostream& os, MazeStack& stack) {
    Node* node = stack.first;

    while (node != nullptr) {
        os << node->pos << endl;
        node = node->next;
    }

    return os;
}




