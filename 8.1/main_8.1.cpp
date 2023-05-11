#include "MyBinarySearchTree.hpp"
#include <cstdlib>
#include <cstdio>


BT_Node* BST_Create_Node(int newData) {
	BT_Node* newNode = (BT_Node*)malloc(sizeof(BT_Node)); //메모리 동적 할당
	newNode->data = newData;
	newNode->left = NULL; //새로운 트리 노드를 생성할 때, 왼쪽 자식과 오른쪽 자식을 널처리
	newNode->right = NULL;

	return newNode;


}

void BST_Destroy_Node(BT_Node* node) {
	if (node != NULL) {
		free(node); //삭제할 노드가 널값이 아니라면 할당 해제
	}

}

int BST_Min(BT_Node* root) {
	if (root == NULL) exit(1);
	BT_Node* iter = (BT_Node*)malloc(sizeof(BT_Node));
	iter = root;
	while (iter->left != NULL) {
		iter = iter->left;
	}

	return iter->data;
}

int BST_Max(BT_Node* root) {
	if (root == NULL) exit(1);
	BT_Node* iter = (BT_Node*)malloc(sizeof(BT_Node));
	iter = root;
	while (iter->right != NULL) {
		iter = iter->right;

	}

	return iter->data;

}

BT_Node* BST_Search(BT_Node* root, int target) {
	if (root == NULL) return NULL;
	if (target == root->data) return root;
	if (target < root->data) return BST_Search(root->left, target);
	else return BST_Search(root->right, target);
}

void BST_Insert(BT_Node** root, int key) {

	BT_Node* newNode = (BT_Node*)malloc(sizeof(BT_Node));
	newNode = BST_Create_Node(key);
	if ((*root) == NULL) {
		(*root) = newNode;
	}
	else {
		BT_Node* parent = (BT_Node*)malloc(sizeof(BT_Node));
		parent = NULL;
		BT_Node* iter = (BT_Node*)malloc(sizeof(BT_Node));
		iter = *root;

		while (iter != NULL) {
			parent = iter;
			
			if (key == iter->data) return;


			if (key < iter->data) iter = iter->left;
			else iter = iter->right;
		}

		if (key < parent->data) parent->left = newNode;
		else parent->right = newNode;


	}
}



void BST_TreePrinter(BT_Node* root)
{
	int h = BST_Height(root);
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
	BST_PrintTree2Matrix(M, root, col / 2, 0, h);
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

void BST_Delete(BT_Node** root, int key) {
	BT_Node* vRoot = (BT_Node*)malloc(sizeof(BT_Node));
	vRoot->right = *root;
	BT_Node* iter = (BT_Node*)malloc(sizeof(BT_Node));
	BT_Node* parent = (BT_Node*)malloc(sizeof(BT_Node));
	iter = *root;
	parent = vRoot;

	while (iter != NULL && iter->data != key) {
		parent = iter;
		if (key < iter->data) iter = iter->left;
		else iter = iter->right;

	}
	if (iter == NULL) return;

	BT_Node* delNode = (BT_Node*)malloc(sizeof(BT_Node));
	delNode = iter;

	if (delNode->left == NULL && delNode->right == NULL) {
		if (parent->left == delNode) parent->left = NULL;
		else parent->right = NULL;
	}

	else if (delNode->left == NULL || delNode->right == NULL) {
		BT_Node* child= (BT_Node*)malloc(sizeof(BT_Node));

		if (delNode->left == NULL) child = delNode->right;
		else child = delNode->left;
		if (parent->left == delNode) parent->left = child;
		else parent->right = child;

	}

	else {
		BT_Node* successor = (BT_Node*)malloc(sizeof(BT_Node));
		BT_Node* pSuccessor = (BT_Node*)malloc(sizeof(BT_Node));
		

		successor = delNode->right;
		pSuccessor = delNode;

		while (successor->left != NULL) {
			pSuccessor = successor;
			successor = successor->left;

		}

		delNode->data = successor->data;
		if (pSuccessor->left == successor) pSuccessor->left = successor->right;
		else pSuccessor->right = successor->right;

		delNode = successor;

	
			

	}

	if (vRoot->right != *root) {
		*root = vRoot->right;
	}

	BST_Destroy_Node(vRoot);
	BST_Destroy_Node(delNode);


	
}


int BST_Height(BT_Node* root) {
	if (root == NULL)
		return 0;
	return MAX(BST_Height(root->left), BST_Height(root->right)) + 1;
}
void BST_PrintTree2Matrix(int** M, BT_Node* bt_node, int col, int row, int height) {
	if (bt_node == NULL) return;
	M[row][col] = bt_node->data;
	BST_PrintTree2Matrix(M, bt_node->left, col - pow(2, height - 2), row + 1, height - 1);
	BST_PrintTree2Matrix(M, bt_node->right, col + pow(2, height - 2), row + 1, height - 1);
}

int main() {
	BT_Node* root = NULL;
	//이진 탐색 트리 구성
	BST_Insert(&root, 50);
	BST_Insert(&root, 35);
	BST_Insert(&root, 70);
	BST_Insert(&root, 6);
	BST_Insert(&root, 40);
	BST_Insert(&root, 36);
	BST_Insert(&root, 45);
	BST_Insert(&root, 38);
	BST_Insert(&root, 37);
	BST_TreePrinter(root);

	//기본 연산 기능 테스트
	printf("Min value: %d \n", BST_Min(root));
	printf("Max value: %d \n", BST_Max(root));
	printf("Search 36 node: %d \n", BST_Search(root, 36)->data);
	//삭제 테스트
	BST_Delete(&root, 35);
	BST_Delete(&root, 38);
	BST_Delete(&root, 6);
	BST_Delete(&root, 50); //35, 38, 6, 50 노드 삭제 테스트 진행


	BST_Insert(&root, 39);
	BST_TreePrinter(root);
	return 0;
}