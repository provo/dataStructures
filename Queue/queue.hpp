#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

// Queue node structure
struct node
{
	node *next;
	char data;
};

// Queue class definition
class Queue
{
private:
	node *front;
	node *rear;
	int nodeCount;
public:
	// Constructors and destructor
	Queue(const char dat);
	Queue();
	~Queue();

	// Class methods
	inline bool isEmpty() const;
	int getCount() const;
	void insert(const char dat);
	void cutTheLine(const char dat);
	char remove();
	void printQueue() const;
	void deleteQueue();

	// Overloaded operators
	friend std::ostream & operator<<(std::ostream &os, const Queue &obj);
	bool operator<(const Queue &obj);
	bool operator>(const Queue &obj);
};


#endif
