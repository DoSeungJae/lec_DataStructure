#include "MyGraphSP.h"
#include <limits.h>

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


void PrintPath(int* path, int v, int u) {
	if (u == v) {
		printf("%d ", u);
		return;
	}
	PrintPath(path, v, path[u]);
	printf("-> %d ", u);
}

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
		int i, j, w;
		int result = fscanf_s(file, "%d, %d, %d", &i, &j, &w);
		if (result == EOF) break;
		adj_mat[i][j] = w;
		adj_mat[j][i] = w;
		

	}
	fclose(file);
}

void Shortest_Path(int weight_mat[][MAX_VERTICES], int n, int v, int* path) { //0부터 방문
	int distance[MAX_VERTICES];
	int visited[MAX_VERTICES];
	

	for (int i = 0; i < n; i++) {
		distance[i] = weight_mat[v][i];
		path[i] = v;
		visited[i] = 0;

	}

	visited[v] = 1; //0 방문 처리
	distance[v] = 0; //시작 지점이므로 거리 0
	int step = 1; 

	while (step < n) { //정점의 수-1 번 실행
		int min = INT_MAX;
		int k=0;

		
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0 && (distance[i] < min)) {
				min = distance[i];
				k = i;

			}
			//최솟값이 되는 정점과 최솟값 저장.

		}

		visited[k] = 1;
		//인접 정점 중 최소 비용 정점부터 방문.

		for (int u = 0; u < n; u++) {
			if (visited[u] == 0 && weight_mat[k][u]!=INT_MAX) { //&& 오버플로우 방지, 방문하지 않았다면
				if (distance[k] + weight_mat[k][u] < distance[u]) { //k에서 u로 가는 거리가 u로 가는 최단거리보다 짧다면
					distance[u] = distance[k] + weight_mat[k][u]; //k에서 u로 가는 거리가 u로 가는 최단거리가 됨.
					path[u] = k; 

				}

			}
		}

		step += 1;

	}


		

	for (int i = 0; i < n; i++) {
		printf("정점 0 -> 정점 %d: %d\n", i, distance[i]);


	}
	
}

int main() {
	const char* file = "g_file4.txt";
	int weight_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	int* path = new int[num_of_ver];
	for (int i = 0; i < num_of_ver; i++) { //그래프 초기화
		path[i] = 0;
		for (int j = 0; j < num_of_ver; j++) {
			if (i != j) weight_mat[i][j] = INT_MAX;
		}
	}
	ADJ_Create(file, weight_mat); //가중치 그래프를 인접 행렬로 생성
	printf("##가중치 그래프##\n");
	ADJ_Print_Array(weight_mat, num_of_ver); //인접 행렬 출력
	printf("##최단 거리##\n");
	Shortest_Path(weight_mat, num_of_ver, 0, path); //최단거리 계산
	printf("\n##최단 거리 경로##\n");
	for (int i = 0; i < num_of_ver; i++) {
		PrintPath(path, 0, i); //시작 정점0부터 모든 정점 사이의 최단거리 경로
		
		printf("\n");

	}
	return 0;
}