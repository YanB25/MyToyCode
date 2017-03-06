#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int Find(int key);
void Union(int lhs, int rhs);
void Print(int);
int* rank;
int* prev;
int main()
{
	freopen("input", "r", stdin);
	int n;
	scanf("%d ",&n);
	rank = malloc(sizeof(int) * n);
	prev = malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		rank[i] = 0;
		prev[i] = i;
	}
	
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (Find(x) != Find(y))
		{
			printf("Link... \n");
			Union(x, y);

		}
		else printf("has link.\n");
	}
	scanf("%d", &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (Find(x) == Find(y))printf("%d and %d Linked\n", x, y);
		else printf("%d and %d NOT Linked\n", x, y);
	}
	Print(n);
}

int Find(int key)
{
	if (prev[key] == key) return key;
	prev[key] = Find(prev[key]);
	return prev[key];
}

void Union(int lhs, int rhs)
{
	if (Find(lhs) == Find(rhs)) return;
	
	if (rank[lhs] < rank[rhs]) prev[lhs] = prev[rhs];
	else
	{
		prev[rhs] = prev[lhs];
		if (rank[lhs] == rank[rhs]) rank[lhs]++;
	}
}

void Print(int n)
{
	for (int i = 0; i < n; ++i) printf("(%d: %d %d) ", i, prev[i], rank[i]);
	printf("\n");
}
	
	
	
	
