// DetectRemoveLoop.cpp : Defines the entry point for the console application.
//
// First part of this programis to find loop
// find the loop by slow and fast pointer, if the two pointers meet, it means there is a loop
// if the fast pointer reaches null, no loop
// Therefore a function to detect loop
// Then remove loop: once you know the position where they met,  make a pointer point to start ans another start from the meeting point
/// until the next of both of them meet at the same point

#include "stdafx.h"
#include<iostream>
using namespace std;

/*structure of the linked list*/
struct Node {
	int data;
	Node *next;
};

struct Node *newNode(int key)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

/*Function to detect and remove the loop in the linked list*/
// it returns NULL if no loop and returns pointer to the meeting node if loop is present
int detectLoop(Node *head)
{
	Node *slow = head, *fast = head;
	while (fast != NULL || fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow->next != fast->next)
			{
				slow = slow->next;
				fast = fast->next;
			}
			fast->next = NULL;
			return 1;
		}
			
	}
	return 0;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	struct Node *head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	cout<<detectLoop(head)<<endl;

	printf("Linked List after removing loop \n");
	printList(head);
    return 0;
}

