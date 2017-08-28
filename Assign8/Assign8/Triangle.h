/*********************************************************************
 PROGRAM:    Triangle.h file
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   12/4/2014
 
 FUNCTION:   This program builds STL vector of pointers to Shape objects.
 *********************************************************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>

using namespace std;

//Derived Triangle Class
class Triangle: public Shape
{
protected:
    //Data members
    int height, base;
    
public:
    //Function Methods
    Triangle(string, int, int);
    void print();
    virtual double get_area();
};

//Function Definitions.
/**************************************************************
 
 FUNCTION: Triangle::Triangle(string Color, int h, int b): Shape(color)
 
 ARGUMENTS:The function initialize the triangle's color and two ints 
            to initialize the triangle's height and base.
 
 RETURNS: N/A.
 
 NOTES:   The function initialize the triangle's color and two ints 
          to initialize the triangle's height and base.
 
 **************************************************************/
Triangle::Triangle(string Color, int h, int b): Shape(color)
{
    color = Color;
    height = h;
    base = b;
}

/**************************************************************
 
 FUNCTION: void Triangle::print()
 
 ARGUMENTS:The function call the base class print() method to print
            the color, then print the word "triangle" followed by the
            triangle's height, base, and area
 
 RETURNS: N/A.
 
 NOTES:   The function call the base class print() method to print 
          the color, then print the word "triangle" followed by the 
          triangle's height, base, and area.
 
 **************************************************************/
void Triangle::print()
{
    cout << color << " Triangle, Height " << height << ", Base " << base << ", Area " << get_area() << endl;
}

/**************************************************************
 
 FUNCTION: double Triangle::get_area()
 
 ARGUMENTS: The function initialize the triangle's color and two ints
            to initialize the triangle's height and base
 
 RETURNS: A double the area of the Triangle.
 
 NOTES:   The function Calculates the area of a triangle.
 **************************************************************/
double Triangle::get_area()
{
    return (height * base / 2);
}

#endif /* TRIANGLE_H */