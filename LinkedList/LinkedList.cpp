/*
 * June 20, 2017   LINKED LIST
 * Linked List implementation featuring char data type although that could
 * easily be changed or made generic.
 */

// Included files
#include <iostream>
#include "LinkedList.hpp"

// Using declarations
using std::cout;
using std::endl;

/* HEAD -> NODE -> NODE -> TAIL -> NULL */

// Constructor with default argument c = '0'
LinkedList::LinkedList(const char c)
{
		ListNode *newNode = new ListNode;
		if (newNode == nullptr)
		{
				cout << "Out of memory" << endl;
				return;
		}
		newNode->next = nullptr;
		newNode->data = c;
		head = tail = newNode;
		nodeCount = 1;
}

// Destructor
LinkedList::~LinkedList()
{
	deleteList();
}

// Inline functions
inline bool LinkedList::isEmpty() const { return (nodeCount == 0); }

inline int LinkedList::getNodeCount() const { return nodeCount; }

// Push a new node to the tail of the list
void LinkedList::push(const char dat)
{
	ListNode *node = new ListNode;
	if (node == nullptr)
	{
		cout << "Out of memory" << endl;
		return;
	}
	node->data = dat;
	node->next = nullptr;

	if (isEmpty())
		head = tail = node;
	else
	{
		tail->next = node;
		tail = node;
	}
	nodeCount++;
}

// Pop off from the tail of the list
char LinkedList::pop()
{
	if (isEmpty())
	{
		cout << "List is already empty" << endl;
		return '0';
	}

	ListNode *del = tail;
	char tmp = del->data;
	nodeCount--;
	// Check if we have a list of only one node
	if (head == tail)
	{
		head = tail = nullptr;
		delete head;
		return tmp;
	}

	ListNode *next_to_last = head;

	while (next_to_last->next != tail)
		next_to_last = next_to_last->next;

	next_to_last->next = nullptr;
	tail = next_to_last;
	delete del;
	return tmp;
}

// Delete the entire list
void LinkedList::deleteList()
{
	if (isEmpty())
		return;

	ListNode *del, *curr = head;
	while(curr)
	{
		del = curr;
		curr = curr->next;
		delete del;
	}
	nodeCount = 0;
	tail = head = nullptr;
}

// Print the entire list
void LinkedList::printList() const
{
	if (isEmpty())
	{
		cout << "The list is empty" << endl;
		return;
	}

	ListNode *curr = head;
	cout << "HEAD -> ";
	while(curr)
	{
	  	cout << curr->data << " -> ";
		curr = curr->next;
	}
    cout << "TAIL -> nullptr" << endl;
}

// Insert new node at front of the list
void LinkedList::insertAtFront(const char dat)
{
	ListNode *node = new ListNode;
	if (node == nullptr)
	{
		cout << "Out of memory" << endl;
		return;
	}
	node->data = dat;

	if (isEmpty())
	{
		node->next = nullptr;
		head = tail = node;
	}
	else
	{
		node->next = head;
		 head = node;
	}
	nodeCount++;
}

// Overload cout << operator to print the list
std::ostream & operator<<(std::ostream &os, const LinkedList &obj)
{
	ListNode *curr = obj.head;
	os << "HEAD -> ";
	while(curr)
	{
		os << curr->data << " ->";
		curr = curr->next;
	}
	os << " TAIL" << endl;
	return os;
}
