#include "MyGraphMST.hpp"
#include <limits.h>

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
	selected[0] = 1; //0 ó�� �湮.

	while (ec < n - 1) { //Ƚ���� n���� �ǵ���.
		int min = INT_MAX;
		int u = 0;
		int v = 0;
		for (int i = 0; i < n; i++) {
			if (selected[i] == 1) { //�湮�� �����̶��
				for (int j = 0; j < n; j++) {
					if ((selected[j] == 0) && (min > weight_mat[i][j])) {
						min = weight_mat[i][j];
						u = i;
						v = j;

					}
					//�ּڰ��� �ּڰ��� ������ ����� ��ġ ����.
				}
			}
		}
		selected[v] = 1; // �湮ó��
		MST[u][v] = weight_mat[u][v];
		MST[v][u] = weight_mat[u][v]; //��� ����Ʈ�� �ּڰ��� ������ ������ ����ġ ����
		ec += 1;

	}
	


}




int main()
{
	const char* file = "g_file3.txt";
	int weight_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int MST[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	for (int i = 0; i < num_of_ver; i++) { //�׷��� �ʱ�ȭ
		for (int j = 0; j < num_of_ver; j++) {
			if (i != j) {
				weight_mat[i][j] = INT_MAX;
				MST[i][j] = INT_MAX;
			}
		}
	}
	ADJ_Create(file, weight_mat); //����ġ �׷����� ���� ��ķ� ����
	printf("����ġ �׷���: \n");
	ADJ_Print_Array(weight_mat, num_of_ver); //���� ��� ���
	MST_Prim(weight_mat, MST, num_of_ver); //���� �˰����� Ȱ���� MST ����
	printf("MST: \n");
	ADJ_Print_Array(MST, num_of_ver); //MST ��� ���
	return 0;
}