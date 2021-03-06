// ReverseLinkedListGroups.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

/*structure for the linked list*/
struct Node {
	int data;
	Node *next;
};

void reverseLinkedList(Node **head)
{
	Node *prev = NULL, *curr = *head;
	while (curr != NULL)
	{
		Node *next = curr->next;
		curr->next = prev;
		prev = curr; 
		curr = next;
	}
	*head = prev;
}

Node *reverseSubLinkedList(Node *head, int k)
{
	Node *prev = NULL, *curr = head, *next = NULL;
	int count = 0;
	while (curr != NULL && count < k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if (next)
	{
		head->next = reverseSubLinkedList(next, k);
	}
	return prev;
}
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d  ", node->data);
		node = node->next;
	}
}

/* Drier program to test above function*/
int main(void)
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("\nGiven linked list \n");
	printList(head);
	//reverseLinkedList(&head);
	head = reverseSubLinkedList(head, 3);
	printf("\nReversed Linked list \n");
	printList(head);

	return(0);
}

