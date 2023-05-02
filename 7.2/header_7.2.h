
#ifndef __MY_MAX_HEAP_TREE_HPP__
#define __MY_MAX_HEAP_TREE_HPP__
#include <cstdlib>
#include <cstdio>
#include <cmath>
//이진트리 출력 함수
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
//최대 힙 트리 삽입/삭제 함수
void Max_Heap_Insert(int* heap, int* h_size, int key) {
	*h_size += 1;
	int idx = *h_size;
	heap[idx] = key;

	while (idx != 1) {
		if (heap[idx] > heap[idx / 2]) {
			heap[idx] = heap[idx / 2];
			idx /= 2;


		}
		heap[idx] = key;

	}




}

int Max_Heap_Remove(int* heap, int* h_size) {
	int d_key = heap[1];
	heap[1] = heap[*h_size];
	*h_size -= 1;
	int par = 1;
	int idx = 2;
	int temp = heap[*h_size];

	while (idx <= *h_size) {
		if (idx < *h_size && (heap[idx + 1] > heap[idx])) {
			idx += 1;

		}

		if (temp >= heap[idx])break;

		heap[par] = heap[idx];
		par = idx;
		idx = idx * 2;

	}

	heap[par] = temp;
	return d_key;


}
#endif

