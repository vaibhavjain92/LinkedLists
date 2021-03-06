// MergeLLAlternately.cpp : Defines the entry point for the console application.
//
// In this program, I need to merge the second linked list into first at alternate positions
// Functions required
// mergeLL: function to merge two linked list
// mergerLLUtil: function used by mergeLL to merge two linked lists
// addNode: add elements to form a linked list
// swapList: swap pointers of linked list in case 2nd is bigger than 1st
// getSize: returns the length of the linked list
// PrintList: prints the linked list

#include "stdafx.h"
#include<iostream>
using namespace std;

/*structure of a linked list*/
struct Node {
	int data;
	Node *next;
};

/*function to add node to first position of linked list*/
void addNode(Node **head, int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

/*function to return the size of the linked list*/
int getSize(Node *head)
{
	int len = 0;
	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}

/*function to swap the pointers of the two lists*/
void swapList(Node **head1, Node **head2)
{
	Node *temp = *head1;
	*head1 = *head2;
	*head2 = temp;
	cout << "<<lists swapped>>" << endl;
}

/*function to print the linked list*/
void PrintList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

/*function used by merge list to merge two lists*/
void mergeListUtil(Node **head1, Node **head2)
{
	Node *curr1 = *head1;
	Node *curr2 = *head2;

	while (curr1 && curr2)
	{
		Node *curNext1 = curr1->next;
		Node *curNext2 = curr2->next;
		curr1->next = curr2;
		curr1 = curNext1;
		curr2->next = curr1;
		curr2 = curNext2;
	}
	*head2 = curr2;
}

/*function to merge the two lists*/
void mergeLists(Node **head1, Node **head2)
{
	int size1 = getSize(*head1);
	int size2 = getSize(*head2);

	// if size 2 is greater than size 1, swap the list pointers
	if (size2 > size1)
	{
		swapList(head1, head2);
	}
	
	//merge the two lists
	mergeListUtil(head1, head2);
	
}

/*driver program to merge two lists*/
int main()
{
	struct Node *p = NULL, *q = NULL;
	addNode(&p, 3);
	addNode(&p, 2);
	addNode(&p, 1);
	printf("First Linked List:\n");
	PrintList(p);

	addNode(&q, 8);
	addNode(&q, 7);
	addNode(&q, 6);
	addNode(&q, 5);
	addNode(&q, 4);
	printf("Second Linked List:\n");
	PrintList(q);
	
	mergeLists(&p, &q);

	printf("Modified First Linked List:\n");
	PrintList(p);

	printf("Modified Second Linked List:\n");
	PrintList(q);

    return 0;
}

