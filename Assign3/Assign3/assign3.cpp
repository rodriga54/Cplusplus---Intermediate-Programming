//
//  assign3.cpp
//  Assign2
//
//  Created by Abe Rodriguez on 9/23/14.
//  Copyright (c) 2014 ___AbeRodriguez___. All rights reserved.
//

/*********************************************************************
 PROGRAM:    CSCI 241 Assignment 3
 PROGRAMMER: Abe Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   9/26/2014
 
 FUNCTION:   This program tests the functionality of the Verifier
 class.
 *********************************************************************/

#include <iostream>
#include <string>
#include "Verifier.h"

using std::cout;
using std::endl;
using std::string;

#define NUM_FILES 1

int main()
{
    Verifier v;
    string fileName;
    
    cout << "Sudoku Verifier\n";
    
    for (int i = 1; i <= NUM_FILES; i++)
    {
        cout << endl;
        
        // Construct file pathname
        fileName = string("/Users/aberodriguez/Documents/Solution2.txt");
        //fileName = string("/home/turing/t90kjm1/CS241/Data/Fall2014/Assign3/solution")
        //+ (char)('0' + i) + ".txt";
        
        // Read the solution file as input
        v.readGrid(fileName.c_str());
        
        // Print the Sudoku grid
        v.printGrid();
        
        // Verify whether or not the solution is correct
        if (v.verifySolution())
            cout << "\nThis is a valid Sudoku solution\n";
        else
            cout << "\nThis is not a valid Sudoku solution\n";
    }
    
    return 0;
}