#include <stdio.h>
#include <stdlib.h>
typedef struct Obj
{
	int data;
	int id;
}Obj;

void SelectSort(Obj* arr, int beg, int end);
void Print(Obj* arr, int n);

int main()
{
	freopen("input", "r", stdin);
	int n;
	scanf("%d", &n);
	Obj* arr = (Obj*) malloc(sizeof(Obj) * n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &arr[i].data, &arr[i].id);
	
	SelectSort(arr, 0, n);
	Print(arr, n);
	free(arr);
	return 0;
}

void SelectSort(Obj* arr, int beg, int end)
{
	int n = end - beg;
}

void Print(Obj* arr, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d %d\n", arr[i].data, arr[i].id);
	printf("\n");
} 

