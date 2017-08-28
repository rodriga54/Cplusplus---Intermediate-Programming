/*********************************************************************
 PROGRAM:    Circle.h file
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   12/4/2014
 
 FUNCTION:   This program builds STL vector of pointers to Shape objects.
 *********************************************************************/

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

using namespace std;

//Derived Rectangle Class
class Circle: public Shape
{
protected:
    //Data members
    int radius;
    
public:
    //Function Methods
    Circle(string, int);
    void print();
    virtual double get_area();
};

//Function Definitions.
/**************************************************************
 
 FUNCTION: Circle::Circle(string Color, int r): Shape(color)
 
 ARGUMENTS:The function initialize the circle's color and an int 
               to initiallize the circle's radius.
 
 RETURNS: N/A.
 
 NOTES:   The function initialize the circle's color and an int
          to initiallize the circle's radius.
 
 **************************************************************/
Circle::Circle(string Color, int r): Shape(color)
{
    color = Color;
    radius = r;
}

/**************************************************************
 
 FUNCTION: void Circle::print()
 
 ARGUMENTS:The function calls the base class print() method to 
            print the color, then print the word "circle" followed 
            by the circle's radius and area
 
 RETURNS: N/A.
 
 NOTES:   The function call the base class print() method to print 
          the color, then print the word "circle" followed by the 
          circle's radius and area.
 
 **************************************************************/
void Circle::print()
{
    cout << color << " Circle, Radius " << radius << ", Area " << get_area() << endl;
}

/**************************************************************
 
 FUNCTION: double Circle::get_area()
 
 ARGUMENTS: The function initialize the rectangle's color and two ints
            to initialize the rectangle's height and base
 
 RETURNS: The Area of the Circle.
 
 NOTES:   The function Calculates the circle's area based on its radius.
 **************************************************************/
double Circle::get_area()
{
    return (radius * radius * 3.14159265);
}

#endif /* CIRCLE_H */