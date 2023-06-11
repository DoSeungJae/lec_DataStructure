#include "MyGraphMST.hpp"
#include <limits.h>

void ADJ_Create(const char* g_file, int adj_mat[][MAX_VERTICES])
{
	printf("!\n");

	FILE* file;
	fopen_s(&file, g_file, "r"); //read mode
	if (file == NULL) {
		printf("파일이 없습니다. 프로그램을 종료합니다.");
		return;
	}
	while (1) {
		int i, j,w;
		int result = fscanf_s(file, "%d, %d, %d" , &i, &j,&w);
		if (result == EOF) break;
		adj_mat[i][j] = w;
		adj_mat[j][i] = w;
		//printf("!!\n");

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
				else {
					if (adj_mat[i][j] == INT_MAX) printf("INF");
					else printf("%2d ", adj_mat[i][j]);
					
				}		
			}
		}
		printf("\n");
	}
}

void MST_Prim(int weight_mat[][MAX_VERTICES], int MST[][MAX_VERTICES], int n) {

	int selected[MAX_VERTICES] = {0};
	int ec = 0;
	selected[0] = 1; //0 처음 방문.

	while (ec < n - 1) { //횟수가 n번이 되도록.
		int min = INT_MAX;
		int u = 0;
		int v = 0;
		for (int i = 0; i < n; i++) {
			if (selected[i] == 1) { //방문한 정점이라면
				for (int j = 0; j < n; j++) {
					if ((selected[j] == 0) && (min > weight_mat[i][j])) {
						min = weight_mat[i][j];
						u = i;
						v = j;

					}
					//최솟값과 최솟값을 가지는 노드의 위치 저장.
				}
			}
		}
		selected[v] = 1; // 방문처리
		MST[u][v] = weight_mat[u][v];
		MST[v][u] = weight_mat[u][v]; //행렬 리스트에 최솟값을 가지는 간선의 가중치 저장
		ec += 1;

	}
	


}




int main()
{
	const char* file = "g_file3.txt";
	int weight_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int MST[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	for (int i = 0; i < num_of_ver; i++) { //그래프 초기화
		for (int j = 0; j < num_of_ver; j++) {
			if (i != j) {
				weight_mat[i][j] = INT_MAX;
				MST[i][j] = INT_MAX;
			}
		}
	}
	ADJ_Create(file, weight_mat); //가중치 그래프를 인접 행렬로 생성
	printf("가중치 그래프: \n");
	ADJ_Print_Array(weight_mat, num_of_ver); //인접 행렬 출력
	MST_Prim(weight_mat, MST, num_of_ver); //프림 알고리즘을 활용한 MST 구성
	printf("MST: \n");
	ADJ_Print_Array(MST, num_of_ver); //MST 행렬 출력
	return 0;
}