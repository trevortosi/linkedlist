#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node* addToFront(Node *list, int value);

void insertAfter(Node *prevNode, int value);

void printList(Node *list);

Node* addToBack(Node *list, int value);

void deleteNode(Node *head, int key);

int main() {

	Node *list = NULL;


	list = addToBack(list, 6);
	addToBack(list, 13);
	addToBack(list, 51);
	

	

	printf("\nList before insertions");
	printList(list);


	list = addToFront(list, 23);

	insertAfter(list->next, 900);

	addToBack(list, 40);

	printf("\nList after insertions");
	printList(list);

	deleteNode(list, 900);

	printList(list);

}



Node* addToFront(Node *list, int data) {
	Node *pNew = (Node *)malloc(sizeof(Node));


	pNew->data = data;
	pNew->next = NULL;

	if (list == NULL) {
		list = pNew;

	}
	else {
		pNew->next = list;
		list = pNew;
	}

	return list;
}

void insertAfter(Node *prevNode, int value) {

	if (prevNode == NULL) {
		printf("\nPrevious node can't be null");
		return;
	}

	else {
		Node *pNew = (Node *) malloc(sizeof(Node)); 

		pNew->data = value;
		pNew->next = prevNode->next;
		prevNode->next = pNew;
	}

	
}




Node* addToBack(Node *list, int value) {



	Node *helpPtr = list;


	if (list == NULL) {

	Node *pNew = (Node*)malloc(sizeof(Node));

	pNew->data = value;
	pNew->next = NULL;
	list = pNew;
	return list;

	}
	while (helpPtr->next != NULL) {
		helpPtr = helpPtr->next;
	}

	Node *pNew = (Node*)malloc(sizeof(Node));

	pNew->data = value;
	pNew->next = NULL;

	helpPtr->next = pNew;

}


void deleteNode(Node *head, int key) {
	Node *helpPtr = head;
	Node *prev = NULL;

	if (helpPtr != NULL && helpPtr->data == key) {
		head = helpPtr->next;
		free(helpPtr);
		return;
	}

	while (helpPtr->next != NULL && helpPtr->data != key) {
		prev = helpPtr;
		helpPtr = helpPtr->next;
	}

	//if helpPtr is null, we know the value isn't in the linked list
	if (helpPtr == NULL) {
		return;
	}

	prev->next = helpPtr->next;



	free(helpPtr);


}










void printList(Node *list) {

	Node *helpPtr = list;

	while (helpPtr->next != NULL) {
		printf("\n%d", helpPtr->data);
		helpPtr = helpPtr->next;

	}

	printf("\n%d\n", helpPtr->data);


}