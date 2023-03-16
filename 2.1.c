//�־��� ���� ����� ��ġ����� �������⵵�� ����Ͽ� �ۼ��� �˰���.

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 8




typedef struct Element { //����ü ����
    int row, col, val;
} Element;

Element* Transpose_Triple1(Element S_a[])
{
    int rows = S_a[0].row; 
    int cols = S_a[0].col;
    int num = S_a[0].val;

    Element* S_b = (Element*)malloc(sizeof(Element) * (MAX_ELEMENTS));
    S_b[0].row = cols; //��ġ����� ��������� ��� ���� �ٲ�Ƿ�.
    S_b[0].col = rows;
    S_b[0].val = num;

    if (num > 0) //��Ŀ� 0�� �ƴ� ������ ������ 0�� �̻��� ��,
    {
        int current = 1;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 1; j <= num; j++)
            {
                if (S_a[j].col == i)
                {
                    S_b[current].row = S_a[j].col; //��� ���� �ٲ㼭 ���� ������. 
                    S_b[current].col = S_a[j].row;
                    S_b[current].val = S_a[j].val;
                    current++;
                }
            }
        }
    }

    return S_b;
}


void Print_Sparse_Mat(Element arr[]) //����ü �迭�� �Է¹޾� ����� ����ϴ� �Լ�
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

int main() { //����ϴ� �޸� ������ ���̱� ���� n*n����� ������ ���� ���·� ����.

    Element Sparse_A[MAX_ELEMENTS] = { {6,6,7}, //ù ������ ���� ���� ����, ���� ����, 0�̾ƴ� ������ ����
                                    {0,2,6},  // 0�� 2���� ���� 6
                                    {1,0,5},  // 1�� 0���� ���� 5
                                    {1,4,7}, //..
                                    {2,3,3}, //..
                                    {4,0,8}, 
                                    {4,1,9},
                                    {5,3,2} };

    Print_Sparse_Mat(Sparse_A); //���� �Լ� ���

    printf("====================\n");

    Element* S_b = Transpose_Triple1(Sparse_A); //����

    Print_Sparse_Mat(S_b); //���� ����� ��ġ ��� ���

    return 0;
}
