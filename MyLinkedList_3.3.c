#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList_3.3.h"

Node* Create_Node(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node)); 

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


Node* Get_Node(Node* head, int pos) { 


	Node* cur = head;

	for (int i = 0; i < pos; i++) {

		cur = cur->link;
	}

	return cur;


}

void Remove_Node(Node** head, Node* targetNode) {




	//1 헤드 노드를 지울 떄
	if ((*head)->link == targetNode->link) {

		*head = (*head)->link;
		free(targetNode);

	}

	//2. 테일 노드를 지울 때

	//3. 가운데 노드를 지울 떄

	else {

		Node* cur = *head;
		while (cur->link != targetNode) {
			cur = cur->link;

		}
		if ((cur->link)->link == NULL) {
			cur->link = NULL;

		}
		else {
			cur->link = targetNode->link;


		}

		free(targetNode);
	}

}



void Insert_Node_After(Node* currentNode, Node* newNode) {//.h

	newNode->link = currentNode->link;

	currentNode->link = newNode;

}

Node* Revsere_List(Node* head) {
	//인자로 넣은 연결리스트와 순서가 반대되는 역 연결리스트를 생성하는 함수이다.
	
	Node* p = head;
	Node* q = NULL;
	Node* r = NULL;
	while (p != NULL) {
		r = q; //r에 q값을 넣음
		q = p; //q에 p값을 넣음
		p = p->link; //p가 다음 노드로 이동함
		q->link = r; //q의 다음노드를 r로 설정함.
	}

	return q;

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