/* 
 * File:   Puzzle.cpp
 * Author: Claire
 * 
 * Created on February 27, 2015, 11:45 AM
 * 
 * PUZZLE.CPP
 *  contains the Puzzle, printPuzzle, and findMatches functions for the Puzzle
 *  class. 
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
 * Function Name: Puzzle - loads the data from the file into a 2-D array
 * Functional Description: 
 * Loads the puzzle from the p2.txt file into a two dimensional array of 
 * characters. Checks to make sure that the file isn't empty or non-rectangular.
 * Then, enters the first row of the board into the array and then enters the 
 * following rows until there are no more lines to read in the file. 
 * Entry Parameters: none
 * Return Values: none
 */
Puzzle::Puzzle() {
    
   string fileName;
  
   ifstream puzzleStream;                
   // will be the puzzle file
    // read in the puzzle file name
    do {
        cout << "\nEnter puzzle file name: ";
        cin >> fileName;
        puzzleStream.open(fileName, ios::in);
    } while (!puzzleStream.good());      // keep trying until this works
    
    string line;
    
    // make sure the file has some stuff in it
    if (!getline(puzzleStream, line)) {
        cerr << "Error: puzzle file is empty" << endl;
        numRows = 0;
        numCols = 0;
        return;
    }
    
    // put the first puzzle line in theBoard
        numCols = line.size();
            for (int i = 0; i < numCols; i++) {
                theBoard[0][i] = tolower(line.at(i));   
            }
        
        // put the rest of the puzzle lines in theBoard       
        for (numRows = 1; getline(puzzleStream, line); numRows++) { 
            // make sure it’s rectangular
            if (line.size() != numCols) { 
                cerr << "Error: puzzle is not rectangular" << endl;
                numRows = 0;
                numCols = 0;
                return;
            }
            
            // put this puzzle line in theBoard
            for (int i = 0; i < numCols; i++) {
                theBoard[numRows][i] = tolower(line.at(i));     
            }
        }
    
   
 
} 

/*
 * Function Name: printPuzzle - prints the puzzle board
 * Functional Description: 
 * Uses a for loop to print out each individual character stored in the two 
 * dimensional array. Changes the characters stored in the array from lower case
 * to upper case letters.
 * Entry Parameters: none
 * Return Values: void
 */
void Puzzle::printPuzzle() {
    for (int r = 0; r < numRows; r++) {
        cout << "\n"; 
        for (int c = 0; c < numCols; c++) {
            char letter = theBoard[r][c];
            char upperLetter = toupper(letter);
            cout << upperLetter << " ";
        }  
    }
    
}

/*
 * Function Name: findMatches - searches through the dictionary to find matches.
 * Functional Description: 
 * Uses binary and prefix search to find words within the puzzle that match
 * words in the dictionary. Does the binary search first and then the prefix 
 * search. Checks for matches by continually going through the loop as long
 * as the words still match and you haven't run off the end of the puzzle. 
 * Entry Parameters: Dictionary dictionary, int minWordLength
 * Return Values: void
 */
void Puzzle::findMatches(Dictionary dictionary, int minWordLength) {
    
    string word = "";
    for (int r = 0; r <= numRows; ++r) {
        for (int c = 0; c <= numCols; ++c){
            //So that it goes through every position in the puzzle
            for (int rDelta = -1; rDelta <= 1; ++rDelta) {
                for (int cDelta = -1; cDelta <= 1; ++cDelta) {
                    
                    char char1 = theBoard[r][c];
                    char char2 = theBoard[r + rDelta][c + cDelta];  
                    
                    string prefix = "";
                    prefix.append(char1, char2);
                    
                    if (dictionary.isPrefix(prefix)) {
                        for (int rDelta = -1; rDelta <= 1 && r + rDelta >= 0 &&
                                r + rDelta <= numRows; ++rDelta) {
                            for (int cDelta = -1; cDelta <= 1 && c + cDelta >= 0
                                    && c + cDelta <= numCols; ++cDelta) {
                                //adds a change in direction to the row and col
                                word = word + theBoard[r + rDelta][c + cDelta];
                                
                                //if the word is found, prints out the word and
                                //the coordinates
                                if (word.length() >= minWordLength &&
                                        dictionary.binarySearch(word)) {
                                    
                                    cout << word << "was found at (" <<
                                            r + rDelta << ", " << c + cDelta 
                                            << ")" << endl;
                                }
                            }
                        }
                    } 
                }
            }
        }
    }
}
    
    
    
