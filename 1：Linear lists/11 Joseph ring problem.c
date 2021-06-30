//约瑟夫问题(Josephus)问题：设有n个人围成一圈并顺序编号1~n。由编号为k的人进行1到m的报数，数到m的人出圈。
//接着再从他的下一个人重新开始1到m的报数，直到所有人都出圈为止。请输出出圈人的出圈次序。 
#include<stdio.h> 
#include<stdlib.h>
typedef struct node{
	char data;
	struct node *next;
}LNode;

void Josephus(int n,int m,int k)
{
	LNode *p,*q;
	int i;
	p=(LNode*)malloc(sizeof(LNode));
	q=p;
	for(i=1;i<n;i++)
	{
	   q->data=k;
	   k=k%n+1;
	   q->next=(LNode*)malloc(sizeof(LNode));
	   q=q->next;
	}
	q->data=k;
	q->next=p;
	while(p->next!=p)
	{
		for(i=1;i<=m;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		printf("%4d",p->data);
		free(p);
		p=q->next;
	}
	printf("%4d",p->data);
}

int main()
{
	int n,m,k;
	printf("Please input n,m,k:\n");
	scanf("%d,%d,%d",&n,&m,&k);
	Josephus(n,m,k);
	printf("\n");
	return 0;
}
