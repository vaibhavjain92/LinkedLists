// Addition LL.cpp : Defines the entry point for the console application.
//
// In addition of a linked list, there can be two cases one that the list length are same
// and second that the two lists are of different length.
// if the lengths are same, make one function for it, and if there is any carry after the last addition push it to the result
// if the lengths are not same, find the diff of two lengths, move the first list by that amount and then do addition of same length
// add the carry from the previous one to the left subpart of the list and complete the result list
// if list 2 is greater than list 1, swap the pointers of two lists
// functions required:
// addLists: function to add two lists
// addSameList: add the elements in the linked lists having same length
// addDiffList: add the lists having diff no. of elements
// addNode: add elements to the beginning of list
// getSizeLL: returns the length of the linked list
// swapLists: swap the pointer of two lists
// PrintList: prints the length of the linked list

#include "stdafx.h"
#include <iostream>
using namespace std;

/*structure of the linked list*/
struct Node {
	int data;
	Node *next;
};

/* returns the length of the linked list */
int getSizeLL(Node *head)
{
	int len = 0;
	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}

/*swap the pointers of the two lists */
void SwapLists(Node **head1, Node **head2)
{
	Node *temp = *head1;
	*head1 = *head2;
	*head2 = temp;
}

/*add nodes to the front of the linked list*/
void addNode(Node **head, int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

/*Prints the elements of the list*/
void PrintList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

/*adds the list having the same no. of elelments*/
void addSameLists(Node *head1, Node *head2, int &carry, Node **result)
{
	if (head1 == NULL)
		return;
	addSameLists(head1->next, head2->next, carry, result);

	int sum = head1->data + head2->data + carry;
	carry = sum / 10;
	int res  = sum % 10;
	addNode(result, res);
}

/*adds the lists having diff no. of elements*/
void addDiffLists(Node *head1, Node *curr, int &carry, Node **result)
{
	if (head1 != curr)
	{
		addDiffLists(head1->next, curr, carry, result);
		int sum = head1->data + carry;
		carry = sum / 10;
		int res = sum % 10;
		addNode(result, res);
	}
}

/*main function to add the elements of two linked lists*/
void addLists(Node *head1, Node *head2, Node **result)
{
	// if the 1st list is empty
	if (head1 == NULL)
	{
		*result = head2;
		return;
	}

	// if the 2nd list is empty
	if (head2 == NULL)
	{
		*result = head1;
		return;
	}

	int len1 = getSizeLL(head1);
	int len2 = getSizeLL(head2);

	int carry = 0;

	// if two lists of same length
	if (len1 == len2)
	{
		addSameLists(head1, head2, carry, result);
	}

	// if second list is greater than the first one, swap the two list pointers
	if (len2 > len1)
	{
		SwapLists(&head1, &head2);
	}

	// condition where 1st list is greater than the second list
	int diff = abs(len1 - len2);
	Node *temp = head1;
	//Increment the pointer so that both the lists are of equal length
	for (temp; diff--; temp = temp->next);

	addSameLists(temp, head2, carry, result); // add the same list
	
	addDiffLists(head1, temp, carry, result); // add the result from the same lists to diff lists
	
	if (carry) // if there is carry, add it to the result list
		addNode(result, carry);
}
int main()
{
	int arr1[] = { 9,8,9 };
	int arr2[] = { 1, 9 };
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	Node *head1 = NULL, *head2 = NULL, *result = NULL;
	// add elements to the first linked list
	for (int i = size1-1; i >=0; i--)
	{
		addNode(&head1, arr1[i]);
	}
	cout << "Printing the first linked list" << endl;
	PrintList(head1);

	// add elements to the second linked list
	for (int i = size2-1; i >=0; i--)
	{
		addNode(&head2, arr2[i]);
	}
	cout << "Printing the second linked list" << endl;
	PrintList(head2);

	// add the elements of the two lists
	addLists(head1, head2, &result);
	
	// print the result
	cout << "Printing the final result" << endl;
	PrintList(result);
    return 0;
}

