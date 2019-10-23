//生成链串与求串长、串连接运算 
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

void StrCat(LiString *s,LiString *t)
{
	LiString *p,*q,*r,*str;
	str=(LiString*)malloc(sizeof(LiString));
	r=str;
	p=t->next;
	while(p!=NULL)
	{
		q=(LiString*)malloc(sizeof(LiString));
		q->data=p->data;
		r->next=q;
		r=q;
		p=p->next;
	}
	r->next=NULL;
	p=s;
	while(p->next!=NULL)
	  p=p->next;
	p->next=str->next;
	free(str); 
}

int main()
{
	LiString *head1,*head2,*p;
	char c1[20]="ABCD",c2[10]="abcd";
	StrAssign(&head1,c1);
	StrAssign(&head2,c2);
	printf("head1=%d\n",StrLength(head1));
	StrCat(head1,head2);
	p=head1->next;
	while(p!=NULL)
	{
		printf("%2c",p->data);
		p=p->next;
	}
	printf("\n");
	return 0;
} 
