#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int heap[1000];
void heapify(int);
void HeapSort();
void MakeHeap();
int main()
{	
	memset(heap, 0, sizeof(heap));
	freopen("input", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &heap[i + 1]);
	heap[0] = n;
	HeapSort(heap);
	
	for (int i = 0; i < n; ++i) printf("%d\n", heap[i + 1]);
	return 0;
}

void heapify(int pos)
{
	int max = pos;
	if (pos * 2 <= heap[0] && heap[max] < heap[pos * 2])
		max = pos * 2;
	if (pos * 2+ 1 <= heap[0] && heap[max] < heap[pos * 2 + 1])
		max = pos * 2 + 1;
	
	if (max == pos) return ;
	
	int tmp = heap[pos];
	heap[pos] = heap[max];
	heap[max] = tmp;
	
	heapify(max);
}

void MakeHeap()
{
	for (int i = heap[0]; i > 0; --i)
		heapify(i);
}

void HeapSort()
{
	MakeHeap();
	
	while (heap[0] > 0)
	{
		int tmp = heap[1];
		heap[1] = heap[heap[0]];
		heap[heap[0]] = tmp;
		heap[0]--;
		heapify(1);
	}
}	
	
	
	
	
