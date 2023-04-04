#include <stdio.h>
#include <stdlib.h>

#include "MyLinkedList.h"


void Print_Circular_Linked_List_T(Node* tail)

{

	if (tail == NULL) return; //������ ���������, �Լ� ����
	Node* iter = tail; //���� ��尡 ���� ������ �����ϹǷ�
	int i = 0;
	iter = iter->link; //��带 ��ĭ ������ ������ �������� �����ϰ���.
	do
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != tail->link); //���� ���ƿ� ������ �ݺ�; ������ ���� ��尡 ��� ����̹Ƿ� tail->link��
	printf("head:%d", iter->data); //������ ��尡 ���� ����Ǿ����� Ȯ��
	printf("\n");


}


Node* Create_Node(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->link = NULL;

	return newNode;

}


void Append_Node_T(Node** tail, Node* newNode) {

	if (*tail == NULL) { //���� ��尡 ���ٴ� ���� ���Ḯ��Ʈ���� ����� ������ 0���̹Ƿ� 
		*tail = newNode; //�� ��尡 ���� ��尡 �Ǹ�
		newNode->link = newNode; //��������Ʈ�̹Ƿ� ù��° ���� �ڱ� �ڽ��� ����Ų��.

	}

	else {//��������Ʈ���� ����� ������ 1�� �̻��� ��
		newNode->link = (*tail)->link; //�� ��尡 ����Ű�� ���� ���� ������ ��尡 ����Ű�� ���(ó�����/���)�� �ȴ�.
		(*tail)->link = newNode; //�׸��� ������ �� ��带 ����Ű�� �Ѵ�.
		(*tail) = newNode; //������ ��� �� ���� �߰��� ��尡 ������ �ȴ�.

	}


}

