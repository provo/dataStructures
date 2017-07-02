#include <iostream>
#include <string>
#include "arrayStack.hpp"

using std::cout;
using std::endl;
using std::string;


inline bool ArrayStack::isEmpty() const { return (top == &stackArray[0]); }

inline bool ArrayStack::isFull() const { return (stackElements >= STACK_SIZE); }


ArrayStack::ArrayStack()
{
    top = stackArray;
    stackElements = 0;
}

ArrayStack::ArrayStack(const string &str)
{
    top = stackArray;
    *top = str;
    top++;
    stackElements = 1;
}


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

ArrayStack::~ArrayStack() { /* Do nothing */ }

void ArrayStack::printStack() const
{
    string *ptr = top - 1;
    cout << "TOP  ";
    while(ptr != &stackArray[0])
    {
        cout << *ptr << "  ";
        ptr--;
    }
    cout << *ptr << "  BOTTOM" << endl;

    return;
}

void ArrayStack::peek() const { cout << "Top element of stack: " << *(top - 1) << endl; }

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




std::ostream & operator<<(std::ostream &os, const ArrayStack &obj)
{
    if (obj.isEmpty())
    {
        os << "The stack is empty" << endl;
        return os;
    }

    string *ptr = obj.top - 1;
    os << "TOP  ";
    while(ptr != &obj.stackArray[0])
    {
        os << *ptr << "  ";
        ptr--;
    }
    os << *ptr << "  BOTTOM" << endl;

    return os;
}
