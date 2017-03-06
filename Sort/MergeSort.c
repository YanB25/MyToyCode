#include <stdio.h>
#include <stdlib.h>
#include <time.h>//4420918
int arr[0xfffffff];
int tmp[0xfffffff];
int cnt = 0;//
double sum = 0;//
void MergeSort(int* ,int*, int, int);
int max(int a,int b){return a>b?a:b;}
int main()
{
	freopen("input", "r", stdin);
	int n;
	for(n = 1; n <= 100000000; n *= 2)
	{
		for (int i = 0; i < n;++i) scanf("%d", &arr[i]);
		int btime = clock();
		MergeSort(arr, tmp, 0, n - 1);
		//for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
		printf("%d ", clock() - btime);
		printf("%lf\n", cnt * 1.0);
	}
}
void MergeSort(int* arr, int* tmp, int beg, int end)
{
	if (beg >= end) return;
	int mid = (beg + end) / 2;
	int beg1 = beg, end1 = mid;
	int beg2 = mid + 1, end2 = end;
	MergeSort(arr, tmp, beg1, end1);
	MergeSort(arr, tmp, beg2, end2);
	if (arr[end1] <= arr[beg2]) {cnt++;return;}
	int k = beg;
	while(beg1 <= end1 && beg2 <= end2)
	{
		tmp[k++] = arr[beg1] <= arr[beg2] ? arr[beg1++] : arr[beg2++];
	}
/*	============*/
/*	int N = end - beg + 1;*/
/*	int m = max(end2 - beg2 + 1,end1 - beg1 + 1);*/
/*	sum += m * 1.0 / N;*/
/*	cnt++;*/
/*	printf("%lf\n", sum / cnt);*/
	//printf("%d %d %d %lf\n",end1 - beg1 + 1, end2 - beg2 + 1, N,  m * 1.0 / N);
/*	============*/
	while (beg1 <= end1) tmp[k++] = arr[beg1++];
	while (beg2 <= end2) tmp[k++] = arr[beg2++];
	
	for (int i = beg; i <= end; ++i) arr[i] = tmp[i];
}
