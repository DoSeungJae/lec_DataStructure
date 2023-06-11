#include <iostream>
#include <cstdlib>
#include "MyGraphLL.h"
#include "MyArrayStack.hpp"
#include "../../5.2/5.2/MyArrayStack.hpp"


void ADJ_Degree(int adj_mat[][MAX_VERTICES], int n) { //���� ���.
	for (int i = 0; i < n; i++) { //�� 1�� ����
		int d = 0;
		for (int j = 0; j < n; j++) { //���õ� �࿡ ��� �� �� ���. 
			d = d + adj_mat[i][j];

		}

		printf("���� %d�� ���� : %d\n", i, d);

	}

}

void ADJ_Insert(G_Node** List, int i, int j) { //���� i�� ����� ����j�� ���Ḯ��Ʈ�� ����; ���� ����.
	G_Node* newNode = (G_Node*)malloc(sizeof(G_Node));
	(newNode)->vertex = j;
	(newNode)->link = List[i]; 
	List[i] = newNode;

}

void ADJ_Mat2List(int adj_mat[][MAX_VERTICES], int n, G_Node** List) { //�࿭�� ����Ʈ�� ����.

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (adj_mat[i][j] == 1) {
				ADJ_Insert(List, i, j);

			}
		}
	}
}

void Graph_DFS(G_Node** List, int v) {
	int cur = v;
	int visited[7]={0};
	visited[cur] = 1;

	printf("%d ", cur);

	ArrStack<int> stack;
	do {
		bool vFlag = false; 
		if (visited[cur] == 0) { //�湮���� �ʾ��� �� 
			printf("%d ", cur); 
			visited[cur] = 1; //�湮
			vFlag = true; 
		}
		else {
			G_Node* iter = List[cur]; //iter�� ��� ������ ���� ������ ������ ���� ����Ʈ�� ����.
			while (iter != NULL) {
				if (visited[iter->vertex] == 0) { //������ �湮���� �ʾ��� ��
					
					stack.Stack_Push(cur); //������ ���� ������ ���ÿ� ����.
					cur = iter->vertex;
					vFlag = true;
					break;

				}
				iter = iter->link;	 //�������� �̵�
			}
		}
		if (vFlag == false) { //��������� ��� �湮���� ��
			if (stack.Stack_IsEmpty()) break;
			else cur = stack.Stack_Pop(); //�� ��Ų ���� ���; �ǵ��ư�.

		}

	} while (!stack.Stack_IsEmpty()); 

	printf("\n");


}



void Graph_DFS_Recursive(G_Node** List, int v) {
	static int visited[7] = { 0 };

	G_Node* iter = List[v];
	visited[v] = 1; //�湮 ó��

	printf("%d ", v);

	while (iter != NULL) {
		int temp = iter->vertex;
		if (visited[temp] == 0) Graph_DFS_Recursive(List, temp);
		iter = iter->link;
	}
}

void ADJ_Create(const char* g_file, int adj_mat[][MAX_VERTICES]) //������ �о� ���� ��� ����
{
	FILE* file;
	fopen_s(&file, g_file, "r"); //read mode
	if (file == NULL) {
		printf("������ �����ϴ�. ���α׷��� �����մϴ�.");
		return;
	}
	while (1) {
		int i, j;
		int result = fscanf_s(file, "%d, %d", &i, &j);
		if (result == EOF) break;
		adj_mat[i][j] = 1;
		adj_mat[j][i] = 1;
	}
	fclose(file);
}

void ADJ_Print_Array(int adj_mat[][MAX_VERTICES], int n)
{
	for (int i = -1; i < n; i++) {
		for (int j = -1; j < n; j++) {
			if (i == -1) {
				if (j != -1) printf("%2d ", j);
				else printf(" ");
			}
			else {
				if (j == -1) printf("%2d ", i);
				else printf("%2d ", adj_mat[i][j]);
			}
		}
		printf("\n");
	}
}

void ADJ_Print_List(G_Node** List, int n)
{
	for (int i = 0; i < n; i++) {
		G_Node* iter = List[i];
		printf("Vertex %2d: ", i);
		while (iter != NULL) {
			printf("%2d ", iter->vertex);
			iter = iter->link;
		}
		printf("\n");
	}
}



