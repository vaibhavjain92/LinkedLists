// DeleteNodeLL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//structure of a linked list node
struct Node {
	int data;
	struct Node *next;
};

void deleteNode(Node *head, Node *node)
{
	// 2 cases: 
	// 1) Head to be deleted : head next node is new head
	// 2) Other nodes apart from head is getting deleted
	Node *temp = head;
	//1st case
	if (head->data == node->data)
	{
		cout << "in if " << endl;
		head = head->next;
		delete(temp);
		return;
	}
	//2nd case
	while (temp->next!= NULL  )
	{
		if (temp->next->data == node->data)
			break;
		temp = temp->next;
	}
	cout << endl;
	// if it reaches end of list, it meand the node is not found, print error message
	if (temp->next == NULL)
	{
		cout << "Node not found" << endl;
		return;
	}
	
	//else if the node is found delete, it
	Node *temp2 = temp->next;
	temp->next = temp->next->next;
	delete(temp2);

	return;

}
// function to insert a new node with the given data
//where the function takes reference to pointer to head

void insert(Node **head, int data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	// if list is empty
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	Node *temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	return;
}

//prints the element of the given list
void PrintList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

//driver program to check the above function
int main()
{
	struct Node *head = NULL;
	insert(&head, 2);
	insert(&head, 6);
	insert(&head, 4);
	insert(&head, 10);
	insert(&head, 8);
	PrintList(head);
	deleteNode(head, head->next->next);
	PrintList(head);
    return 0;
}

