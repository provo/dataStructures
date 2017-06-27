/*
 * June 20, 2017  Queue data structure
 */

#include <iostream>
#include "queue.hpp"

using std::cout;
using std::endl;


// REAR -> NODE -> NODE -> NODE -> FRONT

Queue::Queue(const char dat)
{
	node *newNode = new node;
	newNode->data = dat;
	newNode->next = nullptr;
	front = rear = newNode;
	nodeCount = 1;
}

Queue::Queue()
{
	front = rear = nullptr;
	nodeCount = 0;
}

Queue::~Queue()
{
	deleteQueue();
}

bool Queue::isEmpty() const { return (nodeCount == 0) ? true : false; }

int Queue::getCount() const { return nodeCount; }

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

void Queue::insert(const char dat)
{
	node *newNode = new node;
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

	return;
}


void Queue::cutTheLine(const char dat)
{
	node *newNode = new node;
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

	return;
}

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

//Overloaded operators
// Return true is this.nodeCount < obj.nodeCount
bool Queue::operator<(const Queue &obj)
{
	return (this->nodeCount < obj.nodeCount) ? true : false;
}


// Return true is this.nodeCount > obj.nodeCount
bool Queue::operator>(const Queue &obj)
{
	return (this->nodeCount > obj.nodeCount) ? true : false;
}


