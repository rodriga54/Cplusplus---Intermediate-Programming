/*********************************************************************
 PROGRAM:    CSCI 241 quicksort.h file
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   11/20/2014
 
 FUNCTION:   This program builds and sorts lists using the quick
 sort and merge sort algorithms.
 *********************************************************************/

#ifndef QUICKSORT_H
#define QUICKSORT_H

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
void quickSort(vector<T>&, bool (*compare)(const T&, const T&));
template <class T>
void quickSort(vector<T>&, int , int, bool (*compare)(const T&, const T&));
template <class T>
int partition(vector<T>&, int , int, bool (*compare)(const T&, const T&));


//Function Definitions
/**************************************************************
 
 FUNCTION: void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: This function should sort the items in the vector set 
            using the quick sort algorithm.
 
 RETURNS: N/A.
 
 NOTES:   This function calls the recursive quick sort function,
 passing it the vector, the subscript of the first vector
 element, the subscript of the last vector element, and the
 pointer to the comparison function.
 
 **************************************************************/
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
    quickSort(set, 0, (int) set.size()-1, compare);
}

/**************************************************************
 
 FUNCTION: void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: This function performs the recursive calls to implement 
            the quick sort algorithm
 
 RETURNS: N/A.
 
 NOTES:   This function performs the recursive calls to implement 
        the quick sort algorithm
 
 **************************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
    int pivotPoint;
    
    if (start < end)
    {
        pivotPoint = partition(set, start, end, compare);   // Get the pivot point
        quickSort(set, start, pivotPoint-1, compare);       // Sort first sublist
        quickSort(set, pivotPoint+1, end, compare);         // Sort second sublist
    }
}

/**************************************************************
 
 FUNCTION: int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: This function selects a pivot element and then partitions 
            the vector around the pivot.
 
 RETURNS: pivotValue.
 
 NOTES:   This function selects a pivot element and then partitions 
        the vector around the pivot.
 
 **************************************************************/template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
    int pivotIndex, mid;
    T pivotValue;
    
    mid = (start + end) / 2;
    
    //Swap elements start and mid of the vector
    swap (set[start],set[mid]);
    
    pivotIndex = start;
    pivotValue = set[start];
    
    for (int scan = start + 1; scan <= end; scan++)
    {
        if (compare(set[scan], pivotValue))
        {
            pivotIndex++;
            //Swap elements pivotIndex and scan of the vector
            swap(set[pivotIndex], set[scan]);
        }
    }
    
    //Swap elements start and pivotIndex of the vector
    swap(set[start], set[pivotIndex]);
    
    return pivotIndex;
}

#endif /* QUICKSORT_H */