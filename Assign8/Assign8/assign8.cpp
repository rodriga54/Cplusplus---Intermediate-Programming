

/*#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;

int main()
{
    
    Rectangle rect("Red",8,6);
    Rectangle rect1("Blue",3,7);
    Circle cir("Green",10);
    Circle cir1("Orange",5);
    Triangle tri ("Yellow", 8,4);
    Triangle tri1 ("Black", 4,10);
    
    Shape *shaperect = &rect;
    Shape *shaperect1 = &rect1;
    Shape *shapecir = &cir;
    Shape *shapecir1 = &cir1;
    Shape *shapetri = &tri;
    Shape *shapetri1 = &tri1;


    //dynamic_cast <Shape *> ()
    Shape *shapeAr = new Shape[6];
    
    shapeAr[0] = new Circle("Green",10);
    shapeAr[1] = new Rectangle("Red",8,6);
    shapeAr[2] = new Triangle("Yellow", 8,4);
    shapeAr[3] = new Triangle("Black", 4,10);
    shapeAr[4] = new Circle("Orange",5);
    shapeAr[5] = new Rectangle("Blue",3,7);
    
    Circle *cPtr1 = dynamic_cast<Circle *> (shapeAr[0]);
    
    if( cPtr1 == 0 )
        cout << "cast did not work";
    else
        cout << "cast worked";
    
    
    Circle *cPtr2 = dynamic_cast<Circle *> (shapeAr[1]);
    
    if( cPtr2 == 0 )
        cout << "cast did not work";
    else
        cout << "cast worked";
    

    cout << "Printing all Shapes..." << '\n' << '\n';

    shapecir->print();
    shaperect->print();
    shapetri->print();
 shapetri1->print(#include <typeinfo>
 #include <iomanip>
 #include <vector>
 #include <string>
 #include "shape.h"
 #include "triangle.h"
 #include "circle.h"
 #include "rectangle.h"
 #include <iostream>
 
 using std::cout;
 using std::endl;
 using std::vector;
 
 using namespace std;
 
 int main()
 {
 
 // creating STL vector of pointers to shape objects
 
 vector<Shape*> Shapes;
 
 // Dynamically create some Circles,Rectangles, and Triangles
 
 Shapes.push_back(new Circle("green", 10));
 Shapes.push_back(new Rectangle("red",8,6));
 Shapes.push_back(new Triangle("yellow",8,4));
 Shapes.push_back(new Triangle("black",4,10));
 Shapes.push_back(new Circle("orange",5));
 Shapes.push_back(new Rectangle("blue",3,7));
 
 // call the print method for each of them
 
 cout << "\nPrinting all shapes...\n" << endl;
 
 // loop through the shape pointers for each object while calling the print method
 
 for(unsigned int i=0; i < Shapes.size(); ++i)
 {
 Shapes[i]->print();
 }
 
 cout << "\nPrinting only circles...\n" << endl;
 
 for(unsigned int i = 0; i < Shapes.size(); ++i)
 {
 
 //downcast pointer
 Circle* cptr = dynamic_cast<Circle *>(Shapes[i]);
 
 //determine whether element points to the triangle
 if(cptr != NULL)
 {
 //type cast succeeded, tptr was pointing to a triangle object
 //can now safely call triangle-specific methods
 cptr->print();
 }
 }
 
 for(unsigned int i=0; i < Shapes.size(); ++i)
 {
 delete Shapes[i];
 }
 
 return 0;
 };
    shapecir1->print();
    shaperect1->print();
 
    cout << '\n' << '\n';
    cout << "Printing all Circles..." << '\n' << '\n';
    
    shapecir->print();
    shapecir1->print();
    
    return 0;
}*/


/*********************************************************************
 PROGRAM:    CSCI 241 Assignment 8
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   12/4/2014
 
 FUNCTION:   This program builds STL vector of pointers to Shape objects.
 *********************************************************************/

#include <vector>
#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

int main()
{
    // creating STL vector of pointers to shape objects
    vector<Shape*> Shapes;
    
    // Dynamically create some Circles, Rectangles, and Triangles
    Shapes.push_back(new Circle("Green", 10));
    Shapes.push_back(new Rectangle("Red",8,6));
    Shapes.push_back(new Triangle("Yellow",8,4));
    Shapes.push_back(new Triangle("Black",4,10));
    Shapes.push_back(new Circle("Orange",5));
    Shapes.push_back(new Rectangle("Blue",3,7));
    
    // call the print method for each of them
    cout << "\nPrinting all shapes...\n" << endl;
    
    // loop through the shape pointers for each object while calling the print method
    for(unsigned int i=0; i < Shapes.size(); ++i)
        {
        Shapes[i]->print();
        }
    
    cout << "\nPrinting only circles...\n" << endl;
    
    for(unsigned int i = 0; i < Shapes.size(); ++i)
    {
        //downcast pointer
        Circle* cptr = dynamic_cast<Circle *>(Shapes[i]);
        
        //determine whether element points to the triangle
        if(cptr != NULL)
            {
            //type cast succeeded, tptr was pointing to a triangle object
            //can now safely call triangle-specific methods
            cptr->print();
            }
    }
    
    for(unsigned int i=0; i < Shapes.size(); ++i)
        {
        //Deletes the contents
        delete Shapes[i];
        }
    
    return 0;
}
