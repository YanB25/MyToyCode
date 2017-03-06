#include <stdio.h>
#include <stdlib.h>
typedef struct Obj
{
	int data;
	int id;
}Obj;

void InsertSort(Obj* arr, int beg, int end);
void Print(Obj* arr, int n);

int main()
{
	freopen("input", "r", stdin);
	int n;
	scanf("%d", &n);
	Obj* arr = (Obj*) malloc(sizeof(Obj) * n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &arr[i].data, &arr[i].id);
	
	InsertSort(arr, 0, n);
	Print(arr, n);
	free(arr);
	return 0;
}

void InsertSort(Obj* arr, int beg, int end)
{
	int n = end - beg;
	for (int i = 0; i < n; ++i)
	{
		int index = i;
		Obj tmp = arr[i];
		while (index >= 1 && arr[index - 1].data > tmp.data)
		{
			arr[index] = arr[index - 1];
			index--;
		}
		arr[index] = tmp;
	}
}


void Print(Obj* arr, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d %d\n", arr[i].data, arr[i].id);
	printf("\n");
} 
