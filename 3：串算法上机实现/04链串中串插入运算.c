//¡¥¥Æ÷–¥Æ≤Â»Î‘ÀÀ„
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
 
void StrInsert(LiString *s,int i,LiString *t)
{
	LiString *p,*r;
	int k;
	p=s->next;
	for(k=0;k<i-1;k++)
	  p=p->next;
	r=p->next;
	p->next=t->next;
	p=t;
	while(p->next!=NULL)
	   p=p->next;
	p->next=r; 
}

int main()
{
	LiString *head1,*head2,*p;
	char c1[20]="ABCD",c2[10]="abcd";
	StrAssign(&head1,c1);
	StrAssign(&head2,c2);
	StrInsert(head1,2,head2);
	p=head1->next;
	while(p!=NULL)
	{
		printf("%2c",p->data);
		p=p->next;
	}
	printf("\n");
	return 0;
}
