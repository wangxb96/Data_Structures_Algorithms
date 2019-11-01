//关键路径
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	int adjvex;
	int info;
	struct node *next;
}EdgeNode;
typedef struct vnode{
	int indegree;
	int vertex;
	EdgeNode *firstedge;
}VertexNode;
typedef struct{
	char data[MAXSIZE];
	int top;
}SeqStack;

void Init_SeqStack(SeqStack **s)
{
	*s=(SeqStack*)malloc(sizeof(SeqStack));
	(*s)->top=-1;
 } 

int Empty_SeqStack(SeqStack *s)
{
	if(s->top==-1)
	  return 1;
	else
	  return 0;
}

void Push_SeqStack(SeqStack *s,int x)
{
	if(s->top==MAXSIZE-1)
	   printf("Stack is full!\n");
	else
	{
		s->top++;
		s->data[s->top]=x; 
	}
}

void Pop_SeqStack(SeqStack *s,int *x)
{//将栈*s中的栈元素出栈并通过参数x返回给主调函数
   if(s->top==-1)
     printf("Stack is empty!\n");
	else
	{
		*x=s->data[s->top];
		s->top--;
	 } 
}

void print(VertexNode g[],int ve[],int vl[],int n)
{
	int i,j,e,l,dut;
	char tag;
	EdgeNode *p;
	printf("(vi,vj)dut最早开始时间  最晚开始时间  关键活动\n");
	for(i=0;i<n;i++)
	  for(p=g[i].firstedge;p!=NULL;p=p->next)
	  {
	  	j=p->adjvex;
	  	dut=p->info;
	  	e=ve[i];
	  	i=vl[j]-dut;
	  	tag=(e==l)?'*':' ';
	  	printf("(%d,%d)%4d%11d%11d%8c\n",g[i].vertex,g[j].vertex,dut,e,l,tag);
	  }
	for(i=0;i<n;i++)
	  printf("顶点%d的最早发生时间和最迟发生时间:%5d%5d\n",i,ve[i],vl[i]);
}

void CreatAdjlist(VertexNode g[],int e,int n)
{//建立有向图的邻接表，n为顶点数，e为边数，g[]存储n个顶点表结点
   EdgeNode *p;
   int i,j,k,w;
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
   	printf("Input weight of(%d,%d):",i,j);
   	scanf("%d",&w);
   	p=(EdgeNode*)malloc(sizeof(EdgeNode));
   	p->adjvex=j;   //在顶点vi的邻接表中添加邻接点为j的结点
	p->info=w;
	p->next=g[i].firstedge;
	g[i].firstedge=p;
	g[j].indegree=g[j].indegree+1;
   }
}

void Toplogicalorder(VertexNode g[],int n){
	//AOE网用邻接表存储，求各顶点事件的最早发生时间ve（为全局变量数组）
	int i,j,k,dut,count,*x=&j;
	int ve[MAXSIZE],vl[MAXSIZE];
	EdgeNode *p;
	SeqStack *s,*t;
	Init_SeqStack(&s);
	Init_SeqStack(&t);
	count=0;
	for(i=0;i<n;i++)
	  ve[i]=0;
	for(i=0;i<n;i++)
	  if(g[i].indegree==0)
	    Push_SeqStack(s,i);
	while(!Empty_SeqStack(s))//零入度顶点栈s不为空时
	{
	 Pop_SeqStack(s,x); //弹出零入度顶点 
	 Push_SeqStack(t,j);  //将顶点j压入拓扑序列顶点栈t
	 count++; 
	 g[i].firstedge;//根据顶点j的firstedge指针查其邻接表中第一个邻接边结点 
   	 while(p!=NULL)
	 {
		k=p->adjvex;
		g[k].indegree--;  //顶点j的邻接边结点k的入度减1
		if(g[k].indegree==0)
		   Push_SeqStack(s,k); //顶点k入度减1后若其值为0，则压入零入度顶点栈s
		if(ve[j]+p->info>ve[k])
		   ve[k]=ve[j]+p->info;   //计算顶点事件的最早发生时间ve[k]
		p=p->next; 
	}
    }
    if(count<n)//拓扑序列顶点个数未达到n时则AOE网有回路
    {
   	 printf("The AOE network has a cycle!\n");
   	 goto L1;
	} 
    for(i=0;i<n;i++) //初始化数组vl
      vl[i]=ve[n-1];
    while(!Empty_SeqStack(t))//按拓扑排序的逆序求各顶点的vl值 
    {
   	 Pop_SeqStack(t,x); 
   	 for(p=g[j].firstedge;p!=NULL;p=p->next)//计算顶点事件的最迟发生时间vl[j]
	 {
	 	k=p->adjvex;
	 	dut=p->info;
	 	if(vl[k]-dut<vl[j])
	 	   vl[j]=vl[k]-dut;
	  } 
   	 } 
    print(g,ve,vl,n);
    L1: ;
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
	Toplogicalorder(g,n);  //拓扑排序并求出关键路径
	printf("\n");
	return 0; 
}
