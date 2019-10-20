#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char data;
	struct node *next;
}StackNode;

void Init_LinkStack(StackNode **s)
{
	*s=NULL;
 } 
 
int Empty_LinkStack(StackNode *s)
{
	if(s==NULL)
	  return 1;
	else
	  return 0;
}

void Push_LinkStack(StackNode **top,char x)
{
	StackNode *p;
	p=(StackNode*)malloc(sizeof(StackNode));
	p->data=x;
	p->next=*top;
	*top=p;
}

void Pop_LinkStack(StackNode **top,char *x)
{
	StackNode *p;
	if(*top==NULL)
	   printf("Stack is empty!\n");
	else
	{
		*x=(*top)->data;
		p=*top;
		*top=(*top)->next;
		free(p);
	}
}

void print(StackNode *p)
{
	while(p!=NULL){
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	StackNode *s;
	char x,*y=&x;
	Init_LinkStack(&s);
	if(Empty_LinkStack(s))
	   printf("Stack is empty!\n");
	printf("Input any string:\n");
	scanf("%c",&x);
	while(x!='\n')
	{
		Push_LinkStack(&s,x);
		scanf("%c",&x);
	}
	printf("Output string:\n");
	print(s);
	printf("Output stack:\n");
	Pop_LinkStack(&s,y);
	printf("Element of output stack is %c\n",*y);
	printf("Output string :\n");
	print(s);
	return 0;
}
