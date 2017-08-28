#ifndef VERIFIER_H
#define VERIFIER_H

//*****************************************************************
// FILE:      Verifier.h
// AUTHOR:    Abe Rodriguez
// LOGON ID:  Z1758468
// DUE DATE:  9/26/2014
//
// PURPOSE:   Contains the declaration for the Verifier class.
//*****************************************************************

class Verifier
{
private:
    
    // Data members for the Book class go here.
    int grid [9][9];
    
    // Method prototypes for the Book class go here
public:
    
    Verifier();
    void readGrid(const char*);
    void printGrid();
    bool verifySolution();
    
};
#endif      //#include "Verifier.h"




