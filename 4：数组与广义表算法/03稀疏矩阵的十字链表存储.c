//稀疏矩阵的十字链表存储
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct node{
	int row,col;
	struct node *down,*right;
	union{
		int v;
		struct node *next;
	}tag;
}MNode;

void print(MNode *h[],int m,int n)
{
	MNode *p;
	int i;
	printf("十字链表的行链表:\n");
	for(i=0;i<m;i++)
	{
		p=h[i]->right;
		printf("H%d:   ",i);
		while(p!=h[i])
		{
			printf("(%d,%d):%d,",p->row,p->col,p->tag.v);
			p=p->right;
		}
		printf("\n");
	}
	printf("十字链表的列链表:\n");
	for(i=0;i<n;i++)
	{
		p=h[i]->down;
		printf("H%d:   ",i);
		while(p!=h[i])
		{
			printf("(%d,%d):%d,",p->row,p->col,p->tag.v);
			p=p->down;
		}
		printf("\n");
	}
 } 
 
void CreatMat(MNode **mh,MNode *h[])
{
	MNode *p,*q;
	int i,j,k,m,n,t,v,max;
	printf("Input m,n,t:");
	scanf("%d,%d,%d",&m,&n,&t);
	*mh=(MNode*)malloc(sizeof(MNode));
	(*mh)->row=m;
	(*mh)->col=n;
	p=*mh;
	if(m>n)
	  max=m;
	else
	  max=n;
	for(i=0;i<max;i++)
	{
		h[i]=(MNode*)malloc(sizeof(MNode));
		h[i]->down=h[i];
		h[i]->right=h[i];
		h[i]->row=-1;
		h[i]->col=-1;
		p->tag.next=h[i];
		p=h[i];
	}
	p->tag.next=*mh;
	for(k=0;k<t;k++)
	{
		printf("Input i,j,v:");
		scanf("%d,%d,%d",&i,&j,&v);
		p=(MNode*)malloc(sizeof(MNode));
		p->row=i;
		p->col=j;
		p->tag.v=v;
		q=h[i];
		while(q->right!=h[i]&&q->right->col<j)
		  q=q->right;
		p->right=q->right;
		q->right=p;
		q=h[j];
		while(q->down!=h[j]&&q->down->row<i)
		  q=q->down;
		p->down=q->down;
		q->down=p;
	}
	print(h,m,n);
 } 
 
int main()
{
	MNode *mh,*h[MAXSIZE];
	CreatMat(&mh,h);
	return 0;
}
 

