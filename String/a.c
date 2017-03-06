#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
	srand(time(0));
	freopen("input", "w", stdout);
	const int n = 1E3;
	const int length = 70;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		int l = rand() % length + 1;
		for (int j = 0; j < l; ++j) {
			printf("%c", 'a' + rand() % ('z' - 'a' + 1));
		}
		printf("\n");
	}
	return 0;
}
