#include <stdio.h>
#include <stdlib.h>

typedef struct Obj
{
	int data;
	int id;
}Obj;
void BubbleSort(Obj* arr, int beg, int end);
void Print(Obj* arr, int n);

int main()
{
	freopen("input", "r", stdin);
	int n;
	scanf("%d", &n);
	Obj* arr = (Obj*) malloc(sizeof(Obj) * n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &arr[i].data, &arr[i].id);
	
	BubbleSort(arr, 0, n);
	Print(arr, n);
	free(arr);
	return 0;
}
void BubbleSort(Obj* arr, int beg, int end)
{
	int n = beg - end;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (arr[j].data > arr[j + 1].data)
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				
			}
		}
}


