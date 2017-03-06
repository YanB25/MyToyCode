#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int*, int*);
void QuickSort(int*, int, int);
int main()
{
	freopen("input", "r", stdin);
	int n;
	scanf("%d", &n);
	int *arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n;++i) scanf("%d", &arr[i]);
	int btime = clock();
	QuickSort(arr, 0, n - 1);
	printf("%ld \n", clock() - btime);
	//for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
	free(arr);
	return 0;
}
void QuickSort(int* arr, int beg ,int end)
{
	if (beg >= end) return;
	int index = beg;
	int i2 = beg;
	int pivot = arr[end];
	for (int i = beg; i < end; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(&arr[i], &arr[index++]);
			if (arr[i] != pivot) i2++;
		}
	}
	swap(&arr[index], &arr[end]);
	QuickSort(arr, beg, i2 - 1);
	QuickSort(arr, index + 1, end);
}

void swap(int* a,int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
