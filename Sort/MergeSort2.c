#include <stdio.h>
#include <stdlib.h>
#include <time.h>//4736196
void MergeSort(int*, int, int);
void MergeSortRec(int**, int, int, int);
int btime = 0;
int etime = 0;
int arr[10000000];
int main()
{
	freopen("input", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	MergeSort(arr, 0, n - 1);
	//for (int i =0;i < n;++i) printf("%d ", arr[i]);
	printf("%d\n", etime - btime);
	return 0;
}
void MergeSort(int* tmp, int beg, int end)
{
	int n = end - beg + 1;
	int ** arr = malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; ++i) arr[i] = malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) arr[0][i] = arr[1][i] = tmp[i];
	btime = clock();
	printf("%d \n", btime);
	MergeSortRec(arr, beg, end, 0);
	etime = clock();
	printf("%d \n", etime);
	for (int i = 0; i < n; ++i) tmp[i] = arr[0][i];//

	
	for (int i = 0; i < 2; ++i) free(arr[i]);
	free(arr);
}
void MergeSortRec(int** arr, int beg, int end, int id)
{
	if (beg >= end) return;
	int mid = (beg + end) / 2;
	int beg1 = beg, end1 = mid;
	int beg2 = mid + 1, end2 = end;
	MergeSortRec(arr, beg1, end1, !id);
	MergeSortRec(arr, beg2, end2, !id);
	int k = beg;
	int id2 = !id;
	
	if (end - beg <= 4)
	{
		for (int i = beg; i <= end; ++i)
			for (int j = i + 1; j <= end; ++j)
				if (arr[id][i] > arr[id][j])
				{
					int tmp = arr[id][i];
					arr[id][i] = arr[id][j];
					arr[id][j] = tmp;
				}
	}
	else
	{
		while (beg1 <= end1 && beg2 <= end2)
			arr[id][k++] = arr[id2][beg1] <= arr[id2][beg2] ? arr[id2][beg1++] : arr[id2][beg2++];
		while (beg1 <= end1) arr[id][k++] = arr[id2][beg1++];
		while (beg2 <= end2) arr[id][k++] = arr[id2][beg2++];
	}
}

