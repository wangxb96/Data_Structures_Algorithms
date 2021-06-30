//链串中求子串运算 
#include<stdio.h>
#include<stdlib.h>
typedef struct snode{
	char data;
	struct snode *next;
}LiString;

void StrAssign(LiString **s,char str[])
{
	LiString *p,*r;
	int i;
	*s=(LiString*)malloc(sizeof(LiString));
	r=*s;
	for(i=0;str[i]!='\0';i++)
	{
		p=(LiString*)malloc(sizeof(LiString));
		p->data=str[i];
		r->next=p;
		r=p;
	}
	r->next=NULL;
}

int StrLength(LiString *s)
{
	int i=0;
	LiString *p=s->next;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}

void SubStr(LiString *s,LiString **str,int i,int len)
{
	LiString *p,*q,*r;
	int k;
	p=s->next;
	*str=(LiString*)malloc(sizeof(LiString));
	(*str)->next=NULL;
	r=*str;
	if(i<1||i>StrLength(s)||len<0||i+len-1>StrLength(s))
	   goto L1;
	for(k=0;k<i-1;k++)
	   p=p->next;
	for(k=0;k<len;k++)
	{
		q=(LiString*)malloc(sizeof(LiString));
		q->data=p->data;
		r->next=q;
		r=q;
		p=p->next;
	}
	r->next=NULL;
	L1: ;
}

int main()
{
	LiString *head1,*head2,*p;
	char c1[20]="ABCabD";
	StrAssign(&head1,c1);
	SubStr(head1,&head2,3,3);
	p=head2->next;
	while(p!=NULL)
	{
		printf("%2c",p->data);
		p=p->next;
	 } 
	printf("\n");
	return 0;
}
