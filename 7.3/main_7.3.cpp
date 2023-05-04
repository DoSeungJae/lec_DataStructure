#include <cstdlib>
#include <cstdio>
#include "MyBinaryTree_7.3.hpp"

BT_Node* BT_Create_Node(int newData) {
	BT_Node* newNode = (BT_Node*)malloc(sizeof(BT_Node)); //메모리 동적 할당
	newNode->data = newData;
	newNode->left = NULL; //새로운 트리 노드를 생성할 때, 왼쪽 자식과 오른쪽 자식을 널처리
	newNode->right = NULL;

	return newNode;



}

void BT_Destroy_Node(BT_Node* node) {
	if (node != NULL) {
		free(node); //삭제할 노드가 널값이 아니라면 할당 해제
	}

}

void BT_Make_Left_Sub_Tree(BT_Node* parent, BT_Node* sub) {
	if (parent->left != NULL) {
		BT_Destroy_Node(parent->left); //sub 노드가 부모의 왼쪽 자식이 됨.

	}
	parent->left = sub;


}


void BT_Make_Right_Sub_Tree(BT_Node* parent, BT_Node* sub) {
	if (parent->right != NULL) {
		BT_Destroy_Node(parent->right); //sub 노드가 부모의 오른쪽 자식이 됨.

	}
	parent->right = sub;
}

void BT_Preorder_Traversal(BT_Node* node) { //전위 연산 ; 루트 노드를 먼저 출력하고, L -> R
	if (node != NULL) {
		printf("%d ",node->data); //
		BT_Preorder_Traversal(node->left);
		BT_Preorder_Traversal(node->right);


	}
}

void BT_Inorder_Traversal(BT_Node* node) { //중위 연산 ; L -> 루트 -> R 순서대로 출력
	if (node != NULL) {
		BT_Inorder_Traversal(node->left);
		printf("%d ",node->data);
		BT_Inorder_Traversal(node->right);


	}
}

void BT_Postorder_Traversal(BT_Node* node) { //후위 연산 : L -> R -> 루트 순으로 출력
	if (node != NULL) {
		BT_Postorder_Traversal(node->left);
		BT_Postorder_Traversal(node->right);

		printf("%d ",node->data);



	}
}

void BT_Count_Node(BT_Node* node, int* count) { //노드의 개수를 포인터 변수로 표현

	if (node != NULL) {
		*count += 1;
		BT_Count_Node(node->left,count);
		BT_Count_Node(node->right,count);


	}
}


void BT_Count_Leaf(BT_Node* node, int* count) { //터미널 노드의 개수를 포인터 변수로 표현
	if (node != NULL) {
		BT_Count_Leaf(node->left,count);
		if (node->left == NULL && node->right == NULL) {
			*count += 1;
		}
		BT_Count_Leaf(node->right,count);

	}



}

void BT_TreePrinter(BT_Node* root) 
{
	int h = BT_Height(root);
	int col = (1 << h) - 1;
	int** M = new int* [h];
	for (int i = 0; i < h; i++) {
		M[i] = new int[col];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] = 0;
		}
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
	BT_PrintTree2Matrix(M, root, col / 2, 0, h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			if (M[i][j] == 0)
				printf(" ");

			else
				printf("%2d", M[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
}


int BT_Height(BT_Node* root) {
	if (root == NULL)
		return 0;
	return MAX(BT_Height(root->left), BT_Height(root->right)) + 1;
}
void BT_PrintTree2Matrix(int** M, BT_Node* bt_node, int col, int row, int height) {
	if (bt_node == NULL) return;
	M[row][col] = bt_node->data;
	BT_PrintTree2Matrix(M, bt_node->left, col - pow(2, height - 2), row + 1, height - 1);
	BT_PrintTree2Matrix(M, bt_node->right, col + pow(2, height - 2), row + 1, height - 1);
}




int main()
{
	BT_Node* bt_node1 = BT_Create_Node(5);
	BT_Node* bt_node2 = BT_Create_Node(7);
	BT_Node* bt_node3 = BT_Create_Node(6);
	BT_Node* bt_node4 = BT_Create_Node(9);
	BT_Node* bt_node5 = BT_Create_Node(8);
	BT_Node* bt_node6 = BT_Create_Node(2);
	//이진 트리 구성
	BT_Make_Left_Sub_Tree(bt_node1, bt_node2);
	BT_Make_Right_Sub_Tree(bt_node1, bt_node3);
	BT_Make_Left_Sub_Tree(bt_node2, bt_node4);
	BT_Make_Left_Sub_Tree(bt_node3, bt_node5);
	BT_Make_Right_Sub_Tree(bt_node4, bt_node6);
	//이진 트리 출력
	BT_TreePrinter(bt_node1);
	//순회 출력
	printf("Preorder: ");
	BT_Preorder_Traversal(bt_node1);
	printf("\n");

	printf("Inorder: ");
	BT_Inorder_Traversal(bt_node1);
	printf("\n");
	printf("Postorder: ");
	BT_Postorder_Traversal(bt_node1);
	printf("\n");
	//이진 트리의 노드 수를 계산
	int cnt = 0;
	BT_Count_Node(bt_node1, &cnt);
	printf("Total nodes: %d \n", cnt);
	//이진 트리의 리프 노드 수를 계산
	cnt = 0;
	BT_Count_Leaf(bt_node1, &cnt);
	printf("Total leaf nodes: %d \n", cnt);
	return 0;
}

