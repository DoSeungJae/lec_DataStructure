#include <cstdio>
int Seq_Search(int* random_data, int key, int n) { //순차 탐색, 인덱스 순서대로 탐색.
	for (int i = 0; i < n; i++) {
		if (key == random_data[i]) return i;
	}

	return NULL;


}
int Bin_Search(int* random_data, int key, int n) { 
	int left = 0; //시작지점
	int right = n - 1; //인덱스의 끝
	while (left <= right) {
		int mid = (left + right) * 0.5; //중간 값 설정
		if (key == random_data[mid]) return mid; //키 값(탐색 대상)과 중간 값이 같다면 탐색 종료(인덱스 반환)
		if (key > random_data[mid]) left = mid + 1; //키 값(탐색 대상)이 중간 값 보다 크다면 중간 값 ~ 오른쪽 값 으로 범위를 한정하고 다시 탐색; 즉 오른쪽 영역만 재탐색
		else right = mid - 1; //키 값(탐색 대상)이 중간 값 보다 작다면 왼쪽 값 ~ 중간 값으로 범위를 한정하고 다시 탐색; 즉 왼쪽 영역만 재탐색
	}

	return -1; //발견되지 않으면 인덱스 값을 -1로 반환.


}

void swap(int* n1, int* n2) {
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;

}




int Partition(int* random_data, int left, int right) {
	int low = left + 1;
	int high = right;

	int pivot = random_data[left];




	while (low <= high) { //로우가 하이 이하일 때
		while (random_data[high] > pivot) { 
			high -= 1; 

		}//하이가 피봇보다 작을 때 까지 진행

		while ((low <= high) && (random_data[low] <= pivot)) {
			low += 1;
		} //로우가 피봇보다 클 때 까지 진행

		if (low <= high) {
			swap(&random_data[low], &random_data[high]);
			low += 1;
			high -= 1;
		} 

	}
	//로우와 하이가 교차되면 피봇과 하이를 교환하고 하이를 리턴, 후에 하이가 분리 지점이 됨, partition!!
	swap(&random_data[left], &random_data[high]);

	return high;
}



void Quick_Sort(int* random_data, int left, int right) { //left가 right보다 작다면 실행(재귀)
	if (left < right) {
		int q = Partition(random_data, left, right); //분할을 나누고 나눈 분할로 다시 퀵 정렬.
		Quick_Sort(random_data, left, q - 1);
		Quick_Sort(random_data, q + 1, right);

	}
}

int main()
{
	int random_data[] = { 27, 4, 37, 2, 62, 12, 59, 16, 49, 18 };
	int size = sizeof(random_data) / sizeof(int);
	printf("정렬 전 데이터: ");
	for (int i = 0; i < size; i++) { printf("%d ", random_data[i]); }
	int result = Seq_Search(random_data, 49, size);
	printf("\n\n##순차 탐색##\n");
	if (result != -1) printf("값 %d는 %d 번째에 존재합니다.\n\n", random_data[result], result);
	Quick_Sort(random_data, 0, size - 1); //11.2 참고
	printf("정렬 후 데이터: ");
	for (int i = 0; i < size; i++) { printf("%d ", random_data[i]); }
	printf("\n\n##이진 탐색##\n");
	int key = 52;
	result = Bin_Search(random_data, key, size);
	if (result == -1) printf("%d 값은 존재하지 않습니다.\n", key);
	key = 37;
	result = Bin_Search(random_data, key, size);
	if (result != -1) printf("값 %d는 %d 번째에 존재합니다.\n", key, result);
	return 0;
}