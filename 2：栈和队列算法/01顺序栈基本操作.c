#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
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
{
	if(s->top==-1)
	   printf("Stack is empty!\n");
	else{
		*x=s->data[s->top];
		s->top--;
	}
}

void Top_SeqStack(SeqStack *s,char *x)
{
	if(s->top==-1)
	   printf("Stack is empty!\n");
	else
	   *x=s->data[s->top];
}

void print(SeqStack *s)
{
	int i;
	for(i=s->top;i>=0;i--)
	   printf("%4c",s->data[i]);
	printf("\n");
}

int main()
{
	SeqStack *s;
	char x,*y=&x;
	Init_SeqStack(&s);
	if(Empty_SeqStack(s))
	   printf("Stack is empty!\n");
	printf("Input data of stack:\n");
	scanf("%c",&x);
	while(x!='\n')
	{
		Push_SeqStack(s,x);
		scanf("%c",&x);
	}
	printf("Output all data of stack:\n");
	print(s);
	Pop_SeqStack(s,y);
	printf("Output data of Pop stack:%c\n",*y);
	printf("Output all data of stack:\n");
	print(s);
	Top_SeqStack(s,y);
	printf("Output data of top stack:%c\n",*y);
	printf("Output all data of stack:\n");
	print(s);
	return 0;
}
