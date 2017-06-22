/*
 * June 20, 2017   LINKED LIST 
 * Linked List implementation featuring char data type although that could 
 * easily be changed or made generic. 
 */

#include <iostream>
#include "LinkedList.hpp"

using std::cout;
using std::endl;


// HEAD -> NODE -> NODE -> TAIL -> NULL

LinkedList::LinkedList(const char c)
{
		ListNode *newNode = new ListNode;
		newNode->next = nullptr;
		newNode->data = c; 
		head = tail = newNode;
    nodeCount = 1;
}

LinkedList::~LinkedList()
{
		deleteList();
}

bool LinkedList::isEmpty() const { return (nodeCount == 0) ? true : false; }

int LinkedList::getNodeCount() const { return nodeCount; }

void LinkedList::push(const char dat) 
{
		ListNode *node = new ListNode;
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

		return;
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


void LinkedList::deleteList()
{
		if (isEmpty())
		{	
				cout << "The list is already empty" << endl;
				return;
		}

	  ListNode *del, *curr = head;
	  while(curr)
		{
				del = curr;
				curr = curr->next;
				delete del;
		}	
		nodeCount = 0;
		tail = head = nullptr;

		return;
}

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
		return;
}


