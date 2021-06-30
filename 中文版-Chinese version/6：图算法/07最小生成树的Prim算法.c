//最小生成树的Prim算法
#include<stdio.h>
#define MAXNODE 30
#define MAXCOST 32767
void Prim(int gm[][6],int closevertex[],int n)
{//从存储序号为0的顶点出发建立连通网的最小生成树，gm是邻接矩阵，n为顶点个数（即有0~n-1个顶点）
//最终建立的最小生成树存于数组closevertex中 
	int lowcost[MAXNODE];
	int i,j,k,mincost;
	for(i=1;i<n;i++)
	{
		lowcost[i]=gm[0][i];  //边(u0,u1)的权值送lowcost[i]
		closevertex[i]=0;  //假定顶点ui到顶点u0有一条边 
	}
	lowcost[0]=0;//从序号为0的顶点u0出发生成最小生成树，此时u0已经进入U集 
	closevertex[0]=0;
	for(i=1;i<n;i++)//在n个顶点中生成有n-1条边的最小生成树(共n-1躺） 
	{
		mincost=MAXCOST;
		j=1;k=0;
		while(j<n)
		{
			if(lowcost[j]!=0&&lowcost[j]<mincost)
			{
				mincost=lowcost[j];
				k=j;//记下最小权值边在V-U集中的顶点序号j 
			}
			j++; 
		 } 
		printf("Edge:(%d,%d),Weight:%d\n",k,closevertex[k],mincost);
		lowcost[k]=0;
		for(j=1;j<n;j++)
		  if(lowcost[j]!=0&&gm[k][j]<lowcost[j])
		  {//若顶点k进入U集后使顶点k和另一顶点j(在V-U集中)构成的边权值变小则改变lowcost[j]为这个小值，
		   //并将此最小权值的边(j,k)记入closevertex数组
		   lowcost[j]=gm[k][j];
		   closevertex[j]=k; 
		  }
	 } 
 } 

int main()
{
	int closevertex[MAXNODE];
	int g[6][6]={{100,6,1,5,100,100},{6,100,5,100,3,100},{1,5,100,5,6,4},{5,100,5,100,100,2},{100,3,6,100,100,6},{100,100,4,2,6,100}};
	Prim(g,closevertex,6);
	return 0;
}
