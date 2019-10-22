//已知q是一非空队列，编写一个算法，仅用队列和栈及少量工作变量完成将队列q中的所有元素逆置 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct{
	char data[MAXSIZE];
	int top;
}SeqStack;

void Init_SeqStack(SeqStack **s) 
{
	*s=(SeqStack*)malloc(sizeof(SeqStack));
	(*s)->top=-1;
 } 
 
int Empty_SeqStack(SeqStack *s)
{
	if(s->top==-1)
	   return 1;
	else
	   return 0;
}

void Push_SeqStack(SeqStack *s,char x)
{
	if(s->top==MAXSIZE-1)
	   printf("Stack is full!\n");
	else
	{
		s->top++;
		s->data[s->top]=x;
	}
}

void Pop_SeqStack(SeqStack *s,char *x)
{//将栈*s中的栈顶元素出栈并通过参数x返回x返回给主调函数 
	if(s->top==-1)
	  printf("Stack is empty!\n");
	else
	{
		*x=s->data[s->top];
		s->top--;
	}
}
 
typedef struct{
	char data[MAXSIZE];
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

void Revers_Queue(SeQueue *q,SeqStack *s)
{
	char x,*p=&x;
	Init_SeqStack(&s);
	while(!Empty_SeQueue(q))
	{
		Out_SeQueue(q,p);
		Push_SeqStack(s,*p);
	}
	while(!Empty_SeqStack(s))
	{
		Pop_SeqStack(s,p);
		In_SeQueue(q,*p);
	}
}

int main()
{
	SeqStack *s;
	SeQueue *q;
	char x,*y=&x;
	Init_SeqStack(&s);
	Init_SeQueue(&q);
	if(Empty_SeQueue(q))
	   printf("Queue is empty!\n");
	printf("Input any string:\n");
	scnaf("%c",&x);
	while(x!='\n')
	{
		In_SeQueue(q,x);
		scanf("%c",&x);
	}
	printf("Output elements of Queue:\n");
	print(q);
	printf("Convert Queue:\n");
	Reverse_Queue(q,s);
	printf("Output elements of Queue:\n");
	print(q);
	return 0;
}
