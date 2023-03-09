#include <stdio.h>

void Print_Mat(int arr[][5]);
void Transpos_Mat(int a[][5], int b[][5]);

int main(void) {
	int A[5][5] = { {3,2,6,4,5},
		{8,3,5,9,1},
		{0,3,2,7,9},
		{2,1,5,2,4},
		{5,0,8,2,3} };


	int B[5][5] = { {-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1} };

	Print_Mat(A);

	Transpos_Mat(A, B);

	Print_Mat(B);


	return 0;

}


void Print_Mat(int a[][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");

	}
	printf("\n");
}

void Transpos_Mat(int a[][5], int b[][5]) {


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			b[j][i] = a[i][j];
		}
	}

}


