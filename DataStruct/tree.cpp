#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
	struct Node* left;
	struct Node* right;
	int N;
	int key;
	int val;
};

typedef struct Node Node;

Node* root = NULL;
void Insert(int key, int val);//
Node* _Insert(Node*, int key, int val);//
Node* Delete(int key);//
Node* _Delete(Node*, int);//
Node* DeleteMin(Node*);//
int size(Node* node);
void InOrder(Node* node);
int rank(Node*, int key);
Node* Select(Node*, int rank);
Node* Min(Node*);
Node* Max(Node*);
Node* Floor(Node* x, int key);
Node* Ceiling(Node* x, int key);	
int main()
{
	char order[10];
	printf("i (data) to insert, r (key) to get rank, sl (pos) to select, \nd (key) to delete, s to show, q to quit\n");
	while (true)
	{
		printf(">>> ");
		
		char tmp;
		tmp = getchar();
		if (tmp == '\n') continue;
		else ungetc(tmp, stdin);
		
		scanf("%s",order);
		if (order[0] == 'i')
		{
			int key, val;
			scanf("%d%d",&key, &val);
			Insert(key, val);
			InOrder(root);
			printf("\n");
		}
		else if (order[0] == 'd')
		{
			int key;
			scanf("%d",&key);
			Delete(key);
			InOrder(root);
			printf("\n");
		}
		else if (order[0] == 'r')
		{
			int key;
			scanf("%d",&key);
			printf("%d\n", rank(root, key));
		}
		else if (order[0] == 'f')
		{
/*			int data;*/
/*			scanf("%d",&data);*/
/*			if (TreeSearch(root, data)) printf("Find data %d\n", data);*/
/*			else printf("Do NOT find data %d\n",data);*/
		}
		else if (order[0] == 's' && order[1] == 'e')
		{
			int pos;
			scanf("%d", &pos);
			Node* tmp = Select(root, pos);
			if (tmp != NULL)
				printf("%d\n", tmp->key);
			else
				printf("Out of Arrange\n");
		}
		else if (order[0] == 's')
		{
/*			char type[10];*/
/*			scanf("%s",type);*/
/*			if (type[1] == 'r') PreOrder(root);*/
/*			else if (type[1] == 'n') (root);*/
/*			else if (type[1] == 'o') PostOrder(root);*/
			InOrder(root);
			printf("\n");
		}
		else if (order[0] == 'q') return 0;
		else printf("Syntax Error\n");
		getchar();
	}
	return 0;
}

void Insert(int key, int val) { root = _Insert(root, key, val);}
Node* _Insert(Node* pnode,int key, int val)
{
	if (pnode == NULL)
	{
		Node* new = malloc(sizeof(Node));
		new->left = new->right = NULL;
		new->val = val;
		new->key = key;
		new->N = 1;
		return new;
	}
	else if (key > pnode->key)
	{
		pnode->right = _Insert(pnode->right, key, val);
	}
	else if (key < pnode->key)
	{
		pnode->left = _Insert(pnode->left, key, val);
	}
	else pnode->val = val;
	pnode->N = size(pnode->left) + size(pnode->right) + 1;
	return pnode;
}

Node* Delete(int key)
{
	root = _Delete(root, key);
	return root;
}
	
Node* _Delete(Node* node, int key)
{
	if (node == NULL) return NULL;
	if (key > node->key) node->right = _Delete(node->right, key);
	else if (key < node->key) node->left = _Delete(node->left, key);
	else
	{
		if (node->right == NULL) return node->left;
		else if (node->left == NULL) return node->right;
		else
		{
			Node* ptmp = malloc(sizeof(Node));
			Node* toDelete = Min(node->right);
			*ptmp = *toDelete;
			ptmp->left = node->left;
			ptmp->right = DeleteMin(node->right);
			node = ptmp;
		}
	}
	node->N = size(node->left) + size(node->right) + 1;
	return node;
}

Node* DeleteMin(Node* node)
{
	if (node == NULL) return NULL;
	if (node->left == NULL)
	{
		Node* tmp = node->right;
		free(node);
		return tmp;
	}
	node->left = DeleteMin(node->left);	
	node->N = size(node->left) + size(node->right) + 1;	
	return node;
}

int size(Node* node)
{
	if (node == NULL) return 0;
	return node->N;
}

Node* Min(Node* x)
{
	if (x == NULL) return NULL;
	if (x->left == NULL) return x;
	return Min(x->left);
}	

Node* Max(Node* x)
{
	if (x == NULL) return NULL;
	if (x->right == NULL) return x;
	return Max(x->right);
}
		
int rank(Node* x, int key)
{
	if (x == NULL) return 0;
	if (x->key > key) return rank(x->left, key);
	else if (x->key < key) return size(x->left) + 1 + rank(x->right, key);
	else return size(x->left);
}
		
Node* Select(Node* x, int rank)
{
	if (x == NULL) return NULL;
	int t = size(x->left);
	if (t == rank) return x;
	else if (t > rank) return Select(x->left, rank);
	else return Select(x->right, rank - 1 - t);
}
		
void InOrder(Node* node){
	if (node == NULL) return;
	InOrder(node->left);
	printf("(%d %d) ", node->key, node->val);
	InOrder(node->right);
}
		
Node* Floor(Node* x, int key)
{
	if (x == NULL) return NULL;
	if (x->key == key) return x;
	else if (x->key > key) return Floor(x->left, key);
	else
	{
		Node* tmp = Floor(x->right, key);
		if (tmp != NULL) return tmp;
		else
		return x;
	}
}

Node* Ceiling(Node* x, int key)
{
	if (x == NULL) return NULL;
	if (x->key == key) return x;
	else if (x->key < key) return Ceiling(x->right, key);
	Node* tmp = Ceiling(x->left, key);
	if (tmp == NULL) return x;
	else return tmp;
}
		
		
		
