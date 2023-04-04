#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList_3.2.h"

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


Node* Get_Node(Node* head, int pos) { //정수를 입력하면 그 번호의 노드의 주소를 반환하는 함수이다.
	Node* cur = head; //현재 노드 즉, 대상 노드이다.

	for (int i = 0; i < pos; i++) { //대상 노드의 번호가 n이라면, 다음 노드로 가는 명령을 n번 수행하면, 타겟 노드에 도달하게된다.

		cur = cur->link;
	}

	return cur; //주소값 반환


}

void Remove_Node(Node** head, Node* targetNode) {




	
	if ((*head)->link == targetNode->link) { 
		//1 헤드 노드를 지울 떄
		*head = (*head)->link;
		free(targetNode);
		//삭제 대상노드, 타겟 노드가 헤드 노드라면 헤드 노드를 앞으로 당겨주고, 타겟노드를 할당해제시킨다.

	}

	//2. 테일 노드를 지울 때

	//3. 가운데 노드를 지울 떄

	else {
		
		
		//타겟 노드에 도달할 때까지 다음노드로 가는 반복문 실행

		Node* cur = *head;
		while (cur->link != targetNode) {
			cur = cur->link;

		}

		//타겟 노드에 도달했을 때 해당 노드가 테일 노드라면 타겟노드의 링크를 NULL로 설정한다.
		if ((cur->link)->link == NULL) {
			cur->link = NULL;

		}
		//타겟 노드가 테일 노드가 아니라면 현재의 노드의 링크를 삭제 대상 노드의 링크로 설정하여 다음 노드들에 대한 정보를 저장한다.
		else {
			cur->link = targetNode->link;


		}
		//메모리 할당 해제
		free(targetNode);
	}

}


void Insert_Node_After(Node* currentNode, Node* newNode) {//대상 노드 다음에 새 노드를 삽입한다.

	newNode->link = currentNode->link;

	currentNode->link = newNode;

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