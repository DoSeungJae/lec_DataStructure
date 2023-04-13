#ifndef __MY_LINKED_LIST_H__
#define __MY_LINKED_LIST_H__
typedef struct Node { //Node ����ü
	int data; //������ �ʵ�
	struct Node* link;// ���� ����� �ּҸ� ����
}Node;
Node* Create_Node(int newData); //��� ����
void Print_Linked_List(Node* head);
void Append_Node(Node** head, Node* newNode);//��� �߰�

Node* Merge_List(Node* head_a, Node* head_b);




#endif