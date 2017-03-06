#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	freopen("input", "w", stdout);
	srand(time(0));
	const int min = 0;
	const int max = 40;
	const int n = 1E6;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", rand() % (max + 1));
	}
	printf("\n");
	return 0;
} 
