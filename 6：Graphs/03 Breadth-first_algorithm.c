//图的广度优先搜索 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node1{
	int adjvex;
	struct node1 *next; 
}EdgeNode;
typedef struct vnode{
	int vertex;
	EdgeNode *firstedge; //指向邻接表第一个邻接边结点的指针域 
}VertexNode;

void CreatAdjlist(VertexNode g[],int e,int n)
{//建立无向图的邻接表，n为顶点数，e为边数，g[]存储n个顶点表结点 
	EdgeNode *p;
	int i,j,k;
	printf("Input dataof vertex(0~n-1):\n");
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
		p->adjvex=j;   //在顶点vi的邻接表中添加邻接点为j的结点 
		p->next=g[i].firstedge;
		g[i].firstedge=p;
		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvex=i;    //在顶点vj的邻接表中添加邻接点为i的结点
		p->next=g[j].firstedge;
		g[j].firstedge=p;
	}
}

typedef struct node{
	int data;
	struct node *next;
}QNode;
typedef struct{
	QNode *front,*rear;
}LQueue;

void Init_LQueue(LQueue **q)//创建一个带头结点的空队列
{
	QNode *p;
	*q=(LQueue*)malloc(sizeof(LQueue));
	p=(QNode*)malloc(sizeof(QNode));
	p->next=NULL;
	(*q)->front=p;
	(*q)->rear=p;
 } 

int Empty_LQueue(LQueue *q)
{
	if(q->front==q->rear)
	   return 1;
	else
	   return 0;
}

void In_LQueue(LQueue *q,int x)
{
	QNode *p;
	p=(QNode*)malloc(sizeof(QNode));
	p->data=x;
	p->next=NULL;
	q->rear->next=p;
	q->rear=p;
}

void Out_LQueue(LQueue *q,int *x)
{
	QNode *p;
	if(Empty_LQueue(q))
	   printf("Queue is empty!\n");
	else
	{
		p=q->front->next;
		q->front->next=p->next;
		*x=p->data;
		free(p);
		if(q->front->next==NULL)//出队后队为空，则置为空队列
		   q->rear=q->front; 
	}
}
int visited[MAXSIZE];
void BFS(VertexNode g[],LQueue *Q,int i)
{//广度优先搜索遍历邻接表存储的图，g为顶点表，Q为队指针，i为第i个顶点
   int j,*x=&j;
   EdgeNode *p;
   printf("%4d",g[i].vertex);
   visited[i]=1;
   In_LQueue(Q,i);
   while(!Empty_LQueue(Q))
   {
   	Out_LQueue(Q,x);
   	p=g[j].firstedge;//根据顶点j的表头指针查找其邻接表的第一个邻接边结点
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
		{
			printf("%4d",g[p->adjvex].vertex);
			visited[p->adjvex]=1;
			In_LQueue(Q,p->adjvex);
		}
		p=p->next;
	 } 
	} 
}

int main()
{
	int e,n;
	VertexNode g[MAXSIZE];
	LQueue *q;
	printf("Input number of node:\n");
	scanf("%d",&n);
	printf("Input number of edge:\n");
	scanf("%d",&e);
	printf("Make adjlist:\n");
	CreatAdjlist(g,e,n);
	Init_LQueue(&q);
	printf("BFSTraverse:\n");
	BFS(g,q,0);    //广度优先遍历以邻接表存储的无向图 
	printf("\n");
	return 0;
}
