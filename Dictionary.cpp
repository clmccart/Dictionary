/* 
 * File:   Dictionary.cpp
 * Author: Claire
 * 
 * Created on February 27, 2015, 11:44 AM
 * 
 * DICTIONARY.CPP
 * Dictionary.c – Source code for CSCI2101 Assignment 4.
 * Functional Description
 * This program is C++ fulfills the requirements of Assignment 4 in CSCI2101 
 * Spring 2015.
 * Loads the dictionary file into a vector and provides a binary search method
 * and a method to check if a word is a prefix or not. 
 * NOTICE.
 * Copyright (C) 2014 Claire McCarthy All Rights Reserved.
 */

#include "Dictionary.h"
#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string>

using namespace std;
/*
 * Function Name: Dictionary - loads the dict file into a vector of strings
 * Functional description: 
 * loads the dictionary file into a vector of strings using ifstream and assumes
 * that the file is in alphabetical order so it just uses push back to insert
 * the words. Then, it prints out the size of the dictionary for the user.
 * Entry Parameters: none
 * Return Type: none
 */
Dictionary::Dictionary() {
   
   string fileName;
   
   ifstream dictionaryStream;                
   // will be the puzzle file
    // read in the puzzle file name
    do {
        cout << "\nEnter dictionary file name: ";
        cin >> fileName;
        
        dictionaryStream.open(fileName, ios::in);
        
    } while (!dictionaryStream.good());      // keep trying until this works
    
    
    
    string line;
    // make sure the file has some stuff in it
    if (!getline(dictionaryStream, line)) {
        cerr << "Error: dictionary file is empty" << endl; 
    }
    //assuming the file is in alphabetical order
    while (getline(dictionaryStream, line)){
        string insertLine = line;
        dictionary.push_back(insertLine);
    }
    //prints out the size of the dictionary
    cout << "\nSize of the dictionary: " << dictionary.size() << " words" << 
            endl;
    
}

/*
 * Function Name: binarySearch - uses binary search to see if the word matches. 
 * Functional description:
 * Uses binary search method to see if the word matches any of the words in the 
 * dictionary. Splits the dictionary in half until it comes to a word that 
 * matches.
 * Entry Parameters: string word
 * Return Values: boolean
 */
bool Dictionary::binarySearch(string word) {
    
    int high = dictionary.size();
    int low = 0;
    
    while (low <= high) {
        int midpoint = low + ((high - low) / 2);
        if (dictionary.at(midpoint).compare(word) == 0) {
            return true;
        }
        if (dictionary.at(midpoint).compare(word) > 0) {
            low = midpoint;
        }
        if (dictionary.at(midpoint).compare(word) < 0) {
            high = midpoint; 
        }
    }
    //if it gets tot his point, there is no match
    return false;
    
}

/*
 * Function Name: is PRefix - checks to see if the given word is a prefix 
 * Functional description:
 * Uses the given word to check and see if it matches the first two letters 
 * of any word in the dictionary. If not, returns false.
 * Entry Parameters: string word - the prefix you are trying to validate
 * Return Values: boolean
 */
bool Dictionary::isPrefix(string word) {
     
    for (int i = 0; i < dictionary.size(); ++i) {
        if (dictionary.at(i).substr(0, 2) == word) {
            return true;
        }  
    }

    return false;
}



