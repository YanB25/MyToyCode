#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char* argv[])
{
	srand(time(0));
	freopen("random","w",stdout);
	int cnt = 0;
	sscanf(argv[1],"%d", &cnt);
	for(int i = 0; i < cnt; ++i)
		printf("%d %d\n",(int)rand() % 1000 + 1,(int)rand()%10 + 1);
}
