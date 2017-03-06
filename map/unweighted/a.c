#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
	freopen("input", "w", stdout);
	const int max = 1E4;
	srand(time(0));
	int n = rand() % (max / 40) + 1;
	int m = rand() % max;
	printf("%d %d\n", n, m);
	while (m--){
		printf("%d %d\n", rand() % n, rand() % n);
	}
	printf("%d\n", rand() % n);
	return 0;
}
