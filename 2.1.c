//주어진 원본 행렬의 전치행렬을 공간복잡도를 고려하여 작성한 알고리즘.

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 8




typedef struct Element { //구조체 생성
    int row, col, val;
} Element;

Element* Transpose_Triple1(Element S_a[])
{
    int rows = S_a[0].row; 
    int cols = S_a[0].col;
    int num = S_a[0].val;

    Element* S_b = (Element*)malloc(sizeof(Element) * (MAX_ELEMENTS));
    S_b[0].row = cols; //전치행렬은 원본행렬의 행과 열이 바뀌므로.
    S_b[0].col = rows;
    S_b[0].val = num;

    if (num > 0) //행렬에 0이 아닌 원소의 개수가 0개 이상일 때,
    {
        int current = 1;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 1; j <= num; j++)
            {
                if (S_a[j].col == i)
                {
                    S_b[current].row = S_a[j].col; //행과 열을 바꿔서 값을 대입함. 
                    S_b[current].col = S_a[j].row;
                    S_b[current].val = S_a[j].val;
                    current++;
                }
            }
        }
    }

    return S_b;
}


void Print_Sparse_Mat(Element arr[]) //구조체 배열을 입력받아 행렬을 출력하는 함수
{
    int rows = arr[0].row;
    int cols = arr[0].col;
    int num = arr[0].val;

    int current = 1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[current].row == i && arr[current].col == j)
            {
                printf("%d ", arr[current].val);
                current++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() { //사용하는 메모리 공간을 줄이기 위해 n*n행렬을 다음과 같은 형태로 변형.

    Element Sparse_A[MAX_ELEMENTS] = { {6,6,7}, //첫 열에는 각각 행의 개수, 열의 개수, 0이아닌 원소의 개수
                                    {0,2,6},  // 0행 2열의 값이 6
                                    {1,0,5},  // 1행 0열의 값이 5
                                    {1,4,7}, //..
                                    {2,3,3}, //..
                                    {4,0,8}, 
                                    {4,1,9},
                                    {5,3,2} };

    Print_Sparse_Mat(Sparse_A); //원래 함수 출력

    printf("====================\n");

    Element* S_b = Transpose_Triple1(Sparse_A); //변형

    Print_Sparse_Mat(S_b); //원본 행렬의 전치 행렬 출력

    return 0;
}
