#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList_4.3.h"

Node* DLL_Create_Node(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->next = NULL;


	newNode->prev = NULL;

	return newNode;

}

void DLL_Destroy_Node(Node* node) {

	if (node != NULL) {
		free(node);
	}

}

void DLL_Append_Node(Node** head, Node* newNode) {
	if ((*head) == NULL) {
		*head = newNode;
	}

	else {

		Node* tail = *head;

		while (tail->next != NULL) {
			tail = tail->next;
		}

		tail->next = newNode;
		newNode->prev = tail;

	}
}


Node* DLL_Get_Node(Node* head, int pos) { //정수를 입력하면 그 번호의 노드의 주소를 반환하는 함수이다.
	Node* cur = head; //현재 노드 즉, 대상 노드이다.

	for (int i = 0; i < pos; i++) { //대상 노드의 번호가 n이라면, 다음 노드로 가는 명령을 n번 수행하면, 타겟 노드에 도달하게된다.

		cur = cur->next;
	}

	return cur; //주소값 반환


}


void DLL_Remove_Node(Node** head, Node* targetNode) {
	if ((*head) == targetNode) {
		(*head) = (*head)->next;
		if((*head)!=NULL) 	(*head)->prev = NULL;
		DLL_Destroy_Node(targetNode);
		
	}

	else {
		Node* cur = *head;
		while (cur->next != targetNode) {
			cur = cur->next;
		}
		
		cur = cur->next;

		if ((cur)->next == NULL) {
			
			//현재 노드는 마지막 노드
			cur->prev->next = NULL;
			cur->prev = NULL;
			DLL_Destroy_Node(cur);
		
		}
		

		else {
			

			Node* temp = cur->prev;
			if (cur->next != NULL) {
				temp->next = cur->next;

				cur->next->prev = temp;

				cur->next = NULL;
				cur->prev = NULL;

			}

			

			DLL_Destroy_Node(cur);


		}
	}


}




void DLL_Insert_Node_After(Node* currentNode, Node* newNode) {//대상 노드 다음에 새 노드를 삽입한다.

	currentNode->next->prev = newNode;
	newNode->next = currentNode->next;

	currentNode->next = newNode;
	newNode->prev = currentNode;


}



void DLL_Print_Linked_List(Node* head)
{
	Node* iter = head;
	int i = 0;
	while (iter != NULL)
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->next;
		if (iter != NULL) printf(" -> ");
		i++;
	}
	printf("\n");

}


void DLL_Print_Linked_List_Reverse(Node* tail)
{
	Node* iter = tail;
	int i = 0;
	while (iter != NULL)
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->prev;
		
		if (iter != NULL) printf(" <-> ");
		
		i++;
	}
	printf("\n");

}