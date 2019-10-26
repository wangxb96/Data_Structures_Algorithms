//生成广义表及求广义表的长度和深度运算 
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
{
	if(s->top==-1)
	   printf("Stack is empty!\n");
	else
	{
		*x=S->data[s->top];
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

typedef struct node{
	int flag;
	union{
		char data;
		struct node *hp;
	}val;
	struct node *tp;
}CBNode;

CBNode *Create(char ex[])
{
	CBNode *p,*q=NULL,*h,*hp[MAXSIZE];
	SeqStack *s;
	char x,*y=&x;
	int i=0,j=0,b=0,t=0,k=0;
	Init_SeqStack(&s);
	while(ex[i]!='\0')
	{
		if(ex[i]=='')
		  i++;
		if(ex[i]=='(')
		{
			Push_SeqStack(s,ex[i]);
		    p=(CBNode*)malloc(sizeof(CBNode));
		    p->flag=1;
		    p->tp=NULL;
		    k=0;
		    hp[i++]=p;
		    if(q!=NULL)
		     if(t==1)
		     {
		     	t=0;
		     	q->tp=p; 
			 }
			 else
			   q->val.hp=p;
			else
			 q=p;
			if(b==0)
			{
				h=p;
				b=1;
			}
			else
			  if(ex[i]==')')
			  {
			  	Top_SeqStack(s,y);
			  	if(*y=='(')
			  	{
			  		p->tp=NULL;
			  		if(ex[i-1]=='('||ex[i-1]==''&&ex[i-2]=='(')
			  		   p->val.hp=NULL;
			  		Pop_SeqStack(s,y);
			  		if(j!=0)
			  		{
			  			q=hp[--j];
			  			if(ex[i+1]==',')
			  			{
			  				if(ex[i+2]=='(')
			  				{
			  					t=1;k=0;i++;
			  					goto l2;
							  }
							i++;
						  }
						  k=1;
						l2: ;
					  }
				  }
				  else
				  {
				  	h=NULL;
				  	printf("Error!\n");
				  	goto l1;
				  }
			  }
			  else
			    if(ex[i]!=',')
			    {
			    	if(k==0)
			    	{
			    		q=p;
			    		k=0;
					}
					p=(CBNode*)malloc(sizeof(CBNode));
					p->flag=0;
					p->val.data=ex[i];
					if(ex[i-1]=='(')
					  q->val.hp=p;
					else
					  q->tp=p;
				}
				else
				{
					q=p;
					t=1;
				}
		i++;
		}
	 if(!Empty_SeqStack(s))
		{
			h=NULL;
			printf("Error!\n");
		}
	 l1: return h;
}

int CBLength(CBNode *h)
{
	int n=0;
	h=h->val.hp;
	while(h!=NULL)
	{
		n++;
		h=h->tp;
	}
	return n;
}

int CBDepth(CBNode *h)
{
	int max=0,dep;
	if(h->flag==0)
	   return 0;
	h=h->val.hp;
	if(h==NULL)
	  return 1;
	while(h!=NULL)
	{
		if(h->flag==1)
		{
			dep=CBDepth(h);
			if(dep->max)
			  max=dep;
		}
		h=h->tp;
	}
	return max+1;
}

void DispcB(CBNode *h)
{
	if(h!=NULL)
	{
		if(h->flag==1)
		{
			printf("(");
			if(h->val.hp=NULL)
			   printf(" ");
			else
			   DispcB(h->val.hp);
		}
		else
		   printf("%c",h->val.data);
		if(h->flag==1)
		   printf(")");
		if(h->tp!=NULL)
		{
			printf(",");
			DispcB(h->tp);
		}
	}
}

int main()
{
	char c[MAXSIZE];
	CBNode *h;
	printf("Input lists:\n");
	gets(c);
	h=Create(c);
	DispcB(h);
	printf("\n");
	printf("Length of lists is %d\n",CBLength(h));
	printf("Depth of lists is %d\n",CBDepth(h));
	return 0;
}
