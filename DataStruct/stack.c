#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
int size = 0;
Node* head = NULL;

int Size() {return size;}
bool is_empty() {return size == 0;}

bool push(int data)
{
	Node* tmp = (Node*) malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = head;
	head = tmp;
	size++;
	return true;
}

bool pop()
{
	if (is_empty()) return false;
	
	Node* tmp = head;
	head = head->next;
	free(tmp);
	size--;
	return true;
}

bool top(int* data)
{
	if (is_empty()) return false;
	*data = head->data;
	return true;
}

bool clear()
{
	while (!is_empty()) pop();
	return true;
}

void show()
{
	Node* cur = head;
	printf("size: %d node: ", size);
	while(cur != NULL)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	printf("Enter order, a (data) to push, d to pos, s to show\n");
	while(true)
	{
		printf(">>> ");
		char order;
		order = getchar();
		if (order == 'a')
		{
			int data;
			scanf("%d",&data);
			push(data);
		}
		else if (order == 'd')
		{
			if (!pop()) printf("Error to pop!\n");
		}
		else if (order == 's')
		{
			show();
		}
		else if(order != '\n') printf("Syntax Error!\n");
		else if (order == 'q') return 0;
		while (order != '\n') order = getchar();
		
	}
	return 0;
}
