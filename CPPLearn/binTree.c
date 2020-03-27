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
			while (root != NULL)	//��ӡ����Ԫ��  �������ڵ���ջ  rootָ��ָ������  һֱִ���ҵ�����ĺ���
			{
				printf("%c  ", root->data);
				Push(&stree, root);
				root = root->lchild;
			}

			if (!IsEmpty(&stree))	//��ջ  ����������  1.whileѭ��������������ڵ��ֵ  2.������������������������
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
		while (root != NULL || !IsEmpty(&stree))	//��ֹ����Ϊ  ����root��=NULL ��IsEmpty()Ϊ��
		{
			while (root != NULL)
			{
				Push(&stree, root);
				root = root->lchild;
			}

			if (!IsEmpty(&stree))
			{
				Pop(&stree);
				root = GetTop(&stree);	//�������  �ڳ�ջʱ���Ԫ�ص�ֵ
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

	Push(&stree, p);	//�Ƚ����ڵ���ջ

	while (!IsEmpty(&stree))	
	{
		root = GetTop1(&stree);	//ȡջ��ָ�뵫����ջ
		//�ж����ҽڵ㶼ΪNULL  ��ʱΪҶ�ӽڵ�  ���  ��pre == ����ҽڵ�  
		//�����ҽڵ���������Ϊ��ջʱ���ڵ�֮�����ҽڵ���ڣ�����pre��ʱֻ�ܵ����ҽڵ�ʱ�ſ��Գ�ջ����ӡ
		//��ֻ����ڵ�û���ҽڵ�ʱ��
		if ((root->lchild == NULL && root->rchild == NULL) || (pre != NULL && (pre == root->lchild || pre == root->rchild)))
		{
			//ע���ջ����
			printf("%c ", root->data);
			Pop(&stree);
			pre = root;	//��¼�ϴδ���Ľڵ�  ��Ϊ����ָ��
		}

		else
		{
			if (root->rchild != NULL)	//����ջ�ĺ��ջ  ���ԡ����ȱ�����������  ��߲ű�������������
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

	printf("�������������'#'Ϊ��\n");
	Node *root = createBinaryTree();

	printf("\n�ݹ��������:\n");
	preorderRecursive(root);

	printf("\n�ݹ��������:\n");
	inorderRecursive(root);

	printf("\n�ݹ�������:\n");
	postorderRecursive(root);

	printf("\n�ǵݹ��������\n");
	preordernotRecursive(root);

	printf("\n�ǵݹ��������\n");
	inordernotRecursive(root);

	printf("\n�ǵݹ�������\n");
	postordernotRecursive(root);

	getchar();
	getchar();
}
