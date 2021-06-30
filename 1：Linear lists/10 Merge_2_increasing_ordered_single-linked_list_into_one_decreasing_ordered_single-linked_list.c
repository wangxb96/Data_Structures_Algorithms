//对两个元素递增有序的单链表A和B，编写算法将A、B合并成一个按元素递减有序（允许有相同值）的单链表C，
//要求算法使用A、B中的原有结点，不允许增加新结点 
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char data;
	struct node *next;
}LNode;

LNode *CreateLinkList()
{
	LNode *head,*p,*q;
	int i,n;
	head=(LNode*)malloc(sizeof(LNode));
	head->next=NULL;
	p=head;
	q=p;
	printf("Input length of list:\n");
	scanf("%d",&n);
	printf("Input data of list:\n");
	for(i=1;i<=n;i++)
	{
		p=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=NULL;
		q->next=p;
		q=p;
	}
	return head;
}

void Merge(LNode *A,LNode *B,LNode **C)
{
	LNode *p,*q,*s;
	p=A->next;
	q=B->next;
	*C=A;
	(*C)->next=NULL;
	free(B);
	while(p!=NULL&&q!=NULL)
	{
		if(p->data<q->data)
		{
			s=p;
			p=p->next;
		}
		else
		{
			s=q;
			q=q->next;
		}
		s->next=(*C)->next;
		(*C)->next=s;
	}
	if(p==NULL)
	   p=q;
	while(p!=NULL)
	{
		s=p;
		p=p->next;
		s->next=(*C)->next;
		(*C)->next=s;
	}
}

void print(LNode *p)
{
	p=p->next;
	while(p!=NULL)
	{
		printf("%d",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	LNode *A,*B,*C;
	printf("Input data of list A:\n");
	A=CreateLinkList();
	printf("Output list A:\n");
	print(A);
	printf("Input data of list B:\n");
	B=CreateLinkList();
	printf("Output list B:\n");
	print(B);
	printf("Make list C:\n");
	Merge(A,B,&C);
	printf("Output list C:\n");
	print(C);
	return 0;
}
