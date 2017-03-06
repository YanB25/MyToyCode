#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
};

typedef struct Node Node;
Node* head = NULL;
Node* ptr = NULL;
Node* Insert(Node**, int );
Node* Search(int );
void Trans(Node*, Node*);
void Delete(Node*);
Node* Min(Node* );
void InOrder(Node* );
void clear();

int main()
{
	//freopen("input", "r", stdin);
	printf("Enter order, a (key) to add, d to delete, c to clear, f (data) to search, s to show\n");
	while(true)
	{
		printf(">>> ");
		char order;
		order = getchar();
		if (order == 'a')
		{
			int key;
			scanf("%d",&key);
			Insert(&head, key);
			//if (!tag) printf("Dump and NOT Successfully add\n");
		}
		else if (order == 'd')
		{
			if (ptr == NULL) printf("No Delete Information!\n");
			else Delete(ptr);
			ptr = NULL;
		}
		else if (order == 'c')
		{
			clear();
		}
		else if (order == 's') 
		{ 
			InOrder(head); 
			printf("\n");
			if (ptr == NULL) printf("Current Ptr: NULL\n");
			else printf("Current Ptr at %d\n", ptr->key);
		}
		else if (order == 'f')
		{
			int key;
			scanf("%d",&key);
			ptr = Search(key);
			if (ptr == NULL) printf("Fail to Search\n");
			else printf("Successful Search\n");
		}
		else if (order == 'q') return 0;
		else if(order != '\n') printf("Syntax Error!\n");
		while (order != '\n') order = getchar();
		
	}
	return 0;
}

Node* Insert(Node** cur, int key)
{
	if (*cur == NULL)
	{
		*cur = (Node*)malloc(sizeof(Node));
		(*cur)->left = (*cur)->right = NULL;
		(*cur)->key = key;
	}
	else
	{
		if (key < (*cur)->key) Insert(&((*cur)->left), key)->parent = *cur;
		else Insert(&((*cur)->right), key)->parent = *cur; 
	}
}

Node* Search(int key)
{	
	Node* cur = head;
	if (cur == NULL) return NULL;
	while (cur != NULL && cur->key != key)
	{
		if (key > cur->key) cur = cur->right;
		else cur = cur->left;
	}
	return cur;
}
	
void Trans(Node* dest, Node* cont)
{
	if (dest == NULL) return;
	if (dest->parent == NULL) head = cont;
	else if (dest == dest->parent->left)
		dest->parent->left = cont;
	else dest->parent->right = cont;
	if (cont != NULL) cont->parent = dest->parent;
}
	
void InOrder(Node* cur)
{
	if (cur == NULL) return;
	
	InOrder(cur->left);
	printf("%d ", cur->key);
	InOrder(cur->right);
}

Node* Min(Node* cur)
{
	if (cur == NULL) return NULL;
	while (cur->left != NULL)
	{
		cur = cur->left;
	}
	return cur;
}

void Delete(Node* tar)
{
	if (tar->left == NULL) Trans(tar, tar->right);
	else if (tar->right == NULL) Trans(tar, tar->left);
	else
	{
		Node* s = Min(tar->right);
		if (s->parent != tar)
		{
			Trans(s, s->right);
			s->right = tar->right;
			s->right->parent = s;
		}
		Trans(tar, s);
		s->left = tar->left;
		s->left->parent = s;
	}
	free(tar);
}
	
void clear()
{
	while (head != NULL)
	Delete(head);
}
