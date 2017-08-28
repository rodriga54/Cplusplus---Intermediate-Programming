/*********************************************************************
 PROGRAM:    Shape.h file
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   12/4/2014
 
 FUNCTION:   This program builds STL vector of pointers to Shape objects.
 *********************************************************************/

#ifndef SHAPE_H
#define SHAPE_H

#include "Shape.h"
#include <iostream>

using namespace std;
using std::cout;

//Base Class also an abstract class
class Shape
{
protected:
    //Data members
    string color;
    
public:
    //Function Methods
    Shape (const string &color){}
    virtual ~Shape (){}
    virtual void print();
    virtual double get_area() = 0;
};

//Function Definitions.
/**************************************************************
 
 FUNCTION: void Shape::print()
 
 ARGUMENTS:The function print the color.
 
 RETURNS: N/A.
 
 NOTES:   The function print the color.
 
 **************************************************************/
void Shape::print()
{
    cout << color;
}
#endif /* SHAPE_H */
