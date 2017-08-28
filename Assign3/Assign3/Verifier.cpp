/*
//  Verifier.cpp
//  Assign2
//
//  Created by Abe Rodriguez on 9/23/14.
//  Copyright (c) 2014 ___AbeRodriguez___. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Verifier.h"

using namespace std;


***************************************************************
 FUNCTION: verifier()
 
 USE: Initializes the data members of a verifier object to the
 supplied arguments.
 
 ARGUMENTS: 1. sets the grid array to 0.
 ***************************************************************/

/*Verifier::Verifier()
{
    int grid[9][9];
    
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            grid[i][j] = 0;
            cout << grid[i][j] << " ";
        }
    }
}

***************************************************************
 FUNCTION: readGrid()
 
 USE: Initializes the data members of a readGrid object to the
 supplied arguments.
 
 ARGUMENTS: 1. Stores the input file.
 ***************************************************************/
/*char* Verifier::readGrid(const char* filename)
{
    ifstream inFile;
    //string file;
   char grid[9][9];
    
    inFile.open(filename, ios::binary);
    
    if (inFile.is_open())
    {
        //inFile >> grid;
        for (int i = 0; i < 9; i++)
        {
            
            for (int j = 0; j < 9; j++)
            {
                inFile >> grid[i][j];
                cout << grid[i][j] << " ";
            }
        }
        }
    //int newgrid[i][j] = inFile;
    inFile.close(); //Closes the file when done.
    return 0;
}

**************************************************************
 FUNCTION: printGrid()
 
 USE: Initializes the data members of a printGrid object to the
 supplied arguments.
 
 ARGUMENTS: 1. prints out the Sudoko Puzzle in a 9X9 table.
 ***************************************************************
void Verifier::printGrid()
{
   //char grid[9][9];
   //readGrid(grid);
            cout << "\n+-+-+--+--+-+--+--+-+-+";
    for (int i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6){
            cout << endl;
            cout << "+-+-+--+--+-+--+--+-+-+";}
        cout << " " << endl;
        
        
        for (int j = 0; j < 9; j++)
        {
            if (j == 3 || j == 6){
                cout << " |";}
            cout << " ";// only display this when j is 3 or 6
                //cout << "\n";
                //cout << "\t+---+---+---+---+---+---+---+---+---+" << endl;
            
            cout << grid[i][j].print();
            
        }
        
    }
    cout << "\n+-+-+--+--+-+--+--+-+-+" << endl;
}

**************************************************************
 FUNCTION: verifySolution()
 
 USE: Initializes the data members of a verifySolution object to the
 supplied arguments.
 
 ARGUMENTS: 1. Returns true for a valid puzzle
 2. Returns false for an invalid puzzle
 ***************************************************************
bool Verifier::verifySolution()
{

 int i =0, j =0;
    bool status;
    status = true;
    
    //Checks the Columns if invalied returns false
    for (int column = 0; column < 9; column++)
        if (column != j && grid[i] [column] == grid[i] [j])
            status = false;

    //Checks the Rows if invalied returns false
    for (int row = 0; row < 9; row++)
        if (row != i && grid[row] [j] == grid[i] [j])
            status = false;
    
    //Checks the 3 X 3 Array if invalied returns false
    for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++)
        for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++)
            if (row != i && col != j && grid[row] [col] == grid[i] [j])
                status = false;
    
    //
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (grid[i][j] != 0)
                status = false;
    
    //
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if ((grid[i][j] < 0) || (grid[i][j] > 9))
                status = false;
    
    return status;  //Returns status true or false.
}*/




#include "Verifier.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;


// Default Construct

Verifier::Verifier()
{
    grid[0][0] = '\0';
}

/***********************************************************
 readGrid() method:
 Description:
 ***********************************************************/

void Verifier::readGrid(const char* filename)
{
    ifstream inFile(filename);
    
  
    while (!inFile.eof())
    {
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                inFile >> grid[i][j];
                
            }
        }
    }
    inFile.close(); //Closes the file when done.
}

/***************************************************************
 FUNCTION: printGrid()
 
 USE: Initializes the data members of a printGrid object to the
 supplied arguments.
 
 ARGUMENTS: 1. prints out the Sudoko Puzzle in a 9X9 table.
 ***************************************************************/
void Verifier::printGrid()
{
    cout << "\n+-+-+--+--+-+--+--+-+-+";
    for (int i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6){
            cout << endl;
            cout << "+-+-+--+--+-+--+--+-+-+";}
        cout << " " << endl;
        
        
        for (int j = 0; j < 9; j++)
            {
            if (j == 3 || j == 6){
                cout << " |";
            }
            cout << " ";// only display this when j is 3 or 6
            
            cout << grid[i][j];
    }
}
}
/***********************************************************
 verifyGrid() method:
 Description:
 ***********************************************************/

bool Verifier::verifySolution()
{
    int columnCheck=0;
    int rowCheck=0;
    int blockCheck=0;
    int ctr=0;
    bool status;
    
    // Verify Columns
    
    for (int b=0; b < 9; b=b+3)
    {
        for (int r = 0; r < 9; r++)
        {
            
            for (int c=0; c < 9; c++)
            {
                columnCheck=columnCheck+grid[r][c];
                if (c==8&&columnCheck==45)
                    status=true;
                else if (c==8&&columnCheck != 45)
                    return false;
            }
            
            if (columnCheck==45)
                columnCheck=0;
        }
        
    }
    
    // Verify Rows
    
    for (int b=0; b < 9; b=b+3)
    {
        for (int c=0; c < 9; c++)
        {
            
            for (int r = 0; r < 9; r++)
            {
                rowCheck=rowCheck+grid[r][c];
                
                if (r==8 && rowCheck==45)
                    status=true;
                else if (r==8&&rowCheck != 45)
                    return false;
                if(grid[r][c]==grid[r+1][c])
                    return false;
            }
            
            if (rowCheck==45)
                rowCheck=0;
        }
    }
    
    // Verify 3x3 Blocks
    
    int row=3;
    int col=9;
    int rs = 0;
    int cs = 0;
    for (int b=0; b < 9; b=b+3)
    {
        
        
        for (int c=cs; c < col; c++)
        {
            
            for (int r=rs;r < row; r++)
            {
                if (ctr>27&&ctr<55)
                {
                    row=6;
                    rs=3;
                }
                if (ctr>58)
                {
                    row=9;
                    rs=6;
                }
                
                ctr=ctr+1;
                
                
                if (ctr<28||(ctr<58&&ctr>30)||ctr>60)
                {
                    blockCheck=blockCheck+grid[r][c];
                    
                    if ((ctr==9||ctr==18||ctr==27||ctr==39||ctr==48||ctr==57||ctr==69||ctr==78||ctr==87) && blockCheck==45)
                        status=true;
                    
                    if ((ctr==9||ctr==18||ctr==27||ctr==39||ctr==48||ctr==57||ctr==69||ctr==78||ctr==87) && blockCheck!=45)
                        return false;
                }
                
                
                if (blockCheck==45)
                    blockCheck=0;
            }
        }  
    }  
    return status;
    
}

