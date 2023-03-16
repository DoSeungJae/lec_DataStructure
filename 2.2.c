#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 8



typedef struct Element {
    int row, col, val;
} Element;

Element* Transpose_Triple2(Element S_a[])
{
    int rows = S_a[0].row;
    int cols = S_a[0].col;
    int num = S_a[0].val;

    Element* S_b = (Element*)malloc(sizeof(Element) * (MAX_ELEMENTS));
    S_b[0].row = cols;
    S_b[0].col = rows;
    S_b[0].val = num;

    if (num > 0)
    {
        int row[MAX_ELEMENTS] = { 0 };
        for (int i = 1; i <= num; i++)
            row[S_a[i].col]++;

        int pos[MAX_ELEMENTS] = { 0 };
        pos[0] = 1;
        for (int i = 1; i < cols; i++)
            pos[i] = pos[i - 1] + row[i - 1];

        for (int i = 1; i <= num; i++)
        {
            int abs_pos = pos[S_a[i].col];
            pos[S_a[i].col]++;
            S_b[abs_pos].row = S_a[i].col;
            S_b[abs_pos].col = S_a[i].row;
            S_b[abs_pos].val = S_a[i].val;
        }
    }

    return S_b;
}


void Print_Sparse_Mat(Element arr[])
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

int main() {
    Element Sparse_A[MAX_ELEMENTS] = { {6,6,7},
                                    {0,2,6},
                                    {1,0,5},
                                    {1,4,7},
                                    {2,3,3},
                                    {4,0,8},
                                    {4,1,9},
                                    {5,3,2} };

    Print_Sparse_Mat(Sparse_A);

    printf("====================\n");

    Element* S_b = Transpose_Triple2(Sparse_A);

    Print_Sparse_Mat(S_b);

    return 0;
}
