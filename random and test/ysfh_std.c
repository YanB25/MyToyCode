#include<stdbool.h>
#include<string.h>
#include<stdio.h>
int main()
{	
	freopen("random","r",stdin);
	freopen("ysfh_std_out","w",stdout);
	int num,tag;
	int cnt = 0;
	while(scanf("%d%d",&num,&tag) == 2){
	bool isDead[1005];
	memset(isDead,0,sizeof(isDead));
	int index = 0;
	int mem= 0;
	for(int i = 0; i < num; ++i)
	{
		while(true)
		{
			do
			{
				index++;
				if(index > num)
					index %= num;
			}while(isDead[index] == true);
			cnt++;
			//printf("%d %d \n",cnt,index);
			if(cnt == tag)
			{
				cnt = 0;
				isDead[index] = true;
				//printf("%d",index);
				mem = index;
				break;
			}
		}
		
	}
	printf("%d\n",mem);
	}
}
