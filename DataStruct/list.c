#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
	int data;
	struct Node* next;
} Node;

int size = 0;
Node* head = NULL;

bool InsertNode(int pos, int data);
bool DeleteNode(int pos);
bool clear();
bool show();
int search(int);

bool InsertNode(int pos, int data)
{
	if (pos > size || pos < 0) return false;
	
	Node* tmp = (Node*) malloc(sizeof(Node));
	tmp->data = data; 
	if (pos == 0)
	{
		tmp->next = head;
		head = tmp;
	}
	else
	{
		pos--;
		Node* cur = head;
		while (pos--) cur = cur->next;
		tmp->next = cur->next;
		cur->next = tmp;
	}
	size++;
	return true;
}

bool DeleteNode(int pos)
{
	if (pos >= size || pos < 0) return false;
	
	if (pos == 0)
	{
		Node* tmp = head;
		head = head -> next;
		free(tmp);
	}
	else
	{
		pos--;
		Node* cur = head;
		while (pos--) cur = cur->next;
		Node* tmp = cur->next;
		cur->next = tmp->next;
		free(tmp);
	}
	size--;
	return true;
} 

bool clear() {while (size != 0) DeleteNode(0);return true;}

bool show()
{
	Node* cur = head;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	return true;
}

int search(int key)
{
	Node* cur = head;
	int pos = 0;
	while (cur != NULL && cur->data != key)
	{
		cur = cur->next;
		pos++;
	}
	if (cur == NULL) return -1;
	else return pos;
}
	
	
	
int main()
{
	printf("Enter order, f (data) to found, a (pos) (data) to add, d (pos) to delete, c to clear, f (data) to search, s to show\n");
	while(true)
	{
		printf(">>> ");
		char order;
		order = getchar();
		if (order == 'a')
		{
			int pos, data;
			scanf("%d%d",&pos, &data);
			if(!InsertNode(pos, data)) printf("Error to Insert!\n");
		}
		else if (order == 'd')
		{
			int pos;
			scanf("%d",&pos);
			if (!DeleteNode(pos)) printf("Error to Delete!\n");
		}
		else if (order == 'c')
		{
			if(!clear()) printf("Error to clear!\n");
		}
		else if (order == 's') show();
		else if (order == 'f')
		{
			int data;
			scanf("%d",&data);
			int pos = search(data);
			if (pos != -1) printf("Find data %d at pos %d\n", data, pos);
			else printf("Can NOT find data %d\n", data);
		}
		else if (order == 'q') return 0;
		else if(order != '\n') printf("Syntax Error!\n");
		while (order != '\n') order = getchar();
		
	}
	return 0;
}
