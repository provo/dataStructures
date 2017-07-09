/*
 *  July 8, 2017
 *  Stack implemented with an array. The stack holds string objects.
 */

// Included files
#include <iostream>
#include <string>
#include "arrayStack.hpp"

// Using declarations
using std::cout;
using std::endl;
using std::string;


// Check if the stack is empty
inline bool ArrayStack::isEmpty() const { return (top == &stackArray[0]); }

// Check if the stack array is filled
inline bool ArrayStack::isFull() const { return (stackElements >= STACK_SIZE); }

// Default constructor
ArrayStack::ArrayStack()
{
    top = stackArray;
    stackElements = 0;
}

// Constructor with string object as argument
ArrayStack::ArrayStack(const string &str)
{
    top = stackArray;
    *top = str;
    top++;
    stackElements = 1;
}

// Constructor with pointer to string as argument
ArrayStack::ArrayStack(const char *str)
{
    top = stackArray;
    *top = str;
    top++;
    stackElements = 1;
}

// Copy constructor
ArrayStack::ArrayStack(const ArrayStack &obj)
{
    if (this == &obj)
        ; // Do nothing
    else
    {
        top = stackArray;
        for(int i = 0; i < obj.stackElements; i++)
        {
            stackArray[i] = obj.stackArray[i];
            top++;
        }
        stackElements = obj.stackElements;
    }
}

// Have not created a destructor
ArrayStack::~ArrayStack() { /* Do nothing */ }

// Print the stack
void ArrayStack::printStack() const
{
    if (isEmpty())
    {
        cout << "The stack is empty" << endl;
        return;
    }

    const string *ptr;
    if (isFull())
        ptr = &(stackArray[STACK_SIZE - 1]);
    else
        ptr = top - 1;

    cout << "TOP  ";
    while(ptr != &stackArray[0])
    {
        cout << *ptr << "  ";
        ptr--;
    }
    cout << *ptr << "  BOTTOM" << endl;
}

// View top of the stack
void ArrayStack::peek() const { cout << "Top element of stack: " << *(top - 1) << endl; }

// Push string object onto the stack
void ArrayStack::push(const string &str)
{
    if (isFull())
    {
        cout << "The stack is full" << endl;
        return;
    }

    stackElements++;
    *top = str;
    if (top == &stackArray[STACK_SIZE - 1])
        top = nullptr;
    else
        top++;
}

// Push pointer to string onto the stack
void ArrayStack::push(const char *str)
{
    if (isFull())
    {
        cout << "The stack is full" << endl;
        return;
    }

    stackElements++;
    *top = str;
    if (top == &stackArray[STACK_SIZE - 1])
        top = nullptr;
    else
        top++;
}

// Pop and return top of the stack
string ArrayStack::pop()
{
    if (isEmpty())
    {
        cout << "The stack is empty. Pop operation aborted." << endl;
        return "STACK EMPTY ERROR";
    }

    string tmp = *(top - 1);
    cout << "Popping " << tmp << " off the stack." << endl;
    top--;      // Next push operation will override the current top element
    stackElements--;
    return tmp;
}

// Overload cout << operator to print the stack
std::ostream & operator<<(std::ostream &os, const ArrayStack &obj)
{
    if (obj.isEmpty())
    {
        os << "The stack is empty" << endl;
        return os;
    }

    const string *ptr;
    if (obj.isFull())
        ptr = &(obj.stackArray[obj.STACK_SIZE - 1]);
    else
        ptr = obj.top - 1;

    os << "TOP  ";
    while(ptr != &obj.stackArray[0])
    {
        os << *ptr << "  ";
        ptr--;
    }
    os << *ptr << "  BOTTOM" << endl;
    return os;
}
