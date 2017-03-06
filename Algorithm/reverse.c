#include <stdio.h>
#include <string.h>
int main()
{
	char arr[20];
	int i = 0;
	while(scanf("%c",&arr[i]) && arr[i] != '#') i++;
	char* rev;
	rev = strrev(arr);
	for(int j = 0; j < i; ++j)
		printf("%c ",rev[j]);
	return 0;
}
