/*********************************************************************
 PROGRAM:    CSCI 241 mergesort.h file
 PROGRAMMER:
 LOGON ID:
 DUE DATE:   11/20/2014
 
 FUNCTION:   This program builds and sorts lists using the quick
 sort and merge sort algorithms.
 *********************************************************************/

#ifndef MERGESORT_H
#define MERGESORT_H

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
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&));
template <class T>
void mergeSort(vector<T>& set, int, int, bool (*compare)(const T&, const T&));
template <class T>
void merge(vector<T>& set, int, int, int, bool (*compare)(const T&, const T&));

//Function Definitions
/**************************************************************
 
 FUNCTION: void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: This function sort the items in the vector set using 
            the merge sort algorithm.
 
 RETURNS: N/A.
 
 NOTES:   This function calls the recursive merge sort function, 
        passing it the vector, the subscript of the first vector 
        element, the subscript of the last vector element, and the 
        pointer to the comparison function.
 
 **************************************************************/
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
 mergeSort(set, 0, (int)set.size()-1, compare);
}

/**************************************************************
 
 FUNCTION: void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: This recursive function divides a vector into two subvectors, 
            sorts them, and then merges the two sorted subvectors.
 
 RETURNS: N/A.
 
 NOTES:   Function divides a vector into two subvectors,sorts them, 
        and then merges the two sorted subvectors.
 
 **************************************************************/
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        
        // Divide and conquer
        mergeSort(set, low, mid, compare);
        mergeSort(set, mid+1, high, compare);
        
        // Combine
        merge(set, low, mid, high, compare);
    }
}

/**************************************************************
 
 FUNCTION: void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
 
 ARGUMENTS: The function merges the two sorted subvectors.
 
 RETURNS: N/A.
 
 NOTES:   This function merges the two sorted subvectors..
 
 **************************************************************/
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
    // Create temporary vector to hold merged subvectors
    vector<T> temp(high - low + 1);
    
    int i = low;      // Subscript for start of left sorted subvector
    int j = mid+1;    // Subscript for start of right sorted subvector
    int k = 0;        // Subscript for start of merged vector
    
    // While not at the end of either subvector
    while (i <= mid && j <= high)
    {
        if (compare(set[j], set[i]))
        {
            temp[k++] = set[j++];  //Copy element j of set into element k of temp
        }
        else
        {
            temp[k++] = set[i++];    //Copy element i of set into element k of temp
        }
    }
    
    // Copy over any remaining elements of left subvector
    while (i <= mid)
    {
        temp[k++] = set[i++];    //Copy element i of set into element k of temp
    }
    
    // Copy over any remaining elements of right subvector
    while (j <= high)
    {
        temp[k++] = set[j++];      //Copy element j of set into element k of temp
    }
    
    // Copy merged elements back into original vector
    for (i = 0, j = low; j <= high; i++, j++)
       set[j] = temp[i];  //Copy element i of temp into element j of set
}
#endif /* END MERGESORT_H */