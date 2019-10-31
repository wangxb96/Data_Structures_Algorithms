//深度优先生成树
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	int adjvex;
	struct node *next;
}EdgeNode;

typedef struct vnode{
	int vertex;
	EdgeNode *firstedge;
}VertexNode;

void CreatAdjlist(VertexNode g[],int e,int n)
{//建立无向图的邻接表，n为顶点数，e为边数，g[]存储n个顶点表结点 
	EdgeNode *p;
	int i,j,k;
	printf("Input data of vertex(0~n-1):\n");
	for(i=0;i<n;i++)
	{
		g[i].vertex=i;
		g[i].firstedge=NULL;//初始化指向顶点i的邻接表表头指针 
	}
	for(k=1;k<=e;k++)
	{
		printf("Input edge of(i,j):");
		scanf("%d,%d",&i,&j);
		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvex=j;
		p->next=g[i].firstedge;
		g[i].firstedge=p;
		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvex=i;
		p->next=g[j].firstedge;
		g[j].firstedge=p;
	}
 } 
int visited[MAXSIZE];
void DFSTree(VertexNode g[],int i)
{
	EdgeNode *p;
	visited[i]=1;
	p=g[i].firstedge;//根据顶点i的指针firstedge查找其邻接表的第一个邻接边结点
	while(p!=NULL) 
	{
		if(!visited[p->adjvex]){
			printf("(%d,%d),",i,p->adjvex);
			DFSTree(g,p->adjvex);
		}
		p=p->next;
	}
}

void DFSTraverse(VertexNode g[],int n)//生成深度优先生成树 
{//深度优先搜索遍历以邻接表存储的图，其中g为顶点表，n为顶点个数
   int i;
   for(i=0;i<n;i++)
     visited[i]=0;
   for(i=0;i<n;i++)
     if(!visited[i])
	    DFSTree(g,i);//从未访问过的顶点i开始遍历 
}

int main()
{
	int e,n;
	VertexNode g[MAXSIZE];
	printf("Input number of node:\n");
	scanf("%d",&n);
	printf("Input number of edge:\n");
	scanf("%d",&e);
	printf("Make adjlist:\n");
	CreatAdjlist(g,e,n);
	printf("DFSTraverse:\n");
	DFSTraverse(g,n);
	printf("\n");
	return 0;
}
