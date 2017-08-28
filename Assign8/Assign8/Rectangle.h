/*********************************************************************
 PROGRAM:    Rectangle.h file
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   12/4/2014
 
 FUNCTION:   This program builds STL vector of pointers to Shape objects.
 *********************************************************************/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

using namespace std;

//Derived Rectangle Class
class Rectangle: public Shape
{
protected:
    //Data members
    int height, width;
    
public:
    //Function Methods
    Rectangle(string, int, int);
    void print();
    virtual double get_area();
};

//Function Definitions.
/**************************************************************
 
 FUNCTION: Rectangle::Rectangle(string Color, int h, int w): Shape(color)
 
 ARGUMENTS:The function initialize the Rectangle's color and two ints
 to initialize the Rectangle's height and width.
 
 RETURNS: N/A.
 
 NOTES:   The function initialize the Rectangle's color and two ints
 to initialize the Rectangle's height and width.
 
 **************************************************************/
Rectangle::Rectangle(string Color, int h, int w): Shape(color)
{
    color = Color;
    height = h;
    width = w;
}

/**************************************************************
 
 FUNCTION: void Rectangle::print()
 
 ARGUMENTS:The function call the base class print() method to print
            the color, then print the word "rectangle" followed by the
            rectangle's height, width, and area
 
 RETURNS: N/A.
 
 NOTES:   The function call the base class print() method to print
          the color, then print the word "rectangle" followed by the
          triangle's height, width, and area.
 
 **************************************************************/
void Rectangle::print()
{
    cout << color << " Rectangle, Height " << height << ", Width " << width << ", Area " << get_area() << endl;
}

/**************************************************************
 
 FUNCTION: double Rectangle::get_area()
 
 ARGUMENTS: The function initialize the rectangle's color and two ints
 to initialize the rectangle's height and base
 
 RETURNS: The Area of the Rectangle.
 
 NOTES:   The function Calculates the area of a rectangle.
 **************************************************************/
double Rectangle::get_area()
{
    return (height * width);
}

#endif /* RECTANGLE_H */