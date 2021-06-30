//循环队列基本操作 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct{
	char data[MAXSIZE];
	int rear,front;
}SeQueue;

void Int_SeQueue(SeQueue **q)
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

void In_SeQueue(SeQueue *q,char x)
{
	if((q->rear+1)%MAXSIZE==q->front)
	   printf("Queue is full!\n");
	else
	{
		q->rear=(q->rear+1)%MAXSIZE;
		q->data[q->rear]=x;
	}
}

void Out_SeQueue(SeQueue *q,char *x)
{
	if(q->front==q->rear)
	   printf("Queue is empty!\n");
	else
	{
		q->front=(q->front+1)%MAXSIZE;
		*x=q->data[q->front];
	}
}

void print(SeQueue *q)
{
	int i;
	i=(q->front+1)%MAXSIZE;
	while(i!=q->rear)
	{
		printf("%4c",q->data[i]);
		i=(i+1)%MAXSIZE;
	}
	printf("%4c\n",q->data[i]);
}

int main()
{
	SeQueue *q;
	char x,*y=&x;
	Int_SeQueue(&q);
	if(Empty_SeQueue(q))
	   printf("Queue is empty!\n");
	printf("Input any string:\n");
	scanf("%c",&x);
	while(x!='\n')
	{
		In_SeQueue(q,x);
		scanf("%c",&x);
	}
	printf("Output elements of Queue:\n");
	print(q);
	printf("Output Queue:\n");
	Out_SeQueue(q,y);
	printf("Element of Output Queue is %c\n",*y);
	printf("Output elements of Queue:\n");
	print(q);
	return 0;
}
