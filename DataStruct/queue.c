#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
	
int size = 0;
Node* head = NULL;

bool push(int data)
{
	Node* tmp = (Node*) malloc(sizeof(Node));
	tmp->data = data;
	if (size == 0)
	{
		tmp->next = NULL;
		head = tmp;
	}
	else
	{
		int pos = size - 1;
		Node* cur = head;
		while (pos--) cur = cur->next;
		tmp->next = cur->next;
		cur->next = tmp;
	}
	size++;
	return true;
}

bool pop()
{
	if (size == 0) return false;
	
	Node* tmp = head;
	head = head->next;
	free(tmp);
	size--;
	return true;
}

bool top(int* data)
{
	if (size == 0) return false;
	
	*data = head->data;
	return true;
}

bool is_empty() {return size == 0;}
void show()
{
	printf("size: %d node: ",size);
	Node* cur = head;
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
		else if (order == 'q') return 0;
		else if(order != '\n') printf("Syntax Error!\n");
		while (order != '\n') order = getchar();
		
	}
	return 0;
}
