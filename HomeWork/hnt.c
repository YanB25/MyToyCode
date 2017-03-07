#include <stdio.h>
void print(int a,int b, int c) { printf("move disk %d from peg %d to peg %d\n",a,b,c); }

void move(int num, int beg, int tmp, int end)
{
	if (num == 1) print(num, beg, end);
	else
	{
		move(num - 1, beg, end, tmp);
		print(num, beg, end);
		move(num - 1, tmp, beg, end);
	}
}
	
int main()
{
	int t,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&m);
		move(m, 1, 2, 3);
	}
}
