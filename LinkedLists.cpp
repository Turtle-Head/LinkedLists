// LinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: James Fehr
// LinkedList Exercise

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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
void ReverseList();
void deleteNodeFromStartList();
void deleteSpecificNodeFromList(int data);
void deleteNodeFromEndList();
void addNewNodeAfterSpecificElementInList(int data, int newdata);
void addNewNodeToEndOfList(int data);
void addNewNodeBeforeSpecificElementInList(int data, int newdata);
void menu();
void findSpecificNode(int data);
int main()
{
	for (int i = 1; i <= 15; i++) { addNewNodeBeginList(i); } // adding 15 nodes to list
	
	menu();
	//PrintList();  // Printing LinkedList
	//deleteNodeFromStartList();
	//deleteNodeFromEndList();
	//addNodeEndList(10101);
	//
	//for(int j = 1; j <= 5; j++){ deleteNodeFromEndList(); }
	//addNewNodeBeforeSpecificElementInList(12,11011);
	//addNewNodeAfterSpecificElementInList(140,10111);
	//PrintList();
	//printf("\nReversed List:\n");
	//ReverseList();
	//PrintList();
	
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

	return 0;
}

void menu() {
	printf("\n\n\n\n");
	int choice, data, newdata;

	do {
		printf("\n--- LinkedList Menu ---\n");
		printf("1. Add new node at the beginning\n");
		printf("2. Add new node at the end\n");
		printf("3. Print the list\n");
		printf("4. Reverse the list\n");
		printf("5. Delete node from the start\n");
		printf("6. Delete node from the end\n");
		printf("7. Add new node after a specific element\n");
		printf("8. Add new node before a specific element\n");
		printf("9. Delete Specific Node From List \n");
		printf("10. Find specific Node\n");
		printf("0. Exit\n");

		printf("Enter your choice: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter the data for the new node: ");
			scanf_s("%d", &data);
			addNewNodeBeginList(data);
			break;
		case 2:
			printf("Enter the data for the new node: ");
			scanf_s("%d", &data);
			addNodeEndList(data);
			break;
		case 3:
			printf("The linked list: ");
			PrintList();
			break;
		case 4:
			printf("Reversing the linked list...\n");
			ReverseList();
			break;
		case 5:
			printf("Deleting node from the start...\n");
			deleteNodeFromStartList();
			break;
		case 6:
			printf("Deleting node from the end...\n");
			deleteNodeFromEndList();
			break;
		case 7:
			printf("Enter the data of the existing element: ");
			scanf_s("%d", &data);
			printf("Enter the data for the new node: ");
			scanf_s("%d", &newdata);
			addNewNodeAfterSpecificElementInList(data, newdata);
			break;
		case 8:
			printf("Enter the data of the existing element: ");
			scanf_s("%d", &data);
			printf("Enter the data for the new node: ");
			scanf_s("%d", &newdata);
			addNewNodeBeforeSpecificElementInList(data, newdata);
			break;
		case 9:
			printf("Enter the data of the existing element: ");
			scanf_s("%d", &data);
			deleteSpecificNodeFromList(data);
			break;
		case 10:
			printf("Enter the data of the existing element: ");
			scanf_s("%d", &data);
			findSpecificNode(data);
			break;
		case 0:
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}

	} while (choice != 0);
}

void findSpecificNode(int data)
{
	if (start == NULL) {
		printf("Linked list is empty.\n");
		return;
	}

	struct Node* temp = start;
	int position = 1;
	int found = 0;

	while (temp != NULL) {
		if (temp->data == data) {
			printf("Node with data %d found at position %d.\n", data, position);
			found = 1;
		}
		temp = temp->next;
		position++;
	}

	if (!found) {
		printf("Node with data %d not found in the linked list.\n", data);
	}
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

void ReverseList() {
	struct Node* prev = NULL;
	struct Node* current = start;
	struct Node* next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	start = prev;
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

void addNewNodeAfterSpecificElementInList(int data, int newdata) {
	Node* currentNode = start;
	Node* prevNode = NULL;
	while (currentNode != NULL) {
		if (currentNode->data == data) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = newdata;
			newNode->next = currentNode->next;
			currentNode->next = newNode;
			return;
		}

		prevNode = currentNode;
		currentNode = currentNode->next;
	}

	// If the specific element is not found, add the new node at the beginning of the list
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = start;
	start = newNode;
}


void addNewNodeBeforeSpecificElementInList(int data, int newdata) {
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
			newNode->data = newdata;
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
		printf("Linked list is empty.\n");
		return;
	}

	struct Node* temp = start;
	struct Node* prev = NULL;

	// If the key is found at the start of the list
	if (temp != NULL && temp->data == data) {
		start = temp->next;  // Change the start pointer
		free(temp);  // Free the memory of the node
		printf("Node with key %d deleted successfully.\n", data);
		return;
	}

	// Traverse the list to find the node with the given key
	while (temp != NULL && temp->data != data) {
		prev = temp;
		temp = temp->next;
	}

	// If the key is not found in the list
	if (temp == NULL) {
		printf("Node with key %d not found.\n", data);
		return;
	}

	// Found the node with the given key, delete it
	prev->next = temp->next;
	free(temp);
	printf("Node with key %d deleted successfully.\n", data);
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

