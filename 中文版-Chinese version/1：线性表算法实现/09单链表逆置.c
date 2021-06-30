//已知单链表H如10-1,写一算法将其逆置 
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char data;
	struct node *next;
}LNode;

LNode* CreateLinkList()
{
	LNode *head,*p,*q;
	char x;
	head=(LNode*)malloc(sizeof(LNode));
	head->next=NULL;
	p=head;
	q=p;
	printf("Input any char string:\n");
	scanf("%c",&x);
	while(x!='\n')
	{
		p=(LNode*)malloc(sizeof(LNode));
		p->data=x;
		p->next=NULL;
		q->next=p;
		q=p;
		scanf("%c",&x);
	}
	return head;
 } 
 
void Convert(LNode *H)
{
	LNode *p,*q;
	p=H->next;
	H->next=NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		q->next=H->next;
		H->next=q;
	}
}

int main()
{
	LNode *A,*p;
	A=CreateLinkList();
	Convert(A);
	p=A->next;
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
	return 0;
}

 
