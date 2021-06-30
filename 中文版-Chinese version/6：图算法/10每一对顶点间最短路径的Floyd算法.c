//每一对顶点间最短路径的Floyd算法
#include<stdio.h>
#define MAXSIZE 6
#define INF 32767
void Ppath(int path[][MAXSIZE],int i,int j)
{//前向递归查找路径上的顶点，MAXSIZE为常数
   int k;
   k=path[i][j];
   if(k!=-1)  //顶点vk不是起点 
   {
   	Ppath(path,i,k);
   	printf("%d,",k);  
   	Ppath(path,k,j);
	} 
 } 
 
void Dispath(int A[][MAXSIZE],int path[][MAXSIZE],int n)//输出最短路径
{
	int i,j;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    if(A[i][j]==INF)
	    {
	    	if(i!=j)
	    	  printf("从%d到%d没有路径！\n",i,j);
	    	else
	    	{
	    		printf("从%d到%d的路径长度：%d，路径：",i,j,A[i][j]);
	    		printf("%d",i);   //输出路径上的起点序号i 
	    		Ppath(path,i,j); //输出路径上的各中间点序号 
	    		printf("%d\n",j); //输出路径上的终点序号j 
			}
		}
 } 
 
void Floyd(int gm[][MAXSIZE],int n) //Floyd算法
{
	int A[MAXSIZE][MAXSIZE],path[MAXSIZE][MAXSIZE];
	int i,j,k;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	  {
	  	A[i][j]=gm[i][j];  //A-1[i][j]置初值 
	  	path[i][j]=-1; //初始时表示没有中间顶点 
	   } 
	for(k=0;k<n;k++)  //按顶点编号k递增的次序查找当前顶点之间的最短路径长度 
	  for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	      if(A[i][j]>A[i][k]+A[k][j])
	      {
	      	A[i][j]=A[i][k]+A[k][j];//从vi到vj经过vk时路径长度更短
			path[i][j]=k;  //记录中间顶点vk的编号 
		  }
	Dispath(gm,path,n);
 } 
 
int main()
{
	int g[MAXSIZE][MAXSIZE]={{INF,20,15,INF,INF,INF},{2,INF,INF,INF,10,30},{INF,4,INF,INF,INF,10},
	                      {INF,INF,INF,INF,INF,INF},{INF,INF,INF,15,INF,INF},{INF,INF,INF,4,10,INF}};
	Floyd(g,MAXSIZE);  //求对每一对顶点之间的最短路径
	return 0; 
}
