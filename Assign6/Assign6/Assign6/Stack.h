/*********************************************************************
 PROGRAM:    CSCI 241 Assignment 6
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   11/13/2014
 
 FUNCTION:   This program tests the functionality of the Stack
 template class.
 *********************************************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

template <class T>
struct Node
{
    // data Members
    T data;
    Node<T> * next;
    Node(const T& = T(), Node<T>* next = NULL);
};

// Method definitions for the Node class
/**************************************************************
 
 FUNCTION: Node<T>::Node(const T& newData, Node<T>* newNext)
 
 ARGUMENTS: The constructor copies the argument into the stack 
            node and set the node's pointer to NULL.
 
 RETURNS: N/A.
 
 NOTES:   Copies the argument into the stack node and set the 
          node's pointer to NULL.
 
 **************************************************************/
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
{
    data = newData;
    next = newNext;
}

// Forward declaration of the Stack template class
template <class T>
class Stack;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

template <class T>
class Stack
{
    //Data Members
    Node<T>* stkTop; // – Pointer to top (first) node in list.
    int stkSize; //– Number of items currently stored in stack.
    
    // friend declaration for the template function - note the
    // special syntax
    friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);
    
public:
    Stack();
    ~Stack();
    Stack(const Stack<T>&);
    const Stack<T>& operator=(const Stack<T> &);
    void clear();
    int size() const;
    bool empty() const;
    T top() const throw(underflow_error);
    void push(const T&);
    void pop() throw(underflow_error);
    void evaluateExpressions();
    
private:
    void copyList(const Stack<T>&);
};


// Method definitions for the Stack class
/**************************************************************
 
 FUNCTION: Stack<T>::Stack()
 
 ARGUMENTS: The Default constructor
 
 RETURNS: N/A.
 
 NOTES:   Set the top pointer to NULL and set the stack size to 0.
 
 **************************************************************/
template <class T>
Stack<T>::Stack()
{
    stkTop = NULL;
    stkSize = 0;
}

/**************************************************************
 
 FUNCTION: Stack<T>::~Stack()
 
 ARGUMENTS: The Deconstructor
 
 RETURNS: N/A.
 
 NOTES:   Calls the Clear Method.
 
 **************************************************************/
template <class T>
Stack<T>::~Stack()
{
    clear();
}

/**************************************************************
 
 FUNCTION: Stack<T>::Stack(const Stack<T>& stackToCopy)
 
 ARGUMENTS: The copy constructor
 
 RETURNS: N/A.
 
 NOTES:   Copies the Stack Size.
 
 **************************************************************/
template <class T>
Stack<T>::Stack(const Stack<T>& stackToCopy)
{
    stkTop = NULL;
    copyList(stackToCopy);
    stkSize = stackToCopy.stkSize;
}

/**************************************************************
 
 FUNCTION: const Stack<T>& Stack<T>::operator=(const Stack<T>& rightOp)
 
 ARGUMENTS: Method overloads one Stack object to be assigned to another object.
 
 RETURNS: N/A.
 
 NOTES:   Calls the clear method, Copies the Stack Size, and calls the Copylist method.
 
 **************************************************************/
template <class T>
const Stack<T>& Stack<T>::operator=(const Stack<T>& rightOp)
{
    if (this != &rightOp)
    {
        clear();
        stkSize = rightOp.stkSize;
        copyList(rightOp);
    }
    
    return *this;
}

/**************************************************************
 
 FUNCTION: void Stack<T>::clear()
 
 ARGUMENTS: Method properly set the stack back to the empty state. 
            Deleting all of the nodes in the stack, setting the top 
            pointer back to NULL, and setting the stack size back to 0.
 
 RETURNS: Stack Size
 
 NOTES:   Calls the pop Method.
 
 **************************************************************/
template <class T>
void Stack<T>::clear()
{
    while(stkSize != 0)
    {
        pop();
    }
}

