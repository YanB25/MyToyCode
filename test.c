#include <stdio.h>
int main()
{
	char arr[5];
	for(int i = 0; i < 7; ++i)
		arr[i] = 1;
	for(int i = 0; i < 70000; ++i)
		printf("%d ",arr[i]);
		
	printf("\n");
	return 0;
}
