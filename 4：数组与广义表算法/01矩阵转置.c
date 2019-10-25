//矩阵转置
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct{
	int i;//行号 
	int j;//列号 
	int v;//非零元素值 
}TNode;

typedef struct{
	int m;
	int n;
	int t;
	TNode data[MAXSIZE];
}TSMatrix;

void CreatMat(TSMatrix *p,int a[3][4],int m,int n)
{//p指向三元组表，a指向存储稀疏矩阵的二维数组，m、n为矩阵的行数和列数 
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

void TranTat(TSMatrix *a,TSMatrix *b)
{
	int k,p,q;
	b->m=a->m;
	b->n=a->n;
	b->t=a->t;
	if(b->t!=0)
	{
		q=0;
		for(k=0;k<a->n;k++)
		{
			for(p=0;p<a->t;p++)
			  if(a->data[p].j==k)
			  {
			  	b->data[q].i=a->data[p].j;
			  	b->data[q].j=a->data[p].i;
			  	b->data[q].v=a->data[p].v;
			  	q++;
			  }
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
	printf("    i     j     data\n");
	for(i=0;i<p->t;i++)
	   printf("%4d%4d%4d\n",p->data[i].i,p->data[i].j,p->data[i].v);
	TranTat(p,q);
	printf("After TSMatrix:\n");
	printf("    i     j     data\n");
	for(i=0;i<q->t;i++)
	   printf("%4d%4d%4d\n",q->data[i].i,q->data[i].j,q->data[i].v);
}

