#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define Stack_increment 20
#define Stack_Size 100  


typedef struct  Tree
{
	char data;
	struct Tree *lchild;
	struct Tree *rchild;
}Node;

Node* createBinaryTree()
{
	Node *root;
	char ch;
	scanf("%c", &ch);

	if (ch == '#')
	{
		root = NULL;
	}
	else
	{
		root = (Node *)malloc(sizeof(Node));
		root->data = ch;
		root->lchild = createBinaryTree();
		root->rchild = createBinaryTree();
	}

	return root;
}

typedef struct
{
	int top;
	Node* arr[Stack_Size];
}Stacktree;

void InitStack(Stacktree *S)
{
	S->top = 0;
}

void Push(Stacktree* S, Node* x)
{
	int top1 = S->top;
	if (x->data == '#')
	{
		return;
	}
	else
	{
		S->arr[top1++] = x;
		S->top++;
	}
}

int Pop(Stacktree *S)
{
	int top = S->top;
	if (S->top == 0)
	{
		return 0;
	}
	else
	{
		--(S->top);
		return 1;
	}
}

Node* GetTop(Stacktree *S)
{
	int top1 = S->top;
	Node*p;
	p = S->arr[top1--];
	return p;
}

Node* GetTop1(Stacktree *S)
{
	int top1 = S->top;
	Node*p;
	top1--;
	p = S->arr[top1];
	return p;
}

int IsEmpty(Stacktree *S)
{
	return(S->top == 0 ? 1 : 0);
}

void preorderRecursive(Node *p)
{
	if (p != NULL)
	{
		printf("%c ", p->data);
		preorderRecursive(p->lchild);
		preorderRecursive(p->rchild);
	}
}

void inorderRecursive(Node *p)
{
	if (p != NULL)
	{
		inorderRecursive(p->lchild);
		printf("%c ", p->data);
		inorderRecursive(p->rchild);
	}
}

void postorderRecursive(Node *p)
{
	if (p != NULL)
	{
		postorderRecursive(p->lchild);
		postorderRecursive(p->rchild);
		printf("%c ", p->data);
	}
}

void preordernotRecursive(Node *p)
{
	if (p)
	{
		Stacktree stree;
		InitStack(&stree);
		Node *root = p;
		while (root != NULL || !IsEmpty(&stree))
		{
			while (root != NULL)	//打印数据元素  并将本节点入栈  root指针指向左孩子  一直执行找到最左的孩子
			{
				printf("%c  ", root->data);
				Push(&stree, root);
				root = root->lchild;
			}

			if (!IsEmpty(&stree))	//出栈  遍历右子树  1.while循环将输出右子树节点的值  2.将继续遍历右子树的左子树
			{
				Pop(&stree);
				root = GetTop(&stree);
				root = root->rchild;
			}
		}
	}
}

void inordernotRecursive(Node *p)
{
	if (p)
	{
		Stacktree stree;
		InitStack(&stree);
		Node *root = p;
		while (root != NULL || !IsEmpty(&stree))	//终止条件为  满足root！=NULL 或IsEmpty()为空
		{
			while (root != NULL)
			{
				Push(&stree, root);
				root = root->lchild;
			}

			if (!IsEmpty(&stree))
			{
				Pop(&stree);
				root = GetTop(&stree);	//中序遍历  在出栈时输出元素的值
				printf("%c  ", root->data);
				root = root->rchild;
			}
		}
	}
}

void postordernotRecursive(Node *p)
{
	Stacktree stree;
	InitStack(&stree);

	Node *root;
	Node *pre = NULL;

	Push(&stree, p);	//先将根节点入栈

	while (!IsEmpty(&stree))	
	{
		root = GetTop1(&stree);	//取栈顶指针但不出栈
		//判断左右节点都为NULL  此时为叶子节点  输出  或pre == 左或右节点  
		//有左右节点的情况，因为入栈时根节点之间有右节点存在，所以pre此时只能等于右节点时才可以出栈被打印
		//而只有左节点没有右节点时，
		if ((root->lchild == NULL && root->rchild == NULL) || (pre != NULL && (pre == root->lchild || pre == root->rchild)))
		{
			//注意出栈条件
			printf("%c ", root->data);
			Pop(&stree);
			pre = root;	//记录上次处理的节点  作为辅助指针
		}

		else
		{
			if (root->rchild != NULL)	//先入栈的后出栈  所以。。先遍历了左子树  后边才便利的了右子树
			{
				Push(&stree, root->rchild);
			}

			if (root->lchild != NULL)
			{
				Push(&stree, root->lchild);
			}
		}

	}
}

void main()
{

	printf("请输入二叉树，'#'为空\n");
	Node *root = createBinaryTree();

	printf("\n递归先序遍历:\n");
	preorderRecursive(root);

	printf("\n递归中序遍历:\n");
	inorderRecursive(root);

	printf("\n递归后序遍历:\n");
	postorderRecursive(root);

	printf("\n非递归先序遍历\n");
	preordernotRecursive(root);

	printf("\n非递归中序遍历\n");
	inordernotRecursive(root);

	printf("\n非递归后序遍历\n");
	postordernotRecursive(root);

	getchar();
	getchar();
}
