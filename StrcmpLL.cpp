// StrcmpLL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// structure of a Node
struct Node {
	char data;
	Node *next;
};

// To create new node in a linked list
Node* newNode(char c)
{
	Node *temp = new Node;
	temp->data = c;
	temp->next = NULL;
	return temp;
};

int strcmpLL(Node *head1, Node*head2)
{
	// continue the loop until characters in both the list are equal
	while (head1 && head2 && head1->data == head2->data)
	{
		head1 = head1->next;
		head2 = head2->next;
	}
	// if both the list are still presesnt, compare the unmatched character and return accordingly
	if (head1 && head2)
	{
		return (head1->data > head2->data ? 1 : -1);
	}
	// if list 1 is still present return 1 else if list 2 is present , return -1
	if (head1 && !head2) return 1;
	if (head2 && !head1) return -1;

	// if all the above conditions are not reached, it means strings are equal , return 0
	return 0;
}
int main()
{
	Node *list1 = newNode('v');
	list1->next = newNode('a');
	list1->next->next = newNode('i');
	list1->next->next->next = newNode('b');
	list1->next->next->next->next = newNode('h');
	list1->next->next->next->next->next = newNode('a');
	list1->next->next->next->next->next->next = newNode('v');

	Node *list2 = newNode('v');
	list2->next = newNode('a');
	list2->next->next = newNode('i');
	list2->next->next->next = newNode('b');
	list2->next->next->next->next = newNode('h');
	list2->next->next->next->next->next = newNode('a');

	cout << strcmpLL(list1, list2) << endl;

    return 0;
}

