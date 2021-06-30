//广度优先生成树
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct{
  int data[MAXSIZE];
  int rear,front;
}SeQueue;

void Int_SeQueue(SeQueue **q)
{
	*q=(SeQueue*)malloc(sizeof(SeQueue));
	(*q)->front=0;
	(*q)->rear=0;
 } 

int Empty_SeQueue(SeQueue *q)
{
	if(q->front==q->rear)
	   return 1;
	else
	   return 0;
}

void In_SeQueue(SeQueue *q,int x)
{
	if((q->rear+1)%MAXSIZE==q->front)
	   printf("Queue is full!\n");
	else
	{
		q->rear=(q->rear+1)%MAXSIZE;
	    q->data[q->rear]=x;
	}
}

void Out_SeQueue(SeQueue *q,int *x)
{
	if(q->front==q->rear)
	   printf("Queue is empty!\n");
	else
	{
		q->front=(q->front+1)%MAXSIZE;
		*x=q->data[q->front];
	}
}

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
  	g[i].firstedge=NULL;
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
void BFSTree(VertexNode g[],int i)
{//广度优先搜索遍历邻接表存储的图，g为顶点表，Q为队指针，i为第i个顶点
   int j,*x=&j;
   SeQueue *q;
   EdgeNode *p;
   visited[i]=1;
   Int_SeQueue(&q);
   In_SeQueue(q,i);
   
   while(!Empty_SeQueue(q))
   {
   	 Out_SeQueue(q,x); //队头顶点出队并送j
	 p=g[j].firstedge;//根据顶点j的表头指针查找其邻接表的第一个邻接边结点
	 while(p!=NULL)
	 {
	 	if(!visited[p->adjvex])
	 	{
	 		printf("(%d,%d),",j,p->adjvex);
	 		visited[p->adjvex]=1;
	 		In_SeQueue(q,p->adjvex);
		 }
		p=p->next;   //在顶点j的邻接表中查找j的下一个邻接边结点 
	  }  
	} 
}

int main()
{
	int e,n;
	VertexNode  g[MAXSIZE];
	printf("Input number of node:\n");
	scanf("%d",&n);
	printf("Input number of edge:\n");
	scanf("%d",&e);
	printf("Make adjlist:\n");
	CreatAdjlist(g,e,n);//建立无向图的邻接表
	BFSTree(g,0); //由顶点0开始生成广度优先生成树 
	printf("\n"); 
	return 0;
}
