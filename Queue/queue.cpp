/*
 * June 20, 2017
 * Queue data structure implemented with char data type
 */

// Included files
#include <iostream>
#include "queue.hpp"

// Using declarations
using std::cout;
using std::endl;


/* REAR -> NODE -> NODE -> NODE -> FRONT */

// Constructor with char as argument
Queue::Queue(const char dat)
{
		node *newNode = new node;
		if (newNode == nullptr)
		{
				cout << "Out of memory" << endl;
				return;
		}
		newNode->data = dat;
		newNode->next = nullptr;
		front = rear = newNode;
		nodeCount = 1;
}

// Default constructor
Queue::Queue()
{
		front = rear = nullptr;
		nodeCount = 0;
}

// Destructor
Queue::~Queue()
{
		deleteQueue();
}

// Check if the queue is empty
bool Queue::isEmpty() const { return (nodeCount == 0); }

// Get the current node count
int Queue::getCount() const { return nodeCount; }

// Print the entire queue
void Queue::printQueue() const
{
		if (isEmpty())
		{
				cout << "Queue is empty" << endl;
				return;
		}
		node *curr = rear;
		cout << "REAR | ";
		while(curr)
		{
				cout << curr->data << " | ";
				curr = curr->next;
		}
		cout << " FRONT" << endl;
}

// Overload the cout << operator to print the queue
std::ostream & operator<<(std::ostream &os, const Queue &obj)
{
		node *curr = obj.rear;
		os << "REAR | ";
		while(curr)
		{
				os << curr->data << " | ";
				curr = curr->next;
		}
		os << " FRONT" << endl;
		return os;
}

// Insert a new node at the rear of the queue
void Queue::insert(const char dat)
{
		node *newNode = new node;
		if (newNode == nullptr)
		{
				cout << "Out of memory" << endl;
				return;
		}
		newNode->data = dat;

		if (isEmpty())
		{
				newNode->next = nullptr;
				front = rear = newNode;
		}
		else
		{
				newNode->next = rear;
				rear = newNode;
		}
		nodeCount++;
}

// Insert a new node at the front of the queue
void Queue::cutTheLine(const char dat)
{
		node *newNode = new node;
		if (newNode == nullptr)
		{
				cout << "Out of memory" << endl;
				return;
		}
		newNode->data = dat;

		if (isEmpty())
		{
				newNode->next = nullptr;
				front = rear = newNode;
		}
		else
		{
				front->next = newNode;
				newNode->next = nullptr;
				front = newNode;
		}
		nodeCount++;
}

// Remove from the front of the queue
char Queue::remove()
{
		if (isEmpty())
		{
				cout << "Queue is empty" << endl;
				return '0';
		}

		char tmp = front->data;
		if (front == rear) // Only one node in the q
		{
				delete front;
	 			front = rear = nullptr;
				nodeCount = 0;
				return tmp;
		}

		node *second_in_line = rear;
		while(second_in_line->next != front)
				second_in_line = second_in_line->next;

		delete front;
		front = second_in_line;
		second_in_line->next = nullptr;
		nodeCount--;
		return tmp;
}

// Delete the entire queue
void Queue::deleteQueue()
{
		if (isEmpty())
				return;

		node *curr = rear;
		node *del;
		while(curr)
		{
				del = curr;
				curr = curr->next;
				delete del;
		}

		front = rear = nullptr;
		nodeCount = 0;
}

/* Overloaded operators */
// Return true if this->nodeCount < obj.nodeCount
bool Queue::operator<(const Queue &obj) const { return (nodeCount < obj.nodeCount); }

// Return true if this->nodeCount > obj.nodeCount
bool Queue::operator>(const Queue &obj) const { return (nodeCount > obj.nodeCount); }
