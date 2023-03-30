#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList_3.1.h"

Node* Create_Node(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node)); //?

	newNode->data = newData;
	newNode->link = NULL;

	return newNode;

}

void Destroy_Node(Node* node) {

	if (node != NULL) {
		free(node);
	}

}

void Append_Node(Node** head, Node* newNode) {
	if ((*head) == NULL) {
		*head = newNode;
	}

	else {

		Node* tail = *head;

		while (tail->link != NULL) {
			tail = tail->link;
		}

		tail->link = newNode;

	}
}




void Print_Linked_List(Node* head)
{
	Node* iter = head;
	int i = 0;
	while (iter != NULL)
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	}
	printf("\n");

}