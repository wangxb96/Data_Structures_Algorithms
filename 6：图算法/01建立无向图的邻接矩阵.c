//建立无向图的邻接矩阵 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct{
	char vertex[MAXSIZE];      //顶点为字符型且顶点表的长度小于MAXSIZE 
	int edges[MAXSIZE][MAXSIZE];   //边为整形且edges为邻接矩阵 
}MGraph;    //MGraph为采用邻接矩阵存储的图类型

void CreatMGraph(MGraph *g,int e,int n)
{//建立无向图的邻接矩阵g->edges,n为顶点个数，e为边数 
	int i,j,k;
	printf("Input data of vertexs(0~n-1):\n");
	for(i=0;i<n;i++)
	   g->vertex[i]=i;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	     g->edges[i][j]=0;
    for(k=1;k<=e;k++)
    {
    	printf("Input edge of(i,j):");
    	scanf("%d,%d",&i,&j);
    	g->edges[i][j]=1;
    	g->edges[j][i]=1;
	}
 } 
 
int main()
{
	int i,j,n,e;
	MGraph *g;
	g=(MGraph*)malloc(sizeof(MGraph));
	printf("Input size of MGraph:");
	scanf("%d",&n);
	printf("Input number of edge:");
	scanf("%d",&e);
	CreatMGraph(g,e,n);
	printf("Output MGraph:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		   printf("%4d",g->edges[i][j]);
		printf("\n");
	}
	return 0;
}
