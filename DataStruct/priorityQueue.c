#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int priQueue[1000];
int PriQueueMax();
void IncreaseKey(int , int);
void Insert(int key);
void heapify(int pos);
int Extract();
void show();
int main()
{
	int n;
	scanf("%d", &n);
	memset(priQueue, 0, sizeof(priQueue));
	for (int i = 0; i < n; ++i) 
	{
		int tmp;
		scanf("%d", &tmp);
		Insert(tmp);
	
		//for (int i = 0; i <= priQueue[0]; ++i) printf("%d ", priQueue[i]);
		//printf("\n");
	}
}

int PriQueueMax() {return priQueue[1];}

void IncreaseKey(int pos, int key)
{
	
	priQueue[pos] = key;
	
	while(pos / 2 >= 1 && priQueue[pos / 2] < priQueue[pos])
	{
		int tmp = priQueue[pos / 2];
		priQueue[pos / 2] = priQueue[pos];
		priQueue[pos] = tmp;
		pos /= 2;
	}
}

void Insert(int key)
{
	priQueue[++priQueue[0]] = 0;
	IncreaseKey(priQueue[0], key);
}

int Extract()
{
	if (priQueue[0] <= 0) return 0;
	int tmp = priQueue[1];
	priQueue[1] = priQueue[priQueue[0]];
	priQueue[priQueue[0]] = tmp;
	priQueue[0]--;
	heapify(1);
	return priQueue[priQueue[0] + 1];
}

void heapify(int pos)
{
	int max = pos;
	if (pos * 2 <= priQueue[0] && priQueue[pos * 2] > priQueue[max])
		max = pos * 2;
	if (pos * 2 + 1 <= priQueue[0] && priQueue[pos * 2 + 1] > priQueue[max])
		max = pos * 2 + 1;
	
	if (pos == max) return;
	
	int tmp = priQueue[max];
	priQueue[max] = priQueue[pos];
	priQueue[pos] = tmp;
	
	heapify(max);
}

void show()
{
	for (int i = 0; i < priQueue[0]; ++i)
		printf("%d ", priQueue[i]);
	printf("\n");
}





