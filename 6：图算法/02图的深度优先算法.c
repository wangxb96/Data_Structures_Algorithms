//图的深度优先算法
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{//邻接表结点 
	int adjvex;
	struct node *next;
}EdgeNode;

typedef struct vnode{//邻接点域 
	int vertex;
	EdgeNode *firstedge;
}VertexNode;   

void CreatAdjlist(VertexNode g[],int e,int n)
{//建立无向图的邻接表，n为顶点数，e为边数，g[]存储n个顶点结点
   EdgeNode *p;
   int i,j,k;
   printf("Input data of vetex(0~n-1):\n");
   for(i=0;i<n;i++)
   {
   	g[i].vertex=i;    //读入顶点i信息 
   	g[i].firstedge=NULL;   //初始化指向顶点i的邻接表表头指针 
	} 
   for(k=1;k<=e;k++)
   {
   	printf("Input edge of(i,j):");
   	scanf("%d,%d",&i,&j);
   	p=(EdgeNode*)malloc(sizeof(EdgeNode));
   	p->adjvex=j;  //在顶点vi的邻接表中添加邻接点为j的结点
   	p->next=g[i].firstedge;
   	g[i].firstedge=p;
   	g[i].firstedge=p;
   	p=(EdgeNode*)malloc(sizeof(EdgeNode));
   	p->adjvex=i;     //在顶点vj的邻接表中添加邻接点为i的结点 
   	p->next=g[j].firstedge;   
   	g[j].firstedge=p;
   }
}

int visited[MAXSIZE];
void DFS(VertexNode g[],int i)
{
	EdgeNode *p;
	printf("%4d",g[i].vertex);   //输出顶点i信息，即访问顶点i 
	visited[i]=1;   //置顶点i为访问过标志
	p=g[i].firstedge;  //根据顶点i的指针firstedge查找其邻接表的第一个邻接边结点
	while(p!=NULL)
	{
		if(!visited[p->adjvex])//如果邻接的这个边结点未被访问过
		DFS(g,p->adjvex);  //对这个边结点进行深度优先搜索 
		p=p->next; 
	 } 
}

void DFSTraverse(VertexNode g[],int n)
{//深度优先搜索遍历以邻接表存储的图，其中g为顶点表，n为顶点个数
   int i;
   for(i=0;i<n;i++)
       visited[i]=0;   //访问标志置0 
   for(i=0;i<n;i++)
       if(visited[i])
	     DFS(g,i);   //从未访问过的顶点i开始遍历 
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
	CreatAdjlist(g,e,n);  //建立无向图的邻接表
	printf("DFSTraverse:\n");
	printf("\n");
	return 0; 
}
