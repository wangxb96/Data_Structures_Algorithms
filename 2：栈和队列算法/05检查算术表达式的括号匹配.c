//检查一个算术表达式中的括号是否匹配，算术表达式保存于字符数组ex中 
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
{//将栈*s中的栈顶元素出栈并通过参数x返回给主调函数 
	if(s->top==-1)
	   printf("Error!\n");
	else
	{
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

void Correct(char ex[])
{
	SeqStack *p;
	char x,*ch=&x;
	int i=0;
	Init_SeqStack(&p);
	while(ex[i]!='\0')
	{
		if(ex[i]=='('||ex[i]=='['||ex[i]=='{')
		    Push_SeqStack(p,ex[i]);
		if(ex[i]==')'||ex[i]==']'||ex[i]=='}')
	    {
	    	Top_SeqStack(p,ch);
	    	if(ex[i]==')'&&*ch=='(')
	    	{
	    		Pop_SeqStack(p,ch);
	    		goto l1;
			}
			if(ex[i]==']'&&*ch=='[')
			{
				Pop_SeqStack(p,ch);
				goto l1;
			}
			if(ex[i]=='}'&&*ch=='{')
			{
				Pop_SeqStack(p,ch);
				goto l1;
			}
			else
			  break;
		 } 
	l1: i++;
	}
	if(!Empty_SeqStack(p))
	    printf("Error!\n");
	else
	    printf("Right!\n");
}

int main()
{
	char x[30];
	printf("Input exp:\n");
	scanf("%s",x);
	Correct(x);
	return 0;
}