/**************************************************************
 
 FUNCTION: int Stack<T>::size() const
 
 ARGUMENTS: Method returns the number of data items currently stored 
            in the stack
 
 RETURNS: Stack Size
 
 NOTES:   Method returns the number of data items currently stored 
          in the stack.
 
 **************************************************************/
template <class T>
int Stack<T>::size() const
{
    return stkSize;
}

/**************************************************************
 
 FUNCTION: bool Stack<T>::empty()const
 
 ARGUMENTS: Method returns true if there are no data items currently stored in the stack;
            otherwise returns false
 
 RETURNS: True or False.
 
 NOTES:   Method returns true if there are no data items currently stored in the stack;
          otherwise returns false.
 
 **************************************************************/
template <class T>
bool Stack<T>::empty()const
{
    if(stkSize == 0)
        return true;
    else
        return false;
}

/**************************************************************
 
 FUNCTION: T Stack<T>::top() const throw(underflow_error)
 
 ARGUMENTS: Method return the data stored in the top node of the stack. 
            If the stack is empty, this method should throw an 
            underflow_exception.
 
 RETURNS: Template Parameter Type
 
 NOTES:   If the stack is empty, this method should throw an
          underflow_exception..
 
 **************************************************************/
template <class T>
T Stack<T>::top() const throw(underflow_error)
{
    if (stkSize == 0)
        throw underflow_error("underflow on call to top()");
        
        return stkTop->data;
}

/**************************************************************
 
 FUNCTION: void Stack<T>::push(const T& item)
 
 ARGUMENTS: Method inserts the item at the top of the stack as the 
            new first node in the linked list.
 
 RETURNS: N/A.
 
 NOTES:   inserts the item at the top of the stack as the new first 
          node in the linked list..
 
 **************************************************************/
template <class T>
void Stack<T>::push(const T& item)
{
    Node<T>* newNode = new Node<T>(item, stkTop);
    stkTop = newNode;
    stkSize++;
}

/**************************************************************
 
 FUNCTION: void Stack<T>::pop() throw(underflow_error)
 
 ARGUMENTS: Method removes the node at the top of the stack. If the 
            stack is empty, this method throws an underflow_exception.
 
 RETURNS: N/A.
 
 NOTES:   Removes the node at the top of the stack. If the stack is 
          empty, this method throws an underflow_exception.
 
 **************************************************************/
template <class T>
void Stack<T>::pop() throw(underflow_error)
{
    if (stkSize == 0)
        throw underflow_error("underflow on call to pop()");
        
        Node<T>* delNode = stkTop;
        stkTop = stkTop->next;
        delete delNode;
    stkSize--;
}

/**************************************************************
 
 FUNCTION: ostream& operator<<(ostream& output, const Stack<T>& rightOp)
 
 ARGUMENTS: output - is output stream object to be written too.
            rightOp  - Stack object to insert into the output stream.
 
 RETURNS: The updated output stream object.
 
 NOTES:   Inserts the Stack object into the output stream..
 
 **************************************************************/
template <class T>
ostream& operator<<(ostream& output, const Stack<T>& rightOp)
{
    Node<T>* ptr;
    for (ptr = rightOp.stkTop; ptr != NULL; ptr = ptr->next)
    {
        output << ptr->data << ' ';
    }
    return output;
}

/**************************************************************
 
 FUNCTION: void Stack<T>::copyList(const Stack<T>& stackToCopy)
 
 ARGUMENTS: Method calls both the copy constructor and overloaded 
            assignment operator to make a copy of the linked list.
 
 RETURNS: N/A.
 
 NOTES:   Calls both the copy constructor and overloaded assignment 
          operator to make a copy of the linked list.
 
 **************************************************************/
template <class T>
void Stack<T>::copyList(const Stack<T>& stackToCopy)
{
    Node<T>* ptr, * newNode, * last = NULL;
    for (ptr = stackToCopy.stkTop; ptr != NULL; ptr = ptr->next)
    {
        newNode = new Node<T>(ptr->data);
        if (last == NULL)
            stkTop = newNode;
        else
            last->next = newNode;
        last = newNode;
    }
}
#endif /* STACK_H */
