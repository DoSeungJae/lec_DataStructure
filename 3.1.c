#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList_3.1.h"



int main(void) {
	Node* head = NULL;
	Node* newNode = NULL;
	newNode = Create_Node(15); //15노드 생성 및 추가
	Append_Node(&head, newNode);
	newNode = Create_Node(31); //31노드 생성 및 추가
	Append_Node(&head, newNode);


	//연결리스트 전체 출력
	Print_Linked_List(head);
	return 0;
}