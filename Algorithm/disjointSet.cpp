#include <cstdio>
using namespace std;
struct Node
{
	int p;
	int r;
};
int find(int);
Node set[10];

void print(int i)
{
	printf("%d ",i);
	while( set[i].p != i)
	{
		printf("%d ",set[i].p);
		i = set[i].p;
	}
	printf("\n");
}

void Union(int x, int y)
{
	if (find(x) == find(y)) return;//important statement
	x = find(x);
	y = find(y);//important
	if (set[x].r < set[y].r)
		set[x].p = y;
	else
	{
		set[y].p = x;
		if (set[y].r == set[x].r)
			set[y].r++;
	}
}

int find(int x)
{
	if (set[x].p != x)
		set[x].p = find(set[x].p);
	return set[x].p; //sinvere bug 
}
int main()
{
	freopen("input","r",stdin);
	int n, m;
	scanf("%d%d",&n, &m);
	
	for(int i = 0; i < n; ++i)
	{
		set[i].p = i;
		set[i].r = 0;
	}
	
	while(m--)
	{
		int x, y;
		scanf("%d%d",&x, &y);
		Union(x, y);
	}
	
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			printf("%d and %d is %s adjoint\n",i, j, find(i)==find(j)?"":"NOT");
		
	printf("\n");
	for(int i = 0; i < n; ++i)
		print(i);

	return 0;
}
