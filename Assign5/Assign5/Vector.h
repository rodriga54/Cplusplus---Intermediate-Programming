/*********************************************************************
 PROGRAM:    Vector.h 
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   10/28/2014
 
 FUNCTION:   This program tests the functionality of the Vector
 class.
 *********************************************************************/

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

using namespace std;

class Vector
{
    // Overload the stream extraction operators as standalone
    // functions - can't be done as methods
friend ostream & operator<<(ostream &leftOp, const Vector &rightOp);

private:
    //Private Data members
    int *vectorarray;
    int vsize, vcapacity;
    
public:
    //Public methods/functions
    Vector();
    ~Vector();
    Vector(const Vector&);
    const Vector& operator=(const Vector& rightOp);
    void clear();
    int size() const;
    int capacity() const;
    bool empty() const;
    int front() const;
    int back() const;
    void push_back(int item);
    void pop_back();
    void reserve(int);
    int operator[](int) const;
    int&  operator[](int);
    bool operator==(const Vector&) const;
};
#endif
