//单链表基本运算 
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char data;
	struct node *next;
}LNode;

LNode *CreateLinkList()
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

int Length_LinkList(LNode* head)
{
	LNode *p=head;
	int i=0;
	while(p->next!=NULL)
	{
		p=p->next;
		i++;
	}
	return i;
}

LNode *Get_LinkList(LNode *head,int i)
{
	LNode *p=head;
	int j=0;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	return p;
}

LNode *Locate_LinkList(LNode *head,char x)
{
	LNode *p=head->next;
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
	}
	return p;
}

void Insert_LinkList(LNode *head,int i,char x)
{
	LNode *p,*s;
	p=Get_LinkList(head,i-1);
	if(p==NULL)
	   printf("Error!\n");
	else
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=p->next;
		p->next=s;
	}
}

void Del_LinkList(LNode *head,int i)
{
	LNode *p,*s;
	p=Get_LinkList(head,i-1);
	if(p==NULL)
	  printf("第i-1个结点不存在！\n");
	else
	  if(p->next==NULL)
	     printf("第i个结点不存在！\n");
	  else
	   {
	   	s=p->next;
	   	p->next=s->next;
	   	free(s);
	   }
}

void print(LNode *h)
{
	LNode *p;
	p=h->next;
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	LNode *h,*p;
	int i;
	char x;
	h=CreateLinkList();
	print(h);
	i=Length_LinkList(h);
	printf("Length=%d\n",i);
	print("Input order and search to element:\n");
	scanf("%d",&i);
	p=Get_LinkList(h,i);
	if(p!=NULL)
	  printf("Element is %c\n",p->data);
	else
	  print("search fail!\n");
	printf("Input value of element and search to elment:\n");
	getchar();
	scanf("%c",&x);
	p=Locate_LinkList(h,x);
	if(p!=NULL)
	   printf("Element is %c\n",p->data);
	else
	   printf("Search fail!\n");
	printf("Insert a element,input site and value of element:\n");
	scanf("%d,%c",&i,&x);
	Insert_LinkList(h,i,x);
	print(h);
	printf("Delete a element,input site of element:\n");
	scanf("%d",&i);
	Del_LinkList(h,i);
	print(h);
	return 0;
}
