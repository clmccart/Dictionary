/* 
 * File:   Dictionary.h
 * Author: Claire McCarthy - clmccart
 *
 * Created on February 27, 2015, 11:44 AM
 * 
 * DICTIONAR.H
 * Dictionary.h - Source Code for CSCI2101 Assignment 4.
 * Functional Description:
 * Contains all of the function prototypes for the Dictionary class as well as
 * any private variables.
 * NOTICE.
 * Copyright (C) 2015 Claire McCarthy All Rights Reserved
 * 
 */

#ifndef DICTIONARY_H
#define	DICTIONARY_H

#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string>

using namespace std;

class Dictionary {
public:
    
    // constructor
Dictionary();
    bool binarySearch(string word);
    bool isPrefix(string word);
    int size() { return (int)dictionary.size();}
    string at(int i) { return dictionary.at(i); }
private:
    vector<string> dictionary;
};

#endif	/* DICTIONARY_H */

