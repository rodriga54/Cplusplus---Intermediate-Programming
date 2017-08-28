/*********************************************************************
 PROGRAM:    CSCI 241 sorts.h file
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   11/20/2014
 
 FUNCTION:   This program builds and sorts lists using the quick
 sort and merge sort algorithms.
 *********************************************************************/

#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <vector>

using namespace std;
using std::ostream;
using std::cout;
using std::endl;
using std::ifstream;
using std::setw;
using std::vector;

//Function Prototypes
template <class T>
void buildList(vector<T>&, const char*);
template <class T>
void printList(const vector<T>&, int, int);
template <class T>
bool lessThan(const T&, const T&);
template <class T>
bool greaterThan(const T&, const T&);


 // Method definitions for the Stack class
/**************************************************************
 
 FUNCTION: void buildList(vector<T>& set, const char* fileName)
 
 ARGUMENTS: This function read items from an input file and put 
            them into a vector.
 
 RETURNS: N/A.
 
 NOTES:   The function first opens the files for input, then read 
        items from the file using the >> operator one at a time until 
        end of file, inserting them into the vector. Finally, it 
        should close the input file.
 
 **************************************************************/
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
    T item;
    ifstream infile;
    infile.open(fileName);

    if(!infile)
    {
        cout << "Error: Could not open file. " << fileName << endl;
        exit(1);
    }
    
    infile >> item;
 
while (infile)
    {
    set.push_back(item);
    
   // Read item from input file
    infile >> item;
    }
    infile.close();
}

/**************************************************************
 
 FUNCTION: void printList(const vector<T>& set, int itemWidth, int numPerLine)
 
 ARGUMENTS: This function prints the list of items stored in a vector.
 
 RETURNS: N/A.
 
 NOTES:  This function prints the list of items stored in a vector.
        The first argument to this function is a reference to a constant 
        vector object that will contain the items to print. The second 
        argument is an integer specifying the width an individual item 
        should occupy when printed. The third argument is an integer 
        specifying the maximum number of items that should be printed 
        in a single line of output.
 
 **************************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
    int i = 0;
    while (i < (int) set.size())
    {
    cout << setw(itemWidth) << right << set[i] << ' ';
    i ++;
        if (i % numPerLine == 0)
            cout << endl;
    }
    if (i % numPerLine != 0)
        cout << endl;
}

/**************************************************************
 
 FUNCTION: bool lessThan(const T& item1, const T& item2)
 
 ARGUMENTS: This function returns true if item1 is less than item2 
            and false if not.
 
 RETURNS: This function returns true if item1 is less than item2
            and false if not.
 
 NOTES:    This function returns true if item1 is less than item2
        and false if not.
 
 **************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
    {
    if (item1 < item2)
        return true;
    else
        return false;
    }

/**************************************************************
 
 FUNCTION: bool greaterThan(const T& item1, const T& item2)
 
 ARGUMENTS: This function returns true if item1 is greater
            than item2 and false if not.
 
 RETURNS: This function returns true if item1 is greater
        than item2 and false if not.
 
 NOTES:   This function returns true if item1 is greater
        than item2 and false if not.
 
 **************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2)
    {
    if (item1 > item2)
        return true;
    else
        return false;

    }
#endif   /* SORTS_H */
