//按层次遍历二叉树 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct node{
	char data;
	struct node *lchild,*rchild;
}BSTree;
typedef struct{
	BSTree *data[MAXSIZE];
	int rear,front;
}SeQueue;
void Init_SeQueue(SeQueue **q)
{
	*q=(SeQueue*)malloc(sizeof(SeQueue));
	(*q)->front=0;
	(*q)->rear=0;
}

int Empty_SeQueue(SeQueue *q)
{
	if(q->front==q->rear)
	  return 1;
	else
	  return 0;
}

void In_SeQueue(SeQueue *q,BSTree *x)
{
	if((q->rear+1)%MAXSIZE==q->front)
	  printf("Queue is full!\n");
	else
	{
		q->rear=(q->rear+1)%MAXSIZE;
		q->data[q->rear]=x;
	}
}

void Out_SeQueue(SeQueue *q,BSTree **x)
{
	if(q->front==q->rear)
	   printf("Queue is empty!\n");
	else
	{
		q->front=(q->front+1)%MAXSIZE;
		*x=q->data[q->front];
	}
}

void Inorder(BSTree *p)
{
	if(p!=NULL)
	{
		Inorder(p->lchild);
		printf("%3c",p->data);
		Inorder(p->rchild);
	}
 } 
 
void Createb(BSTree **p)
{
	char ch;
	scanf("%c",&ch);
	if(ch!='.')
	{
		*p=(BSTree*)malloc(sizeof(BSTree));
		(*p)->data=ch;
		Createb(&(*p)->lchild);
		Createb(&(*p)->rchild);
	}
	else
	  *p=NULL;
}

void Transleve(BSTree *t)
{
	SeQueue *Q;
	BSTree *p;
	Init_SeQueue(&Q);
	if(t!=NULL)
	  printf("%2c",t->data);
	In_SeQueue(Q,t);
	while(!Empty_SeQueue(Q))
	{
		Out_SeQueue(Q,&p);
		if(p->lchild!=NULL)
		{
			printf("%2c",p->lchild->data);
			In_SeQueue(Q,p->lchild);//*p左孩子指针入队 
		}
		if(p->rchild!=NULL)
		{
			printf("%2c",p->rchild->data);
			In_SeQueue(Q,p->rchild);//*p右孩子指针入队 
		}
	}
}

int main()
{
	BSTree *root;
	printf("Preorder enter bitree with '..':\n");
	Createb(&root);
	printf("Inorder output:\n");
	Inorder(root);
	printf("\n");
	Transleve(root);
	printf("\n");
	return 0;
}
