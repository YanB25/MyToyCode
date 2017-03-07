#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stu
{
	char gender[2];
	char name[7];
	int id;
	int score;
}Stu;

void print(Stu* stus, int n);
int GenderCmp(const void*, const void*);
int NameCmp(const void*, const void*);
int IdCmp(const void*, const void*);
int ScoreCmp(const void*, const void*);
int main()
{
	freopen("input","r",stdin);
	int n;
	scanf("%d",&n);
	Stu *stus = (Stu*)malloc(n * sizeof(Stu));
	Stu *sort_stus = (Stu*)malloc(n * sizeof(Stu));
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%s%d%d", stus[i].gender, stus[i].name, &stus[i].id, &stus[i].score);
		sort_stus[i] = stus[i];
	}
	int op;
	while(scanf("%d",&op) == 1)
	{
		if (op == -1) return 0;
		if (op == 0) { print(stus,n); continue; }
		if (op == 1) qsort(sort_stus, n, sizeof(*stus), GenderCmp);
		if (op == 2) qsort(sort_stus, n, sizeof(*stus), NameCmp);
		if (op == 3) qsort(sort_stus, n, sizeof(*stus), IdCmp);
		if (op == 4) qsort(sort_stus, n, sizeof(*stus), ScoreCmp);
		print(sort_stus, n);
	}
}



void print(Stu* stus, int n)
{
	for(int i = 0; i < n; ++i)
		printf("%-6s %-6s %-8d %-5d\n", stus[i].gender, stus[i].name, stus[i].id, stus[i].score);
	printf("\n");
	printf("\n");
}

int GenderCmp(const void* lhs, const void* rhs)
{
	if (strcmp( ((Stu*)lhs)->gender, ((Stu*)rhs)->gender ) == 0) 
		return ((Stu*)lhs)->id - ((Stu*)rhs)->id;
	else
		return strcmp( ((Stu*)lhs)->gender, ((Stu*)rhs)->gender );
}

int NameCmp(const void* lhs, const void* rhs)
{
	return strcmp( ((Stu*)lhs)->name, ((Stu*)rhs)->name );
}

int IdCmp(const void* lhs, const void* rhs)
{
	return ((Stu*)lhs)->id - ((Stu*)rhs)-> id;
}

int ScoreCmp(const void* lhs, const void* rhs)
{
	if ( ((Stu*)lhs)->score != ((Stu*)rhs)-> score)
		return ((Stu*)rhs)->score - ((Stu*)lhs) -> score;
	else
		return ((Stu*)lhs)->id - ((Stu*)rhs)->id;
}










