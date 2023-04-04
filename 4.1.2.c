#include <stdio.h>
#include <stdlib.h>

#include "MyLinkedList.h"


void Print_Circular_Linked_List_T(Node* tail)

{

	if (tail == NULL) return; //테일이 비어있으면, 함수 종료
	Node* iter = tail; //실행 노드가 테일 노드부터 시작하므로
	int i = 0;
	iter = iter->link; //노드를 한칸 앞으로 보내서 헤드노드부터 시작하게함.
	do
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != tail->link); //헤드로 돌아올 때까지 반복; 테일의 다음 노드가 헤드 노드이므로 tail->link로
	printf("head:%d", iter->data); //마지막 노드가 헤드로 연결되었는지 확인
	printf("\n");


}


Node* Create_Node(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->link = NULL;

	return newNode;

}


void Append_Node_T(Node** tail, Node* newNode) {

	if (*tail == NULL) { //테일 노드가 없다는 것은 연결리스트에서 노드의 개수가 0개이므로 
		*tail = newNode; //새 노드가 테일 노드가 되며
		newNode->link = newNode; //원형리스트이므로 첫번째 노드는 자기 자신을 가리킨다.

	}

	else {//원형리스트에서 노드의 개수가 1개 이상일 때
		newNode->link = (*tail)->link; //새 노드가 가리키는 다음 노드는 마지막 노드가 가리키는 노드(처음노드/헤드)가 된다.
		(*tail)->link = newNode; //그리고 테일이 새 노드를 가리키게 한다.
		(*tail) = newNode; //마지막 노드 즉 새로 추가된 노드가 테일이 된다.

	}


}

