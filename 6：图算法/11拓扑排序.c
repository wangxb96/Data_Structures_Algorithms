//拓扑排序
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{//邻接表结点 
	int adjvex;
	struct node *next; 
}EdgeNode;
typedef struct vnode{//顶点表结点 
	int indegree;  //顶点入度
	int  vertex;
	EdgeNode *firstedge; 
}VertexNode;

void CreatAdjlist(VertexNode g[],int e,int n)
{//建立有向图的邻接表，n为顶点数，e为边数，g[]存储n各顶点表结点
   EdgeNode *p;
   int i,j,k;
   printf("Input data of vertex(0~n-1):\n");
   for(i=0;i<n;i++)
   {
   	g[i].vertex=i;
   	g[i].firstedge=NULL;
   	g[i].indegree=0;
	} 
   for(k=1;k<=e;k++)
   {
   	printf("Input edge of(i,j):");
	scanf("%d,%d",&i,&j);
	p=(EdgeNode*)malloc(sizeof(EdgeNode));
	p->adjvex=j;  //在顶点vi的邻接表中添加邻接点为j的结点
	p->next=g[i].firstedge;  
	g[i].firstedge=p;
	g[j].indegree=g[j].indegree+1; 
   }
 } 

void Top_Sort(VertexNode g[],int n)
{//用带有入度域的邻接表存储AOV网并输出一种拓扑排序，n为顶点个数
  int i,j,k,top,m=0;
  EdgeNode *p;
  top=-1;   //栈顶指针初始化，-1为链尾
  for(i=0;i<n;i++)  //依次将入度为0的顶点链接成一个链栈
    if(g[i].indegree==0)
	{
		g[i].indegree=top;
		top=i;
	 } 
	while(top!=-1)
	{
		j=top;  //取出栈顶入度为0的一个顶点
		top=g[top].indegree;  //栈顶指针指向弹栈后的下一个入度为0顶点
		printf("%d",g[j].vertex);
		m++;
		p=g[j].firstedge;  //根据顶点j的firstedge指针查其邻接表的第一个邻接边结点
		while(p!=NULL)//删除顶点j的所有出边 
		{
			k=p->adjvex;
			g[k].indegree--;  //将顶点j的邻接边结点k入度减1
			if(g[k].indegree==0) //顶点k入度减1后若其值为0则将该顶点k链入链栈
			{
				g[k].indegree=top;
				top=k;
			 } 
			p=p->next;
		 } 
	}
	if(m<n)
	  printf("The AOV network has a cycle!\n");
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
	printf("Top Sort:\n");
	Top_Sort(g,n);
	printf("\n");
	return 0;
 } 
