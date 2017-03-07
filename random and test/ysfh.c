#include<stdio.h>
void delete(int (*arr)[2],int index)
{
	arr[arr[index][1]][0] = arr[index][0];
	arr[arr[index][0]][1] = arr[index][1];
}
int main()
{
	freopen("random","r",stdin);
	freopen("ysfh","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m) == 2){
	int arr[1000+5][2];
	for(int i = 2; i < n; ++i)
	{
		arr[i][0] = i + 1;
		arr[i][1] = i - 1;
	}
	arr[n][0] = 1;
	arr[n][1] = n - 1;
	arr[1][0] = 2;
	arr[1][1] = n;
	arr[0][0] = 1;
	
	int index = 0;
	while(1)
	{
		int cnt = m;
		while(cnt--) index = arr[index][0];
		delete(arr,index);
		if(arr[index][0] == index && arr[index][1] == index)
		{
			printf("%d\n",index);
			break;
		}
	}
	}
	return 0;
}	
	
