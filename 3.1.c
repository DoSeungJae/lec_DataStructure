#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList_3.1.h"



int main(void) {
	Node* head = NULL;
	Node* newNode = NULL;
	newNode = Create_Node(15); //15��� ���� �� �߰�
	Append_Node(&head, newNode);
	newNode = Create_Node(31); //31��� ���� �� �߰�
	Append_Node(&head, newNode);


	//���Ḯ��Ʈ ��ü ���
	Print_Linked_List(head);
	return 0;
}