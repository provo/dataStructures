#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP

#include <string>
#include <iostream>

using std::string;

class ArrayStack
{
private:
    static const int STACK_SIZE = 10;
    string stackArray[STACK_SIZE];
    string *top; // Pointer to next free stack slot
    int stackElements; // Keep track of stack element number
public:
    // Constructors and destructor
    ArrayStack(const string &str);
    ArrayStack(const char *str);
    ArrayStack(const ArrayStack &obj);
    ArrayStack();
    ~ArrayStack();

    // Class methods
    bool isEmpty() const;
    bool isFull() const;
    void printStack() const;
    void peek() const;  // Print top element

    void push(const string &str);
    void push(const char *str);
    string pop();

    // Overloaded operators
    friend std::ostream & operator<<(std::ostream &os, const ArrayStack &obj);

};


#endif // ARRAYSTACK_HPP 
