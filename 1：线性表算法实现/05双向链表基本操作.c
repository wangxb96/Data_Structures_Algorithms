//双向链表基本操作 
#include<stdio.h>
#include<stdlib.h>
typedef struct dlnode{
	char data;
	struct dlnode *prior,*next;
}DLNode;

DLNode *CreateDlinkList()
{
	DLNode *head,*s;
	char x;
	head=(DLNode*)malloc(sizeof(DLNode));
	head->prior=head;
	head->next=head;
	printf("Input any char string:\n");
	scanf("%c",&x);
	while(x!='\n')
	{
		s=(DLNode*)malloc(sizeof(DLNode));
		s->data=x;
		s->prior=head;
		s->next=head->next;
		head->next->prior=s;
		head->next=s;
		scanf("%c",&x);
	}
	return head;
}

DLNode *Get_DLinkList(DLNode *head,int i)
{
	DLNode *p=head;
	int j=0;
	while(p->next!=head&&j<i)
	{
		p=p->next;
		j++;
	 } 
	if(p->next!=head)
	   return p;
	else
	   return NULL;
}

void Insert_DLinkList(DLNode *head,int i,char x)
{
	DLNode *p,*s;
	p=Get_DLinkList(head,i-1);
	if(p==NULL)
	  printf("ERROR!\n");
	else
	{
		s=(DLNode*)malloc(sizeof(DLNode));
		s->data=x;
		s->prior=p;
		s->next=p->next;
		p->next->prior=s;
		p->next=s;
	}
 } 
 
void Del_DLinkList(DLNode *head,int i)
{
	DLNode *p;
	p=Get_DLinkList(head,i);
	if(p==NULL)
	  printf("第i个数据结点不存在!\n"); 
	else
	{
		p->prior->next=p->next;
		p->next->prior=p->prior;
		free(p);
	}
}

void print1(DLNode *h)
{
	DLNode *p;
	p=h->next;
	while(p!=h)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}

void print2(DLNode *h)
{
	DLNode *p;
	p=h->prior;
	while(p!=h)
	{
		printf("%c",p->data);
		p=p->prior;
	}
	printf("\n");
}

int main()
{
	DLNode *h,*p;
	int i;
	char x;
	h=CreateDlinkList();
	printf("Output list for next\n");
	print1(h);
	printf("Output list for prior\n");
	print2(h);
	printf("Input order and search to element:\n");
	scanf("%d",&i);
	p=Get_DLinkList(h,i);
	if(p!=NULL)
	   printf("Element is %c\n",p->data);
	else
	   printf("Search fail!\n");
	printf("Insert element,Input site and value of element:\n");
	scanf("%d,%c",&i,&x);
	Insert_DLinkList(h,i,x);
	print1(h);
	printf("Delete a element,Input site of element:\n");
	scanf("%d",&i);
	Del_DLinkList(h,i);
	print1(h);
	return 0;
}
