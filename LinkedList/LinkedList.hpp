#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

// Linked List node class
class ListNode
{
public:
	ListNode *next;
	char data;
};

// Linked List class
class LinkedList
{
private:
	ListNode *head;
	ListNode *tail;
	int nodeCount;	// Hold number of existing nodes
public:
	// Constructor and destructor
	LinkedList(const char c = '0');
	~LinkedList();

	// Class methods
	bool isEmpty() const;
	int getNodeCount() const;
	void push(const char dat);
	void insertAtFront(const char dat);
	char pop();
	void deleteList();
	void printList() const;

	// Overloaded operators
	friend std::ostream & operator<<(std::ostream &os, const LinkedList &obj);
};


#endif
