/*********************************************************************
 PROGRAM:    Vector.cpp
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   10/28/2014
 
 FUNCTION:   This program tests the functionality of the Vector
 class.
 *********************************************************************/

#include <iostream>
#include <iomanip>
#include <cassert>
#include "Vector.h"

/**************************************************************
 
 FUNCTION: Vector::Vector()
 
 ARGUMENTS: The default constructor set the vector size and vector 
            capacity to 0 and the vector array to NULL
 
 RETURNS: N/A.
 
 NOTES:  Assign the method parameters to the corresponding data members.
 
 **************************************************************/
Vector::Vector()
{
    vsize = 0;
    vcapacity = 0;
    vectorarray = NULL;
}

/**************************************************************
 
 FUNCTION: Vector::~Vector()
 
 ARGUMENTS: The default destructor that deletes the dynamic 
            memory for the vector array
 
 RETURNS: N/A.
 
 NOTES:   Deletes the dynamicmemory for the vector array.
 
 **************************************************************/
Vector::~Vector()
{
    delete [] vectorarray;
}

/**************************************************************
 
 FUNCTION: Vector::Vector(const Vector &vectorToCopy)
 
 ARGUMENTS: The copy constructor
 
 RETURNS: N/A.
 
 NOTES:   Copies the vector array.
 
 **************************************************************/
Vector::Vector(const Vector &vectorToCopy)
{
    vcapacity = vectorToCopy.vcapacity;
    
    vsize = vectorToCopy.vsize;
    
    vectorarray = new int[vcapacity];
    //assert( vectorarray != 0 );
    
    for(int sub = 0; sub < vcapacity; sub++)
        vectorarray[sub] = vectorToCopy.vectorarray[sub];
}

/**************************************************************
 
 FUNCTION: const Vector& Vector::operator=(const Vector &rightOp)
 
 ARGUMENTS: This method overloads one Vector object to be 
            assigned to another object.
 
 RETURNS: *this.
 
 NOTES:   Assigns one vector abject to another.
 
 **************************************************************/
const Vector& Vector::operator=(const Vector &rightOp)
{
    if(this != &rightOp)
    {
        vcapacity = rightOp.vcapacity;
        
        vsize = rightOp.vsize;
        
        vectorarray = new int[vcapacity];
        //assert(vectorarray != 0 );
        
        for(int sub = 0; sub < vcapacity; sub++)
            vectorarray[sub] = rightOp.vectorarray[sub];
    }
    return *this;
}

/**************************************************************
 
 FUNCTION: void Vector::clear()
 
 ARGUMENTS: This method only sets the vector size to 0.
 
 RETURNS: N/A.
 
 NOTES:   Sets Vector size to 0.
 
 **************************************************************/
void Vector::clear()
{
    vsize = 0;
}

/**************************************************************
 
 FUNCTION: int Vector::size() const
 
 ARGUMENTS: This method returns the vector size.
 
 RETURNS: Vector size.
 
 NOTES:   Returns the data member vector size.
 
 **************************************************************/
int Vector::size() const
{
    return vsize;
}

/**************************************************************
 
 FUNCTION: int Vector::capacity() const
 
 ARGUMENTS: This method returns the vector capacity.
 
 RETURNS: Vector capacity.
 
 NOTES:   Returns the data member vector capacity.
 
 **************************************************************/
int Vector::capacity() const
{
    return vcapacity;
}

/**************************************************************
 
 FUNCTION: int Vector::enpty() const
 
 ARGUMENTS: This method returns the vector capacity.
 
 RETURNS: True if size is equal to 0 and false if not true.
 
 NOTES:   This method returns true if the vector size is equal to 0;
          otherwise returns false.
 
 **************************************************************/
bool Vector::empty() const
{
    bool status;
    if (vsize == 0)
        status = true;
    else
        status = false;
    return status;
}

/**************************************************************
 
 FUNCTION: int Vector::front() const
 
 ARGUMENTS: This method returns the first element of the vector array.
 
 RETURNS: First element of the vector array.
 
 NOTES:   This method returns the first element of the vector array.
 
 **************************************************************/
int Vector::front() const
{
    return vectorarray[0];
}

/**************************************************************
 
 FUNCTION: int Vector::back() const
 
 ARGUMENTS: This method returns the last element of the vector array.
 
 RETURNS: Last element of the vector array.
 
 NOTES:   This method returns the last element of the vector array.
 
 **************************************************************/
