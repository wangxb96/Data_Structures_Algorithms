//矩阵的快速转置 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct{
	int i;
	int j;
	int v;
}TNode;
typedef struct{
	int m;
	int n;
	int t;
	TNode data[MAXSIZE];
}TSMatrix;

void CreatMat(TSMatrix *p,int a[3][4],int m,int n)
{
	int i,j;
	p->m=m;
	p->n=n;
	p->t=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		  if(a[i][j]!=0)
		  {
		  	p->data[p->t].i=i;
		  	p->data[p->t].j=j;
		  	p->data[p->t].v=a[i][j];
		  	p->t++;
		  }
	}
}

void FastTranTat(TSMatrix *a,TSMatrix *b)
{
	int i,k,pot[MAXSIZE];
	b->m=a->m;
	b->n=a->n;
	b->t=a->t;
	if(b->t!=0)
	{
		for(k=1;k<=a->n;k++)
		  pot[k]=0;
		for(i=0;i<a->t;i++)
		{
			k=a->data[i].j;
			pot[k+1]=pot[k+1]+1; 
		}
		pot[0]=0;
		for(k=1;k<a->n;k++)
		   pot[k]=pot[k-1]+pot[k];
		for(i=0;i<a->t;i++)
		{
			k=a->data[i].j;
			b->data[pot[k]].i=a->data[i].j;
			b->data[pot[k]].j=a->data[i].i;
			b->data[pot[k]].v=a->data[i].v;
			pot[k]=pot[k]+1;
		}
	}
}

int main()
{
	TSMatrix *p,*q;
	int i,a[3][4]={{0,3,1,0},{1,0,0,0},{0,2,0,1}};
	p=(TSMatrix*)malloc(sizeof(TSMatrix));
	q=(TSMatrix*)malloc(sizeof(TSMatrix));
	CreatMat(p,a,3,4);
	printf("Before TSMatrix:\n");
	printf("   i   j   data\n");
	for(i=0;i<p->t;i++)
	   printf("%4d%4d%4d\n",p->data[i].i,p->data[i].j,p->data[i].v);
	FastTranTat(p,q);
	printf("After TSMatrix:\n");
	printf("   i   j   data\n");
	for(i=0;i<q->t;i++)
	   printf("%4d%4d%4d\n",q->data[i].i,q->data[i].j,q->data[i].v);
	return 0; 
}
