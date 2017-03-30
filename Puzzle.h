/* 
 * File:   Puzzle.h
 * Author: Claire McCarthy - clmccart
 *
 * Created on February 27, 2015, 11:45 AM
 * 
 * 
 * PUZZLE.H
 *  Assignment 4 - Source code for CSCI2101 Assignment 4
 * 
 * FUNCTIONAL DESCRIPTION
 *  This Program in C++ fulfills the requirements of Assignment 4.
 *  Contains the function prototypes and private variables for the Puzzle class
 *  to be used throughout the program. 
 * 
 */

#ifndef PUZZLE_H
#define	PUZZLE_H
#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string>
#include "Dictionary.h"

using namespace std;

class Puzzle {
public:
    //function prototypes
    Puzzle();
    int loadPuzzle();
    void printPuzzle();
    void findMatches(Dictionary dictionary, int minWordLength);
    //in-line functions
    int getRows() { return numRows; }
    int getCols() { return numCols; } 
    char *getBoard() { return &theBoard[0][0]; }
private:
    //private variables
    static const int MAX_ROWS = 10;
    static const int MAX_COLUMNS = 10;
    int numRows;
    int numCols;
    int minWordLength;
//  two-d array for the actual puzzle board
    char theBoard[MAX_ROWS][MAX_COLUMNS];
  
};

#endif	/* PUZZLE_H */

