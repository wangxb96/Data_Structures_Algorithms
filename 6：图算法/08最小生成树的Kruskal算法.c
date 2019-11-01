//最小生成树的Kruskal算法
#include<stdio.h>
#define MAXSIZE 30
#define MAXCOST 32767
typedef struct{
	int u;
	int v;
	int w;
}Edge;

void Bubblesort(Edge R[],int e)
{//对数组R中的ｅ条边按权值递增排序
    Edge temp;
    int i,j,swap;
	for(i=0;i<e-1;j++)
	{
		swap=0;
		for(j=0;j<e-i-1;j++)
		   if(R[j].w>R[j+1].w)
		   {
		   	temp=R[j];
		   	R[j]=R[j+1];
		   	R[j+1]=temp;
		   	swap=1;
		   }
		   if(swap==0)break;//本趟比较中未出现交换则结束排序（已排好） 
	 } 
 } 

void Kruskal(int gm[][6],int n)
{//在顶点为n的连通图中构造最小生成树，gm为连通网的邻接矩阵
  int i,j,u1,v1,sn1,sn2,k;
  int vest[MAXSIZE];
  Edge E[MAXSIZE];
  k=0;
  for(i=0;i<n;i++)  //用数组E存储连通网中每条边的两个顶点及边上的权值信息 
    for(j=0;j<n;j++) 
      if(i<j&&gm[i][j]!=MAXCOST)
	  {
	  	E[k].u=i;
	  	E[k].v=j;
	  	E[k].w=gm[i][j];
	  	k++;
	   } 
	Bubblesort(E,k);//采用冒泡排序对数组E中的k条边按权值递增排序 
	for(i=0;i<n;i++)
	   vest[i]=i;  //给每个顶点置不同连通分量编号，即初始时有n个连通分量
	k=1;    //k表示当前构造生成树的第n条边，初值为1 
	j=0;    //数组E中元素的下标，初值为0
	while(k<n)
	{
		u1=E[j].u;
		v1=E[j].v;
		sn1=vest[u1];
		sn2=vest[v1];
		if(sn1!=sn2)//两顶点 分属不同集合（连通分量）则该边为最小生成树的一条边
		{
			printf("Edge:(%d,%d),Weight:%d\n",u1,v1,E[j].w);
			k++;
			for(i=0;i<n;i++)
			  if(vest[i]==sn2)//集合编号为sn2的第i号边其编号该为sn1 
			    vest[i]=sn1; 
		 } 
		j++; //扫描下一条边 
	 } 
 } 

int main()
{
	int g[6][6]={{100,6,1,5,100,100},{6,100,5,100,3,100},{1,5,100,5,6,4},{5,100,5,100,100,2},{100,3,6,100,100,6},{100,100,4,2,6,100}};
	Kruskal(g,6);
	return 0;
}
