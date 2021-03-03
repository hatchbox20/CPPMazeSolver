//
// Created by John Hatcher on 2021-02-21.
//

#include <fstream>
#include "Maze.h"

// Construct maze from text file w/ constructor
Maze::Maze(const string &fileName) {

    // File check
    ifstream infile("../tests/" + fileName);
    if (!infile.good()) {
        cout << "[ERROR] File cannot be used or does not exist. Please try again." << endl;
        return;
    }

    // Assign to property
    file = fileName;

    // Create maze array
    CreateArray();
}

// Go through each character of text file to create 2D array that represents the maze
void Maze::CreateArray() {
    // Init empty maze
    maze = new char*[rows];
    for (int i = 0; i < rows; i++) {
        maze[i] = new char[cols];
    }

    // Iterate through the maze file by using getline() to represent each row of a maze array
    ifstream infile("../tests/" + file);

    while (!infile.eof()) {
        for (int i = 0; i < rows; i++) {
            string row;
            getline(infile, row);

            for (int x = 0; x < cols; x++) {
                maze[i][x] = row[x];
            }
        }
    }

    infile.close();
}

// Takes in a direction and moves position, adding the current position to the stack and setting a path char (#)
void Maze::Move(int direction, MazeStack *mazeStack, MazePosition *pos) {
    mazeStack->Push(*pos);
    maze[pos->row][pos->col] = '#';

    // inc/dec col/row depending on cardinal direction
    switch (direction) {
        case right:
            pos->col += 1;
            break;
        case down:
            pos->row += 1;
            break;
        case left:
            pos->col -= 1;
            break;
        case up:
            pos->row -= 1;
            break;
    }

    // If end reached, set solved to true and assign a # char
    if (pos->IsEqual(end)) {
        solved = true;
        maze[end.row][end.col] = '#';
    }
}

// Check if a particular direction is a valid move, given the current position
bool Maze::IsMove(MazePosition *here, int direction) {
    switch (direction) {
        case up:
            return (maze[here->row - 1][here->col] == ' ');
        case right:
            return (maze[here->row][here->col + 1] == ' ');
        case down:
            return (maze[here->row + 1][here->col] == ' ');
        case left:
            return (maze[here->row][here->col - 1] == ' ');
        default:
            return false;
    }
}

/* Recursive path function */

void Maze::Path(MazeStack *mazeStack, MazePosition *pos) {
    if (!solved) {
        MazePosition here(*pos);
        for (int i = right; i <= up; i++) {
            // Checks valid move and ignore if solved
            if (IsMove(&here, i) && !solved) {
                Move(i, mazeStack, &here);
                Path(mazeStack, &here);
            } else if (solved) {
                // Pop call off stack if already solved
                return;
            }
        }
    // At this point, all options are exhausted on a square
    if (!solved) {
            // Save the popped position in a variable and set the character to X for bad path
            MazePosition temp;
            temp = mazeStack->Pop();
            maze[temp.row][temp.col] = 'X';
            MazePosition last = mazeStack->Peek();
            Path(mazeStack, &last);
        }
    }
}

// Calls the path function on the default starting point, cleaning the bad path characters, and outputting maze
void Maze::Solve() {
    // Creates maze and start point
    MazeStack mazeStack;
    MazePosition here;

    // Runs path trace and cleans bad paths
    Path(&mazeStack, &here);
    CleanMaze();

    // Output
    PrintMaze();
    SaveMazeToFile();
}

// Print maze to console by iterating through the array
void Maze::PrintMaze() {
    for (int i = 0; i < rows; i++) {
        for (int c = 0; c < cols; c++) {
            cout << maze[i][c];
        }
        cout << endl;
    }
    cout << endl;
}

// Save maze to file
void Maze::SaveMazeToFile() {
    ofstream outfile;
    outfile.open("../solved/" + file);

    for (int i = 0; i < rows; i++) {
        for (int x = 0; x < cols; x++) {
            outfile << maze[i][x];
        }

        outfile << "\n";
    }

    outfile.close();
}

// Clean the bad path characters from the maze array by looping through and setting the characters back to empty
void Maze::CleanMaze() {
    for (int i = 0; i < rows; i++) {
        for (int x = 0; x < cols; x++) {
            if (maze[i][x] == 'X') {
                maze[i][x] = ' ';
            }
        }
    }
}


