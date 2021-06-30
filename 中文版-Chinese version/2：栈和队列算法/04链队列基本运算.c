//链队列基本运算 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	char data;
	struct node *next; 
}QNode; 

typedef struct{
	QNode *front,*rear;
}LQueue;

void Init_LQueue(LQueue **q)
{
	QNode *p;
	*q=(LQueue*)malloc(sizeof(LQueue));
	p=(QNode*)malloc(sizeof(QNode));
	p->next=NULL;
    (*q)->front=p;
	(*q)->rear=p; 
 } 
 
int Empty_LQueue(LQueue *q)
{
	if(q->front==q->rear)
	   return 1;
	else
	   return 0;
}

void In_LQueue(LQueue* q,char x)
{
	QNode *p;
	p=(QNode*)malloc(sizeof(QNode));
	p->data=x;
	p->next=NULL;
	q->rear->next=p;
	q->rear=p;
}

void Out_LQueue(LQueue *q,char *x)
{
	QNode *p;
	if(Empty_LQueue(q))
	   printf("Queue is empty!\n");
	else
	{
		p=q->rear;
		q->front->next=p->next;
		*x=p->data;
		free(p);
		if(q->front->next==NULL)
		  q->rear=q->front; 
	 } 
}

void print(LQueue *q)
{
	QNode *p;
	p=q->front->next;
	while(p!=NULL)
	{
		printf("%4c",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	LQueue *q;
	char x,*y=&x;
	Init_LQueue(&q);
    if(Empty_LQueue(q))
       printf("Queue is empty!\n");
    printf("Input any string:\n");
    scanf("%c",&x);
    while(x!='\n')
    {
    	In_LQueue(q,x);
    	scanf("%c",&x);
	}
    printf("Output elements of Queue:\n");
    print(q);
    printf("Output Queue:\n");
    Out_LQueue(q,y);
    printf("Element of Output Queue is %c\n",*y);
    printf("Output elements of Queue:\n");
    print(q);
    return 0;
}
