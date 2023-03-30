#pragma once
#ifndef __MY_LINKED_LIST_H__
#define __MY_LINKED_LIST_H__
typedef struct Node { //Node ����ü
	int data; //������ �ʵ�
	struct Node* link;// ���� ����� �ּҸ� ����
}Node;
Node* Create_Node(int newData); //��� ����
void Destroy_Node(Node* node); //��� �Ҹ�
void Append_Node(Node** head, Node* newNode);//��� �߰�
void Print_Linked_List(Node* head); //���Ḯ��Ʈ ��� �Լ�

#endif