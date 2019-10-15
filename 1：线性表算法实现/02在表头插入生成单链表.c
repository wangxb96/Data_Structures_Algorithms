//在表头插入生成单链表
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char data;
	struct node *next;
}LNode;

void CreateLinkList(LNode **head)
{
	//将主调函数中指向待生成单链表的指针地址传给**head
	char x;
	LNode *p;
	*head=(LNode*)malloc(sizeof(LNode));
	(*head)->next=NULL;
	printf("Input any char string:\n");
	scnaf("%c",&x);
	while(x!='\n')
	{
		p=(LNode*)malloc(sizeof(LNode));
		p->data=x;
		p->next=(*head)->next;
		(*head)->next=p;
		scanf("%c",&x);
	}
 } 

int main()
{
	LNode *h,*p;
	CreateLinkList(&h);
	p=h->next;
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printt("\n");
    return 0;
}
