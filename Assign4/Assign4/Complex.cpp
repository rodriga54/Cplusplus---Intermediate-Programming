/*********************************************************************
PROGRAM:    Complex.cpp
PROGRAMMER: Abraham Rodriguez
LOGON ID:   Z1758468
DUE DATE:   10/17/2014

FUNCTION:   This program tests the functionality of the Complex
class.
*********************************************************************/

#include <iostream>
#include <iomanip>
#include "Complex.h"

using namespace std;

/**************************************************************
 
 FUNCTION: Complex::Complex(double real, double imagine)
 
 ARGUMENTS: The constructor should take two double variables as 
            arguments, representing the real and imaginary parts 
            of a complex number. Give the two parameters the 
            default value 0 in the prototype for the constructor 
            (which will allow this constructor to double as a 
            "default" constructor).
 
 RETURNS: N/A.
 
 NOTES:  Assign the method parameters to the corresponding data members.
 
 **************************************************************/

Complex::Complex(double nreal, double nimaginary)
{
    real = nreal;
    imaginary = nimaginary;
    
}

/**************************************************************
 
 FUNCTION: Complex::setComplex(double real, double imagine)
 
 ARGUMENTS: This method takes two double variables as arguments, 
            representing the real and imaginary parts of a complex 
            number.
 
 RETURNS: N/A.
 
 NOTES: Assign the method parameters to the corresponding data members.
 
 **************************************************************/
void Complex::setComplex(double nreal, double nimaginary)
{
    real = nreal;
    imaginary = nimaginary;
}

/**************************************************************
 
 FUNCTION: Complex::getComplex(double real, double imaginary) const
 
 ARGUMENTS: This method takes two references to double variables as 
            arguments, representing the real and imaginary parts 
            of a complex number.
 
 RETURNS: N/A.
 
 NOTES: Assign the data members to the corresponding method parameters. 
        This lets us pass back the value of both parts of the complex 
        number with a single method call.
 **************************************************************/
double Complex::getComplex( double &nreal, double &nimaginary)const
{
    return (nreal = real), (nimaginary = imaginary);
    
}

/**************************************************************
 
 FUNCTION: Complex::setRealPart(double real)
 
 ARGUMENTS: A double, representing the real part of a complex number.
 
 RETURNS: N/A.
 
 NOTES: Assign the method parameter to the real part data member 
        of the object that called the method.
 
 **************************************************************/
void Complex::setRealPart(double nreal)
{
   real = nreal;
}

/**************************************************************
 
 FUNCTION: Complex::getRealPart() const
 
 ARGUMENTS: None.
 
 RETURNS: The real part of the complex number (a double).
 
 NOTES: Return the data member representing the real part of the 
        complex number.
 
 **************************************************************/
double Complex::getRealPart()const
{
    return real;
}

/**************************************************************
 
 FUNCTION: Complex::setImaginaryPart(double imagine)
 
 ARGUMENTS: A double, representing the imaginary part of a complex number.
 
 RETURNS: N/A.
 
 NOTES: Assign the method parameter to the imaginary part data 
        member of the object that called the method.
 
 **************************************************************/
void Complex::setImaginaryPart(double nimaginary)
{
    imaginary = nimaginary;
}

/**************************************************************
 
 FUNCTION: double Complex::getImaginaryPart() const
 
 ARGUMENTS: None.
 
 RETURNS: The imaginary part of the complex number (a double).
 
 NOTES: Return the data member representing the imaginary part 
        of the complex number.
 
 **************************************************************/
double Complex::getImaginaryPart() const
{
    return imaginary;
}

/**************************************************************
 
 FUNCTION: Complex Complex::operator+(const Complex & rightOp)const
 
 ARGUMENTS: rightOp - a Complex object operand.
 
 RETURNS: The sum of the two operands.
 
 NOTES: Adds two Complex objects and returns the result.
 
 **************************************************************/
Complex Complex::operator+(const Complex & rightOp)const
{
    Complex result;
    
    result.real = (real + rightOp.real);
    result.imaginary = (imaginary + rightOp.imaginary);
    
    return result;
}

/**************************************************************
 
 FUNCTION: Complex Complex::operator*(const Complex & rightOp) const
 
 ARGUMENTS: rightOp - a Complex object operand.
 
 RETURNS: The multiply of the two operands.
 
 NOTES: Multiplies two Complex objects and returns the result.
 
 **************************************************************/
Complex Complex::operator*(const Complex & rightOp) const
{
    // Declare a temporary object to hold the result and set it
    Complex result = rightOp;

    // Multiply the left operand by the right operand in ordered pair notation.
    result.real = ((rightOp.real * real) - (rightOp.imaginary * imaginary));
    result.imaginary = ((imaginary * rightOp.real) + (real * rightOp.imaginary));
 
    // Return the result
    return result;
}

/**************************************************************
 
 FUNCTION: bool Complex::operator==(const Complex & rightOp)const
 
 ARGUMENTS: rightOp - a Complex object operand.
 
 RETURNS: true if the operands are equal, otherwise false.
 
 NOTES: Compares two Complex objects.
 
 **************************************************************/
bool Complex::operator==(const Complex & rightOp)const
{
    Complex result; //declared object
    
    //Returns the result True or False
    return (result.real == rightOp.real && imaginary == rightOp.imaginary);
}

/**************************************************************
 
 FUNCTION: istream & operator>>(istream & input, Complex & rightOp)
 
 ARGUMENTS: input - input stream object to write to.
 rightOp  - Complex object in which to store values extracted 
 from the input stream.
 
 RETURNS: The updated input stream object.
 
 NOTES: Extracts two int values from the input stream and
 stores them into a Complex object.
 
 **************************************************************/
istream & operator>>(istream & input, Complex & rightOp)
{
    char ch; //declared char variable
   
    input >> ch >> rightOp.real >> ch >> rightOp.imaginary >> ch;
    
    // Returns the input object
    return input;
}

/**************************************************************
 
 FUNCTION: ostream & operator<<(ostream & output, const Complex & rightOp)
 
 ARGUMENTS: output - is output stream object to write to.
 rightOp  - Complex object to insert into the output stream.
 
 RETURNS: The updated output stream object.
 
 NOTES: Inserts the Complex object into the output stream.
 
 **************************************************************/
ostream & operator<<(ostream & output, const Complex & rightOp)
{
    // Print the real and imaginary
    output << "(" << rightOp.real << "," << rightOp.imaginary << ")";
    
    // Return the updated output stream object
    return output;
}