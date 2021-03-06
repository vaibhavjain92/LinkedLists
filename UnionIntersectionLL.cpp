// UnionIntersectionLL.cpp : Defines the entry point for the console application.
//
// In this program, the intersection prints the common element in the two linked lists
// and union prints all the elements in the two linked list without repetition
// Thus, to achieve the union, we need hash map to optimize the performance
// UnionLists: Function to do union of the linked lists
#include "stdafx.h"
#include <iostream>
#include<unordered_set>
using namespace std;

/*structure of the linked list*/
struct Node {
	int data;
	Node *next;
};

/*Add element to the end of linked list*/
void addNode(Node **head, int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	if (*head == NULL)
	{
		*head = newNode; 
		return;
	}
		
	Node *temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
	return;
}

/* A utility function to print a linked list*/
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/*A funtion to return the union of two linked list*/
Node *UnionListFunc(Node *head1, Node *head2)
{
	unordered_set<int> set;
	Node *unionLL = NULL;
	Node *temp1 = head1;
	Node *temp2 = head2;
	while (temp1 != NULL)
	{
		unordered_set<int>::iterator i = set.find(temp1->data);
		if (i == set.end())
		{
			set.insert(temp1->data);
			addNode(&unionLL, temp1->data);
		}
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		unordered_set<int>::iterator i = set.find(temp2->data);
		if (i == set.end())
		{
			set.insert(temp2->data);
			addNode(&unionLL, temp2->data);
		}
		temp2 = temp2->next;
	}
	return unionLL;
}

/*A function to return the insection of the two linked lists*/
Node *IntersectionListFunc(Node *head1, Node *head2)
{
	// create a hash set, if the element is there, add it to list otherwise move
	unordered_set<int> set;
	Node *intersecnList = NULL;
	while (head1 != NULL)
	{
		set.insert(head1->data);
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		unordered_set<int>::iterator i = set.find(head2->data);
		if (i != set.end())
		{
			addNode(&intersecnList, head2->data);
		}
		head2 = head2->next;
	}
	return intersecnList;
}

/*Driver program to return the union and intersection of two linked list*/
int main()
{
	/* Start with the empty list */
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* intersecn = NULL;
	struct Node* unin = NULL;

	/*create a linked lits 10->15->5->20 */
	addNode(&head1, 20);
	addNode(&head1, 4);
	addNode(&head1, 15);
	addNode(&head1, 10);
	addNode(&head1, 4);

	/*create a linked lits 8->4->2->10 */
	addNode(&head2, 10);
	addNode(&head2, 2);
	addNode(&head2, 4);
	addNode(&head2, 8);

	intersecn = IntersectionListFunc(head1, head2);
	unin = UnionListFunc(head1, head2);

	printf("\n First list is \n");
	printList(head1);

	printf("\n Second list is \n");
	printList(head2);

	printf("\n Intersection list is \n");
	printList(intersecn);
	
	printf("\n Union list is \n");
	printList(unin);
	cout << endl;
    return 0;
}

