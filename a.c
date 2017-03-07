#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
	srand(time(0));
	freopen("input", "w", stdout);
	int n = 100000;
	int m = n * 40;
	printf("%d\n", n);
	printf("%d\n", m);
	for (int i = 0; i < m; ++i) printf("%d %d\n", rand() % n, rand() % n);
	printf("%d\n", m);
	for (int i = 0; i < m * 10; ++i) printf("%d %d\n", rand() % n, rand() % n);
	printf("\n");
	return 0;
} 
