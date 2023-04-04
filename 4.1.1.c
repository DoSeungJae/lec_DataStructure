#include <stdio.h>
#include <stdlib.h>

#include "MyLinkedList.h"


void Print_Circular_Linked_List(Node* head)
{
	if (head == NULL) return; //��尡 ���������, �Լ� ����
	Node* iter = head;
	int i = 0;
	do
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != head); //���� ���ƿ� ������ �ݺ�
	printf("head:%d", iter->data); //������ ��尡 ���� ����Ǿ����� Ȯ��
	printf("\n");
}


Node* Create_Node(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node)); //?

	newNode->data = newData;
	newNode->link = NULL;

	return newNode;

}



void Append_Node(Node** head, Node* newNode) {

	if (*head == NULL) { //��尡 0���� ��
		*head = newNode; //newNode�� ��尡 �ǰ�
		newNode->link = newNode; //newNode�� newNode�� ����Ų��.  
	}
	else { //������ ��尡 0���� �ƴ� ��,
		Node* tail = *head;  //���� ��尡 ������ġ�� ����.
		while (tail->link != *head) { //������ ���� ��尡 ��� ��尡 �ƴҶ�
			tail = tail->link; //���� ��尡 ���� ���� �̵�.
		}
		//������ ���� ��尡 ��� ����̸�
		//�� ���� ���� ���Ḯ��Ʈ�� ������ �����. �� ����.


		//���� ��尡 �� ��带 ����Ű����. 
		tail->link = newNode;
		newNode->link = *head;
		//newNode�� ���� ���� ���(ó�����)�� �ǹǷ� ���� ���°� ������.

	}
}

