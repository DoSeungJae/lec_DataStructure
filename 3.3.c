#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList_3.3.h"



int main(void) {
	Node* head = NULL;
	Node* newNode = NULL;
	newNode = Create_Node(15); //15노드 생성 및 추가
	Append_Node(&head, newNode);
	newNode = Create_Node(31); //31노드 생성 및 추가
	Append_Node(&head, newNode);


	newNode = Create_Node(100);
	Append_Node(&head, newNode);

	//연결리스트 전체 출력
	Print_Linked_List(head);


	//Insert_Node_After() 함수 기능 테스트
	Insert_Node_After(Get_Node(head, 0), Create_Node(25));
	Print_Linked_List(head);
	//Remove_Node() 함수 기능 테스트
	Remove_Node(&head, Get_Node(head, 0));
	Print_Linked_List(head);

	Node* rev = Revsere_List(head);
	Print_Linked_List(rev);



	return 0;
}