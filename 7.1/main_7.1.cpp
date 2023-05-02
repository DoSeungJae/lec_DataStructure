#include <iostream>
#include <cmath>
#include "header_7.1.hpp"

using namespace std;
void PrintTree2Matrix(int** M, int* bTree, int size, int idx, int col, int row, int height) {
	if (idx > size) return;
	M[row][col] = bTree[idx];
	PrintTree2Matrix(M, bTree, size, idx * 2, col - pow(2, height - 2), row + 1, height - 1);
	PrintTree2Matrix(M, bTree, size, idx * 2 + 1, col + pow(2, height - 2), row + 1, height - 1);
}
void TreePrinter(int* bTree, int size) {
	int h = (int)ceil(log2(size + 1));
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
	PrintTree2Matrix(M, bTree, size, 1, col / 2, 0, h);
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


//아래 함수를 구현
void PrintAncestor(int* bTree, int size, int idx) {
	printf("%d의 모든 조상 노드 : ", bTree[idx]);
	while (idx != 1) {
		idx = idx / 2;
		printf("%d" ,bTree[idx]);
		if (idx != 1) printf(" , ");



	}
	printf("%\n");



}
void PrintLeftDescendant(int* bTree, int size, int idx) {
	printf("%d의 모든 왼쪽 후손 노드 : ", bTree[idx]);
	int b = (size+1)/2;
	
	while (idx<b) {
		idx = 2 * idx;
		printf("%d", bTree[idx]);
		if (idx < b) printf(" , ");


	}
	printf("\n");

}
void PrintRightDescendant(int* bTree, int size, int idx) {
	printf("%d의 모든 오른쪽 후손 노드 : ", bTree[idx]);
	while (idx < size) {
		idx = 2 * idx + 1;
		printf("%d", bTree[idx]);
		if (idx < size) printf(" , ");

	}

	printf("\n");



}
int FindNode(int* bTree, int size, int data) {
	int idx = 1;
	
	while (idx != size) {
		if (bTree[idx] == data) {
			return idx;
		}
		else {
			idx += 1;

		}
	}
}


int main() {
	int full_bTree[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 55, 25, 65,75,35,91 };
	int size = sizeof(full_bTree) / sizeof(full_bTree[0]) - 1; //size : 15;



	TreePrinter(full_bTree, size);


	PrintAncestor(full_bTree, size, 14);
	PrintLeftDescendant(full_bTree, size, 1);
	PrintRightDescendant(full_bTree, size, 1);
	printf("%d 노드의 인덱스는 %d 입니다. \n", 30, FindNode(full_bTree, size, 30));

	return 0;
}
