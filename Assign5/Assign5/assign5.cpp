/*********************************************************************
 PROGRAM:    CSCI 241 Assignment 5
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   10/28/2014
 
 FUNCTION:   This program tests the functionality of the Vector
 class.
 *********************************************************************/

#include <iostream>
#include "Vector.h"

using std::cout;
using std::endl;

int main()
{
    cout << "Testing default constructor\n\n";
    
    Vector v1;
    
    cout << "v1: " << v1 << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 is " << ((v1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing push_back()\n\n";
    
    for (int i = 10; i < 200; i+= 10)
        v1.push_back(i);
    
    cout << "v1: " << v1 << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 is " << ((v1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing pop_back()\n\n";
    
    for (int i = 0; i < 3; ++i)
    {
        v1.pop_back();
    }
    
    cout << "v1: " << v1 << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 is " << ((v1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing copy constructor()\n\n";
    
    Vector v2 = v1;
    
    cout << "v1: " << v1 << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 is " << ((v1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "v2: " << v2 << endl;
    cout << "v2 size: " << v2.size() << endl;
    cout << "v2 capacity: " << v2.capacity() << endl;
    cout << "v2 is " << ((v2.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing front() and back()\n\n";
    
    cout << "Front item of v1: " << v1.front() << endl;
    cout << "Front item of v2: " << v2.front() << endl << endl;
    
    cout << "Rear item of v1: " << v1.back() << endl;
    cout << "Rear item of v2: " << v2.back() << endl << endl;
    
    cout << "v1: " << v1 << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 is " << ((v1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "v2: " << v2 << endl;
    cout << "v2 size: " << v2.size() << endl;
    cout << "v2 capacity: " << v2.capacity() << endl;
    cout << "v2 is " << ((v2.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing pop() to empty\n\n";
    
    while (!v1.empty())
    {
        cout << v1.back() << ' ';
        v1.pop_back();
    }
    
    cout << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 is " << ((v1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing assignment operator\n\n";
    
    Vector v3;
    
    v3 = v2;
    
    cout << "v2: " << v2 << endl;
    cout << "v2 size: " << v2.size() << endl;
    cout << "v2 capacity: " << v2.capacity() << endl;
    cout << "v2 is " << ((v2.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "v3: " << v3 << endl;
    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 capacity: " << v3.capacity() << endl;
    cout << "v3 is " << ((v3.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    Vector v4;
    
    v3 = v4;
    
    cout << "v3: " << v3 << endl;
    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 capacity: " << v3.capacity() << endl;
    cout << "v3 is " << ((v3.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "v4: " << v4 << endl;
    cout << "v4 size: " << v4.size() << endl;
    cout << "v4 capacity: " << v4.capacity() << endl;
    cout << "v4 is " << ((v4.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    v3 = v2;
    
    cout << "v3: " << v3 << endl;
    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 capacity: " << v3.capacity() << endl;
    cout << "v3 is " << ((v3.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing clear()\n\n";
    
    v2.clear();
    
    cout << "v2 (size " << v2.size() << "): " << v2 << endl;
    cout << "v3 (size " << v3.size() << "): " << v3 << endl << endl;
    
    cout << "Testing assignment to self and swap\n\n";
    
    v3 = v3;
    v2 = v3;
    v3.clear();
    
    cout << "v2 (size " << v2.size() << "): " << v2 << endl;
    cout << "v3 (size " << v3.size() << "): " << v3 << endl << endl;
    
    cout << "Testing chained assignment\n\n";
    
    Vector v5;
    
    v5 = v3 = v2;
    
    cout << "v2 (size " << v2.size() << "): " << v2 << endl;
    cout << "v3 (size " << v3.size() << "): " << v3 << endl;
    cout << "v5 (size " << v5.size() << "): " << v5 << endl << endl;
    
    cout << "Testing write version of subscript operator\n\n";
    
    for (int i = 0; i < v5.size(); ++i)
        v5[i] += 5;
    
    cout << "v5 (size " << v5.size() << "): " << v5 << endl << endl;
    
    cout << "Testing read version of subscript operator\n\nv5: ";
    
    for (int i = 0; i < v5.size(); ++i)
        cout << v5[i] << ' ';
    cout << endl << endl;
    
    cout << "Testing const correctness\n\n";
    
    const Vector& r5 = v5;
    
    cout << "v5: " << r5 << endl;
    cout << "v5 size: " << r5.size() << endl;
    cout << "v5 capacity: " << r5.capacity() << endl;
    cout << "v5 is " << ((r5.empty()) ? "empty\n" : "not empty\n");
    cout << "Front item of v5: " << r5.front() << endl;
    cout << "Rear item of v5: " << r5.back() << endl;
    cout << "4th item of v5: " << r5[3] << endl << endl;
    
    v1 = r5;
    
    cout << "v1: " << v1 << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 is " << ((v1.empty()) ? "empty\n" : "not empty\n");
    cout << endl;
    
    cout << "Testing equality operator\n\n";
    
    cout << "v1 and v5 are " << ((v1 == r5) ? "equal\n" : "not equal\n");
    cout << "v5 and v3 are " << ((r5 == v3) ? "equal\n" : "not equal\n");
    cout << "v1 and v2 are " << ((v1 == v2) ? "equal\n" : "not equal\n");
    v5.pop_back();
    cout << "v1 and v5 are now " << ((v1 == v5) ? "equal\n" : "not equal\n");
    
    return 0;
}
