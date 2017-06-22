#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

class ListNode
{
public:
	ListNode *next;
	char data;
};

class LinkedList 
{
private:
	ListNode *head;
	ListNode *tail;
	int nodeCount; // Hold number of existing nodes
public:
	LinkedList(const char c = '0');
	~LinkedList();
	inline bool isEmpty() const;
	int getNodeCount() const;
	void push(const char dat);
	char pop();
	void deleteList();
	void printList() const;
};


#endif
