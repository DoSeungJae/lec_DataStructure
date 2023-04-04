#include <stdio.h>
#include <stdlib.h>

#include "MyLinkedList.h"


void Print_Circular_Linked_List(Node* head)
{
	if (head == NULL) return; //헤드가 비어있으면, 함수 종료
	Node* iter = head;
	int i = 0;
	do
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != head); //헤드로 돌아올 때까지 반복
	printf("head:%d", iter->data); //마지막 노드가 헤드로 연결되었는지 확인
	printf("\n");
}


Node* Create_Node(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node)); //?

	newNode->data = newData;
	newNode->link = NULL;

	return newNode;

}



void Append_Node(Node** head, Node* newNode) {

	if (*head == NULL) { //노드가 0개일 떄
		*head = newNode; //newNode가 헤드가 되고
		newNode->link = newNode; //newNode가 newNode를 가리킨다.  
	}
	else { //기존에 노드가 0개가 아닐 떄,
		Node* tail = *head;  //꼬리 노드가 시작위치로 선언.
		while (tail->link != *head) { //테일의 다음 노드가 헤드 노드가 아닐때
			tail = tail->link; //테일 노드가 다음 노드로 이동.
		}
		//테일의 다음 노드가 헤드 노드이면
		//그 노드는 원형 연결리스트의 마지막 노드임. 즉 꼬리.


		//테일 노드가 새 노드를 가리키게함. 
		tail->link = newNode;
		newNode->link = *head;
		//newNode의 다음 노드는 헤드(처음노드)가 되므로 원형 형태가 유지됨.

	}
}

