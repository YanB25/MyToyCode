#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void CountSort(int*, int, int, int);
int main() {
	freopen("input", "r", stdin);
	int n;
	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n;++i) {
		scanf("%d", &arr[i]);
	}
	CountSort(arr,n, 0, 1000);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", arr[i]);
	}
	free(arr);
	return 0;
}

void CountSort(int* arr, int n, int min, int max) {
	const int range = max - min + 1;
	int* tmp = malloc(sizeof(int) * n);//
	int* count = malloc(sizeof(int) * (range + 5));
	memset(tmp , 0, sizeof(int) * n);
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; ++i) {
		count[arr[i] - min + 1]++;
	}
	for (int i = 0; i < range + 1; ++i) {
		count[i + 1] += count[i];
	}
	for (int i = 0; i < n; ++i) {
		tmp[count[arr[i] - min]++] = arr[i];
	}
	for (int i = 0; i < n; ++i) {
		arr[i] = tmp[i];
	}
	free(tmp);
	free(count);
}
