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


Node* Get_Node(Node* head, int pos) { //������ �Է��ϸ� �� ��ȣ�� ����� �ּҸ� ��ȯ�ϴ� �Լ��̴�.
	Node* cur = head; //���� ��� ��, ��� ����̴�.

	for (int i = 0; i < pos; i++) { //��� ����� ��ȣ�� n�̶��, ���� ���� ���� ����� n�� �����ϸ�, Ÿ�� ��忡 �����ϰԵȴ�.

		cur = cur->link;
	}

	return cur; //�ּҰ� ��ȯ


}

void Remove_Node(Node** head, Node* targetNode) {




	
	if ((*head)->link == targetNode->link) { 
		//1 ��� ��带 ���� ��
		*head = (*head)->link;
		free(targetNode);
		//���� �����, Ÿ�� ��尡 ��� ����� ��� ��带 ������ ����ְ�, Ÿ�ٳ�带 �Ҵ�������Ų��.

	}

	//2. ���� ��带 ���� ��

	//3. ��� ��带 ���� ��

	else {
		
		
		//Ÿ�� ��忡 ������ ������ �������� ���� �ݺ��� ����

		Node* cur = *head;
		while (cur->link != targetNode) {
			cur = cur->link;

		}

		//Ÿ�� ��忡 �������� �� �ش� ��尡 ���� ����� Ÿ�ٳ���� ��ũ�� NULL�� �����Ѵ�.
		if ((cur->link)->link == NULL) {
			cur->link = NULL;

		}
		//Ÿ�� ��尡 ���� ��尡 �ƴ϶�� ������ ����� ��ũ�� ���� ��� ����� ��ũ�� �����Ͽ� ���� ���鿡 ���� ������ �����Ѵ�.
		else {
			cur->link = targetNode->link;


		}
		//�޸� �Ҵ� ����
		free(targetNode);
	}

}


void Insert_Node_After(Node* currentNode, Node* newNode) {//��� ��� ������ �� ��带 �����Ѵ�.

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