int Vector::back() const
{
    return vectorarray[vsize -1];
}

/**************************************************************
 
 FUNCTION: void Vector::push_back(int item)
 
 ARGUMENTS: This method checks if the vector is full also calls 
 the reserve() method to increase the capacity of the vector array.
 If the vector capacity is equal 0 then pass a new capacity of 1 
 to the reserve() method. Otherwise, pass a new capacity of twice 
 the current vector capacity to the reserve() method.
 
 RETURNS: N/A.
 
 NOTES:   This method increase the vector array if vector array is full.
        Then passes it the reserve() method.
 
 **************************************************************/
void Vector::push_back(int item)
{
    //Checks to see if Size and Capacity are equal.
    if (vsize == vcapacity)
    {
        //Checks to see if Capacity is equal 0 and sets it to 1.
        if (vcapacity == 0) //
         {
         vcapacity = 1;
         reserve(vcapacity);
         }
        ///Sets capacity to twice the current vector capacity.
         else
         {
         vcapacity = vcapacity * 2;
         reserve(vcapacity);
         }
    }
    //Passes in the new item and increments size by 1.
    vectorarray[vsize] = item;
    vsize++;
}

/**************************************************************
 
 FUNCTION: void Vector::pop_back()
 
 ARGUMENTS: This method decrement the vector size by 1.
 
 RETURNS: N/A.
 
 NOTES:   Removes the last item from the vector array.
 
 **************************************************************/
void Vector::pop_back()
{
   //Decrements size by 1.
       --vsize;
}

/**************************************************************
 
 FUNCTION: void Vector::reserve(int newCapacity)
 
 ARGUMENTS: This method increases the capacity of the vector array.
 
 RETURNS: N/A.
 
 NOTES:   This method increases the capacity of the vector array.
 
 **************************************************************/
void Vector::reserve(int newCapacity)
{
    
    vcapacity = newCapacity;
    // declares and assigns temparray with newCapacity
    int * temparray = new int[vcapacity];
  
    for(int sub = 0; sub < vsize; sub++)
    // Copies vectorarray to temparray
        temparray[sub] = vectorarray[sub];
    // Deletes vector array.
        delete [] vectorarray;
    // Copies temparray to vectorarray with newCapacity
        vectorarray = temparray;
}

/**************************************************************
 
 FUNCTION: int Vector::operator[](int sub) const
 
 ARGUMENTS: This method returns the element of the vector array at subscript sub.
 
 RETURNS: Vector array at subscript sub.
 
 NOTES:   Returns the element of the vector array at subscript sub.
 
 **************************************************************/
int Vector::operator[](int sub) const
{
    return vectorarray[sub];
}

/**************************************************************
 
 FUNCTION: int & Vector::operator[](int sub)
 
 ARGUMENTS: This method returns the element of the vector array at subscript sub.
 
 RETURNS: Vector array at subscript sub.
 
 NOTES:   Returns the element of the vector array at subscript sub.
 
 **************************************************************/
int & Vector::operator[](int sub)
{
    return vectorarray[sub];
}

/**************************************************************
 
 FUNCTION: bool Vector::operator==(const Vector &rightOp) const
 
 ARGUMENTS: This method compares two Vector objects and returns 
            true if the Vector objects are equal; otherwise, it 
            should return false.
 
 RETURNS: Return true if the Vector objects are equal; 
          otherwise, it should return false.
 
 NOTES:   Return true if the Vector objects are equal;
          otherwise, it should return false.
 
 **************************************************************/
bool Vector::operator==(const Vector &rightOp) const
{
 bool result = false;
 
    if(vsize != rightOp.vsize)
        result = false;
    else
        for(int sub = 0; sub < vsize; sub++)
            if (vectorarray[sub] != rightOp.vectorarray[sub])
                result = false;
            else
                result = true;
 
 return result;
}

/**************************************************************
 
 FUNCTION: ostream & operator<<(ostream & output, const Vector & rightOp)
 
 ARGUMENTS: output - is output stream object to write to.
 rightOp  - Vector object to insert into the output stream.
 
 RETURNS: The updated output stream object.
 
 NOTES: Inserts the Vector object into the output stream.
 
 **************************************************************/
ostream & operator<<(ostream & output, const Vector & rightOp)
{
    // Print the vector array at subscript sub.
    for( int sub = 0; sub < rightOp.vsize; sub++ )
    {
        output << rightOp.vectorarray[sub] << "  ";
        
    }
    // Return the updated output stream object.
    return output;
}