#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int key;
	int color;
	struct Node* l;
	struct Node* r;
	struct Node* p;
};
typedef struct Node Node;
Node* root = NULL;

void LeftRotate(Node* x);
void RightRotate(Node* y);
void Insert(int key);
void FixUp(Node* x);
void Delete();
void InOrder(Node* cur);
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
			Insert(key);
			//if (!tag) printf("Dump and NOT Successfully add\n");
		}
		else if (order == 'd')
		{
			//if (ptr == NULL) printf("No Delete Information!\n");
			//else Delete(ptr);
			//ptr = NULL;
		}
/*		else if (order == 'c')*/
/*		{*/
/*			clear();*/
/*		}*/
		else if (order == 's') 
		{ 
			InOrder(root); 
			printf("\n");
			//if (ptr == NULL) printf("Current Ptr: NULL\n");
			//else printf("Current Ptr at %d\n", ptr->key);
		}
/*		else if (order == 'f')*/
/*		{*/
/*			int key;*/
/*			scanf("%d",&key);*/
/*			ptr = Search(key);*/
/*			if (ptr == NULL) printf("Fail to Search\n");*/
/*			else printf("Successful Search\n");*/
/*		}*/
		else if (order == 'q') return 0;
		else if(order != '\n') printf("Syntax Error!\n");
		while (order != '\n') order = getchar();
		
	}
	return 0;
}

void LeftRotate(Node* x)
{
	Node* y = x->r;
	x->r = y->l;
	if (y->l != NULL) y->l->p = x;
	
	y->p = x->p;
	if (x->p == NULL) root = y;
	else if (x->p->l == x) x->p->l = y;
	else x->p->r = y;
	
	y->l = x;
	x->p = y;
}

void RightRotate(Node* y)
{
	Node* x = y->l;
	y->l = x->r;
	if (x->r != NULL) x->r->p = y;
	
	x->p = y->p;
	if (y->p == NULL) root = x;
	else if (y->p->l == y) y->p->l = x;
	else y->p->r = x;
	
	x->r = y;
	y->p = x;
}

void Insert(int key)
{
	Node* y = NULL;
	Node* x = root;
	while (x != NULL)
	{
		y = x;
		if (key < x->key) x = x->l;
		else x = x->r;
	}
	
	x = (Node*)malloc(sizeof(Node));
	x->p = y;
	x->l = x->r = NULL;
	x->color = 0;
	if (y == NULL) root = x;
	else if (key < y->key) y->l = x;
	else y->r = x;
	FixUp(x);// remain RBT properties
}
	
void FixUp(Node* x)
{
	while (x->p != NULL && x->p->color == 0)
	{
		if (x->p == x->p->p->l)
		{
			Node* uncle = x->p->p->r;//uncle
			if (uncle != NULL && uncle->color == 0)
			{
				x->color = 1;
				uncle->color = 1;
				x->p->p->color = 0;
				x = x->p->p;
			}
			else if (x == x->p->r)
			{
				x = x->p;
				LeftRotate(x);
			}
			x->p->color = 1;
			x->p->p->color = 0;
			RightRotate(x->p->p);
		}
		else
		{
			Node* uncle = x->p->p->l;
			if (uncle != NULL && uncle->color == 0)
			{
				x->color = 1;
				uncle->color = 1;
				x->p->p->color = 0;
				x = x->p->p;
			}
			else if (x == x->p->l)
			{
				x = x->p;
				RightRotate(x);
			}
			x->p->color = 1;
			x->p->p->color = 0;
			LeftRotate(x->p->p);
		}
	}
	if (root != NULL) root->color = 1;
}
	 
void InOrder(Node* cur)
{
	if (cur == NULL) return;
	
	InOrder(cur->l);
	printf("(%c %d) ", cur->color == 0?'r' : 'b', cur->key);
	InOrder(cur->r);
}
	
