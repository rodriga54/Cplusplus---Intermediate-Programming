/*********************************************************************
 PROGRAM:    Complex.h
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   10/17/2014
 
 FUNCTION:   This program tests the functionality of the Complex
 class.
 *********************************************************************/

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using namespace std;

class Complex
{
    // Overload the stream insertion and extraction operators as standalone
    // functions - can't be done as methods
    friend ostream & operator<<(ostream &, const Complex &);
    friend istream & operator>>(istream &, Complex &);
    
private:
    //Private Data members
    double real, imaginary;
public:
    //Public methods/functions
    Complex(double =0, double=0);
    void setComplex(double, double);
    double getComplex(double &, double &)const;
    void setRealPart(double);
    double getRealPart()const;
    void setImaginaryPart(double);
    double getImaginaryPart() const;
    Complex operator+(const Complex &)const;
    Complex operator*(const Complex &)const;
    bool operator==(const Complex &)const;
};
#endif
