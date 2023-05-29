// LinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: James Fehr
// LinkedList Exercise

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//////////////// Linked List needed struct
struct Node
{
	int data;
	Node* next;
};
////////////////
Node* start, current; // pointers needed for Linked list
void addNewNodeBeginList(int data);  // add new node to Linked list function
void addNodeEndList(int data);
void PrintList();	// Print out Linked list function
void deleteNodeFromStartList();
void deleteNodeFromEndList();
void addNewNodeAfterSpecificElementInList(int data);
void addNewNodeToEndOfList(int data);
void addNewNodeBeforeSpecificElementInList(int data);
int main()
{
	for (int i = 1; i <= 15; i++) { addNewNodeBeginList(i); } // adding 25 nodes to list
	PrintList();  // Printing LinkedList
	deleteNodeFromStartList();
	deleteNodeFromEndList();
	addNodeEndList(10101);
	
	for(int j = 1; j <= 13; j++){ deleteNodeFromEndList(); }
	addNewNodeBeforeSpecificElementInList(12);
	addNewNodeAfterSpecificElementInList(14);
	PrintList();
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

	return 0;
}
// Add New Node 
void addNewNodeBeginList(int data) { // takes integer for data which makes it easy using a for loop to initialize any number of Nodes
	if (start == NULL) { // check for null just in case
		start = (Node*)malloc(sizeof(Node));  // assign memory to the struct
		start->data = data;	// assign data to the struct
		start->next = NULL;	// set a null 
		return; // exit error check
	}
	Node* newNode = (Node*)malloc(sizeof(Node)); // setup memory for the newNode
	newNode->data = data;		// assign data to the struct
	newNode->next = start;		// assign start as new node
	start = newNode;			// swap node to start
}

void PrintList() {
	Node* current = start;
	if (current == NULL) { printf("\nThere is nothing to display\n"); return; }
	printf("\n -<- Start ->- \n");
	while (current != NULL)
	{
		printf("Current Next Data: %d, Current Next Address %p\n", current->data, current->next);
		current = current->next;
	}
	printf(" -<- End ->- \n");
}

void addNodeEndList(int data) {
	Node* current = start;
	while (current->next != NULL) {
		current = current->next;
	}
	Node* newNode = (Node*)malloc(sizeof(Node)); // setup memory for the newNode
	newNode->data = data;		// assign data to the struct
	newNode->next = start;		// assign start as new node
	start = newNode;			// swap node to start
};


void addNewNodeToEndOfList(int data) {
	// Create a new node
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (start == NULL) {
		// If the list is empty, make the new node the start node
		start = newNode;
	}
	else {
		// Traverse to the end of the list
		Node* currentNode = start;
		while (currentNode->next != NULL) {
			currentNode = currentNode->next;
		}

		// Add the new node to the end of the list
		currentNode->next = newNode;
	}
}


void deleteNodeFromStartList() {
	if (start == NULL) {
		return;
	}
	Node* temp = start;
	start = start->next;
	free(temp);
}

void deleteNodeFromEndList() {
	if (start == NULL) {
		printf("Error, cannot delete nothing\n");
		return;
	}

	Node* current = start;
	Node* temp = NULL;

	if (current->next == NULL) {
		// Only one node in the list
		free(current);
		start = NULL;
		return;
	}

	while (current->next->next != NULL) {
		temp = current;
		current = current->next;
	}

	free(current->next);
	current->next = NULL;
}

void addNewNodeAfterSpecificElementInList(int data) {
	Node* currentNode = start;
	while (currentNode != NULL) {
		if (currentNode->data == data) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = data + 1;
			newNode->next = currentNode->next;
			currentNode->next = newNode;
			return;
		}

		currentNode = currentNode->next;
	}

	// If the specific element is not found, add the new node at the beginning of the list
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = start;
	start = newNode;

	}


void addNewNodeBeforeSpecificElementInList(int data) {
	if (start == NULL) {
		// If the list is empty, create a new node and make it the start node
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = NULL;
		start = newNode;
		return;
	}

	if (start->data == data) {
		// If the start node has the specific element, add the new node before it
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data - 1;
		newNode->next = start;
		start = newNode;
		return;
	}

	Node* currentNode = start;
	while (currentNode->next != NULL) {
		if (currentNode->next->data == data) {
			// Found the specific element, add the new node before it
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = data - 1;
			newNode->next = currentNode->next;
			currentNode->next = newNode;
			return;
		}
		currentNode = currentNode->next;
	}

	// If the specific element is not found, add the new node at the end of the list
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	currentNode->next = newNode;
}


void deleteSpecificNodeFromList(int data) {
	if (start == NULL) {
		// If the list is empty, return as there is nothing to delete
		return;
	}

	if (start->data == data) {
		// If the start node has the specific element, delete it
		Node* nodeToDelete = start;
		start = start->next;
		free(nodeToDelete);
		return;
	}

	Node* currentNode = start;
	while (currentNode->next != NULL) {
		if (currentNode->next->data == data) {
			// Found the specific element, delete the node
			Node* nodeToDelete = currentNode->next;
			currentNode->next = currentNode->next->next;
			free(nodeToDelete);
			return;
		}
		currentNode = currentNode->next;
	}
}

void deleteAfterSpecificNodeFromList(int data) {
	if (start == NULL) {
		// If the list is empty, return as there is nothing to delete
		return;
	}

	Node* currentNode = start;
	while (currentNode != NULL) {
		if (currentNode->data == data && currentNode->next != NULL) {
			// Found the specific node, delete the node after it
			Node* nodeToDelete = currentNode->next;
			currentNode->next = currentNode->next->next;
			free(nodeToDelete);
			return;
		}
		currentNode = currentNode->next;
	}
}

void deleteBeforeSpecificNodeFromList(int data) {
	if (start == NULL || start->next == NULL) {
		// If the list is empty or has only one node, return as there is nothing to delete before
		return;
	}

	if (start->next->data == data) {
		// If the second node has the specific element, delete the first node
		Node* nodeToDelete = start;
		start = start->next;
		free(nodeToDelete);
		return;
	}

	Node* currentNode = start;
	while (currentNode->next != NULL && currentNode->next->next != NULL) {
		if (currentNode->next->next->data == data) {
			// Found the specific element, delete the node before it
			Node* nodeToDelete = currentNode->next;
			currentNode->next = currentNode->next->next;
			free(nodeToDelete);
			return;
		}
		currentNode = currentNode->next;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

