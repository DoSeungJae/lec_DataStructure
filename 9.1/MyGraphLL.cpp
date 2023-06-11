#include <iostream>
#include <cstdlib>
#include "MyGraphLL.h"
#include "MyArrayStack.hpp"
#include "../../5.2/5.2/MyArrayStack.hpp"


void ADJ_Degree(int adj_mat[][MAX_VERTICES], int n) { //차수 계산.
	for (int i = 0; i < n; i++) { //행 1개 선택
		int d = 0;
		for (int j = 0; j < n; j++) { //선택된 행에 모든 열 값 계산. 
			d = d + adj_mat[i][j];

		}

		printf("정점 %d의 차수 : %d\n", i, d);

	}

}

void ADJ_Insert(G_Node** List, int i, int j) { //정점 i에 연결된 정점j를 연결리스트로 연결; 순서 무관.
	G_Node* newNode = (G_Node*)malloc(sizeof(G_Node));
	(newNode)->vertex = j;
	(newNode)->link = List[i]; 
	List[i] = newNode;

}

void ADJ_Mat2List(int adj_mat[][MAX_VERTICES], int n, G_Node** List) { //행열을 리스트에 넣음.

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
		if (visited[cur] == 0) { //방문하지 않았을 때 
			printf("%d ", cur); 
			visited[cur] = 1; //방문
			vFlag = true; 
		}
		else {
			G_Node* iter = List[cur]; //iter에 대상 정점의 인접 정점을 포함한 연결 리스트를 저장.
			while (iter != NULL) {
				if (visited[iter->vertex] == 0) { //정점을 방문하지 않았을 때
					
					stack.Stack_Push(cur); //정점에 대한 정보를 스택에 저장.
					cur = iter->vertex;
					vFlag = true;
					break;

				}
				iter = iter->link;	 //다음으로 이동
			}
		}
		if (vFlag == false) { //인접행렬을 모두 방문했을 때
			if (stack.Stack_IsEmpty()) break;
			else cur = stack.Stack_Pop(); //팝 시킨 것을 출력; 되돌아감.

		}

	} while (!stack.Stack_IsEmpty()); 

	printf("\n");


}



void Graph_DFS_Recursive(G_Node** List, int v) {
	static int visited[7] = { 0 };

	G_Node* iter = List[v];
	visited[v] = 1; //방문 처리

	printf("%d ", v);

	while (iter != NULL) {
		int temp = iter->vertex;
		if (visited[temp] == 0) Graph_DFS_Recursive(List, temp);
		iter = iter->link;
	}
}

void ADJ_Create(const char* g_file, int adj_mat[][MAX_VERTICES]) //파일을 읽어 인접 행렬 생성
{
	FILE* file;
	fopen_s(&file, g_file, "r"); //read mode
	if (file == NULL) {
		printf("파일이 없습니다. 프로그램을 종료합니다.");
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



