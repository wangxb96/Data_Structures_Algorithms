//单源点最短路径的Dijkstra算法
#include<stdio.h>
#define MAXSIZE 6
#define INF 32767
void Ppath(int path[],int i,int v0)
{//先序递归查找最短路径(源点为v0)上的顶点
   int k;
   k=path[i];
   if(k!=v0)//顶点vk不是源点v0时
   {
   	Ppath(path,k,v0); //递归查找顶点vk的前一个顶点
	printf("%d,",k); 
	} 
 } 
 
void Dispath(int dist[],int path[],int s[],int v0,int n)//输出最短路径的函数
{
	int i;
	for(i=0;i<n;i++)
	if(s[i]==1)
	{
		printf("从%d到%d的最短路径长度为：%d，路径为：",v0,i,dist[i]);
		printf("%d,",v0);   //输出路径上的源点v0 
		Ppath(path,i,v0);   //输出路径上的中间顶点vi 
		printf("%d\n",i);   //输出路径上的终点 
	}
	else
	  printf("从%d到%d不存在路径\n",v0,i); 
 } 
 
void Dijkstra(int gm[][MAXSIZE],int v0,int n)
{
	int dist[MAXSIZE],path[MAXSIZE],s[MAXSIZE];
	int i,j,k,mindis;
	for(i=0;i<n;i++)
	{
		dist[i]=gm[v0][i];   //v0到vi的最短路径初值赋给dist[i]
		s[i]=0;    //s[i]=0表示顶点vi属于T集
		if(gm[v0][i]<INF)  //路径初始化，MAXCOST为可取的最大常数 
		   path[i]=v0;   //源点v0是vi当前最短路径中的前一个顶点
		else
		   path[i]=-1;   //v0到vi没有边 
	}
	s[v0]=1;
	path[v0]=0;  //v0并入集合S且v0的当前最短路径中无前一个顶点 
	for(i=0;i<n;i++)//对除v0外的n-1顶点寻找最短路径，即循环n-1次 
	{
		mindis=INF;
		for(j=0;j<n;j++) //从当前集合T中选择一个路径长度最短的顶点vk
		  if(s[j]==0&&dist[j]<mindis)
		  {
		  	k=j;
		  	mindis=dist[j];
		   } 
		s[k]=1;   //顶点vk加入集合S中
		for(j=0;j<n;j++)//调整源点v0到集合T中任一顶点ｖｊ的路径长度
		    if(s[j]==0)  //顶点vj在集合T中
		      if(gm[k][j]<INF&&dist[k]+gm[k][j]<dist[j])
			  {//当v0到vj的路径长度小于v0到vk和vk到vj的路径长度时
			     dist[j]=dist[k]+gm[k][j];
				 path[j]=k;  //vk是当前最短路径中vj的前一个顶点 
			   } 
	}
	Dispath(dist,path,s,v0,n);//输出最短路径 
}

int main()
{
	int g[MAXSIZE][MAXSIZE]={{INF,20,15,INF,INF,INF},{2,INF,INF,INF,10,30},{INF,4,INF,INF,INF,10},
	                     {INF,INF,INF,INF,INF,INF},{INF,INF,INF,15,INF,INF},{INF,INF,INF,4,10,INF}};  //定义邻接矩阵g并给邻接矩阵g赋值
    Dijkstra(g,0,6);//求顶点0的最短路径 
	return 0;
}
