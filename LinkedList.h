#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class ListNode
{
protected:
		ListNode *next;
		char data;
		ListNode();
};

class LinkedList : public ListNode
{
private:
		ListNode *head;
		ListNode *tail;
		int nodeCount; // Hold number of existing nodes
public:
		LinkedList();
		~LinkedList();
		inline bool isEmpty() const;
    int getNodeCount() const;
		void push(const char dat);
		char pop();
};


#endif
