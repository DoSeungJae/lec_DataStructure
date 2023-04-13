#include <stdio.h>
#include <stdlib.h>

#include "MyLinkedList_4.2.h"



Node* Create_Node(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->link = NULL;

	return newNode;

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

void Append_Node(Node** head, Node* newNode) {
	if ((*head) == NULL) {
		(*head) = newNode;
	}

	else {

		Node* tail = *head;

		while (tail->link != NULL) {
			tail = tail->link;
		}

		tail->link = newNode;

	}
}


Node* Merge_List(Node* head_a, Node* head_b) {
	Node* head_c = NULL;

	while (head_a != NULL && head_b != NULL) {
		if (head_a->data < head_b->data) {
			Append_Node(&head_c, Create_Node(head_a->data));
			head_a = head_a->link;
		}
		else {
			Append_Node(&head_c, Create_Node(head_b->data));
			head_b = head_b->link;
		}
	}

	while (head_a != NULL) {
		Append_Node(&head_c, Create_Node(head_a->data));
		head_a = head_a->link;


	}

	while (head_b = NULL) {
		Append_Node(&head_c, Create_Node(head_b->data));
		head_b = head_b->link;

	}

	return head_c;

}