// LinkedListInsertSorted.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//Linked List Node	
struct Node{
	int data;
	struct Node *next;
};

//Insert function which will insert the new data in a sorted order
//Function takes a pointer to head and returns the modified list
Node *insert(Node *head, int data)
{
	// allocate node and put in data
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	//create a temporary variable pointing to head
	Node *temp = head;

	// if the list is empty
	if (head == NULL)
	{
		head = newNode;
		return head;
	}
	// run the loop till the next ndoe is not null or next node data is greater than the data
	while ((temp->next != NULL) && (temp->next->data < data))
	{
		temp = temp->next;
	}
	if (temp->next != NULL)
	{
		newNode->next = temp->next;
	}
	temp->next = newNode;
	return head;
}


// This insert function takes a reference of pointer to head and
// inserts the new data in a sorted order

void insertRef(Node **head, int data)
{
	// allocate node and put in data
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	//create a temporary variable pointing to head
	Node *temp = *head;

	// if the list is empty
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	// run the loop till the next ndoe is not null or next node data is greater than the data
	while (temp->next != NULL && temp->next->data < data)
	{
		temp = temp->next;
	}
	if (temp->next != NULL)
	{
		newNode->next = temp->next;
	}
	temp->next = newNode;
}
// Function prints the elements of linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

// Driver program to test insert linked list functions
int main()
{
	// start with empty list
	Node *head = NULL;
	// Pass by value
	/*head = insert(head, 2);
	head = insert(head, 6);
	head = insert(head, 4);
	head = insert(head, 10);
	head = insert(head, 8);
	*/
	// Pass by reference
	insertRef(&head, 2);
	insertRef(&head, 6);
	insertRef(&head, 4);
	insertRef(&head, 10);
	insertRef(&head, 8);
	printList(head);
    return 0;
}

