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
		printf("������ �����ϴ�. ���α׷��� �����մϴ�.");
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

void Shortest_Path(int weight_mat[][MAX_VERTICES], int n, int v, int* path) { //0���� �湮
	int distance[MAX_VERTICES];
	int visited[MAX_VERTICES];
	

	for (int i = 0; i < n; i++) {
		distance[i] = weight_mat[v][i];
		path[i] = v;
		visited[i] = 0;

	}

	visited[v] = 1; //0 �湮 ó��
	distance[v] = 0; //���� �����̹Ƿ� �Ÿ� 0
	int step = 1; 

	while (step < n) { //������ ��-1 �� ����
		int min = INT_MAX;
		int k=0;

		
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0 && (distance[i] < min)) {
				min = distance[i];
				k = i;

			}
			//�ּڰ��� �Ǵ� ������ �ּڰ� ����.

		}

		visited[k] = 1;
		//���� ���� �� �ּ� ��� �������� �湮.

		for (int u = 0; u < n; u++) {
			if (visited[u] == 0 && weight_mat[k][u]!=INT_MAX) { //&& �����÷ο� ����, �湮���� �ʾҴٸ�
				if (distance[k] + weight_mat[k][u] < distance[u]) { //k���� u�� ���� �Ÿ��� u�� ���� �ִܰŸ����� ª�ٸ�
					distance[u] = distance[k] + weight_mat[k][u]; //k���� u�� ���� �Ÿ��� u�� ���� �ִܰŸ��� ��.
					path[u] = k; 

				}

			}
		}

		step += 1;

	}


		

	for (int i = 0; i < n; i++) {
		printf("���� 0 -> ���� %d: %d\n", i, distance[i]);


	}
	
}

int main() {
	const char* file = "g_file4.txt";
	int weight_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	int* path = new int[num_of_ver];
	for (int i = 0; i < num_of_ver; i++) { //�׷��� �ʱ�ȭ
		path[i] = 0;
		for (int j = 0; j < num_of_ver; j++) {
			if (i != j) weight_mat[i][j] = INT_MAX;
		}
	}
	ADJ_Create(file, weight_mat); //����ġ �׷����� ���� ��ķ� ����
	printf("##����ġ �׷���##\n");
	ADJ_Print_Array(weight_mat, num_of_ver); //���� ��� ���
	printf("##�ִ� �Ÿ�##\n");
	Shortest_Path(weight_mat, num_of_ver, 0, path); //�ִܰŸ� ���
	printf("\n##�ִ� �Ÿ� ���##\n");
	for (int i = 0; i < num_of_ver; i++) {
		PrintPath(path, 0, i); //���� ����0���� ��� ���� ������ �ִܰŸ� ���
		
		printf("\n");

	}
	return 0;
}