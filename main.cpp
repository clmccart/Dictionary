/* 
 * File:   main.cpp
 * Author: Claire McCarthy - clmccart
 *
 * Created on February 26, 2015, 9:40 PM
 * 
MAIN.CPP.
// Assignment4.c – Source code for CSCI2101 Assignment 4. Word Search Lab 
// FUNCTIONAL DESCRIPTION.
// This program is C++ fulfills the requirements of Assignment 4 in 
 * CSCI2101 Fall 2015.
 * 1. get the dictionary filename,create the dictionary,and print its size
    2. get the puzzle filename,read the puzzle,print its dimensions,and print 
     the puzzle (in upper-case, but chars in the array your algorithms actually  
    use should be lower-case)
    3. ask for and read in the minimum word length and
    4. display the results of each search(worst to best),including coordinates 
 *  of words found, number of words found, and solution time
//
// NOTICE.
// Copyright (C) 2014 Claire McCarthy All Rights Reserved. //
 */

#include <cstdlib>
#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string>

#include "Puzzle.h"
#include "Dictionary.h"

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    
    Dictionary dictionary = Dictionary();
   
    Puzzle puzzle = Puzzle();
    puzzle.printPuzzle();
    
    int minWordLength;
    cout << "\n\nEnter minimum word length:";
    cin >> minWordLength;
    
    puzzle.findMatches(dictionary, minWordLength); 
   
    return EXIT_SUCCESS;
}



