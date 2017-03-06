//2017.1.1
//ListNode's member change to key and value 
//add operation-delete and remain the property of this heap

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}ListNode;

bool push(ListNode** head, int data)
{
	ListNode* tmp = (ListNode*) malloc(sizeof(ListNode));
	tmp->data = data;
	tmp->next = *head;
	*head = tmp;
	//size++;
	return true;
}

bool pop(ListNode** head)
{
	if (head == NULL) return false;
	
	ListNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);
	//size--;
	return true;
}

bool top(ListNode* head, int* data)
{
	if (head == NULL) return false;
	*data = head->data;
	return true;
}

void clear(ListNode* node)
{
	if (node == NULL) return;
	clear(node->next);
	free(node);
}

void show(ListNode* head)
{
	printf("(");
	ListNode* cur = head;
	while(cur != NULL)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf(")");
}

bool ListSearch(ListNode* head, int data)
{
	if (head == NULL) return false;
	
	while (head != NULL)
	{
		if (head->data == data) return true;
		head = head->next;
	}
	return false;
}
//==============================================================
/* below is about tree*/
typedef struct TreeNode
{
	ListNode* head;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;
typedef TreeNode* TreeNodePtr;
TreeNode* root = NULL;

bool TreeInsertNode(TreeNodePtr* nodePtr, int data)
{
	if (*nodePtr == NULL)
	{
		*nodePtr = (TreeNode*) malloc(sizeof(TreeNode));
		(*nodePtr)->head = NULL;
		(*nodePtr)->left = (*nodePtr)->right = NULL;
		
		push(&(*nodePtr)->head, data);
	}
	else
	{
		if (data > (*nodePtr)->head->data)
			TreeInsertNode(&((*nodePtr)->left), data);
		else if (data < (*nodePtr)->head->data)
			TreeInsertNode(& ((*nodePtr)->right), data);
		else push(&(*nodePtr)->head, data);
	}
	
	return true;
}

void InOrder(TreeNodePtr node)
{
	if (node == NULL) return;
	
	InOrder(node->left);
	show(node->head);
	InOrder(node->right);
}

void PreOrder(TreeNodePtr node)
{
	if (node == NULL) return;
	
	show(node->head);
	PreOrder(node->left);
	PreOrder(node->right);
}

void PostOrder(TreeNodePtr node)
{
	if (node == NULL) return;
	
	PostOrder(node->left);
	PostOrder(node->right);
	show(node->head);
}

bool TreeSearch(TreeNodePtr root, int data)
{
	if(root == NULL) return false;
	if (ListSearch(root->head, data)) return true;
	return TreeSearch(root->left, data) || TreeSearch(root->right, data);
}

int main()
{
	char order[10];
	printf("i (data) to insert, f (data) to search, s [pr,in,po] to show, q to quit\n");
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
			int data;
			scanf("%d",&data);
			if( !TreeInsertNode(&root, data)) printf("Insert Fail\n");
		}
		else if (order[0] == 'f')
		{
			int data;
			scanf("%d",&data);
			if (TreeSearch(root, data)) printf("Find data %d\n", data);
			else printf("Do NOT find data %d\n",data);
		}
		else if (order[0] == 's')
		{
			char type[10];
			scanf("%s",type);
			if (type[1] == 'r') PreOrder(root);
			else if (type[1] == 'n') InOrder(root);
			else if (type[1] == 'o') PostOrder(root);
			printf("\n");
		}
		else if (order[0] == 'q') return 0;
		else printf("Syntax Error\n");
		
		getchar();
	}
	return 0;
}

