//哈夫曼树及哈夫曼编码 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 40
#define MAXBIT 10
typedef struct{
	int weight,parent,lchild,rchild;
}HNode;
typedef struct{
	int weight;
	int bit[MAXBIT];
	int start;
}HCode;

void HuffTree(HNode Huff[],int n)
{
	int i,j,m1,m2,x1,x2;
	for(i=0;i<2*n-1;i++)
	{
		Huff[i].weight=0;
		Huff[i].parent=-1;
		Huff[i].lchild=-1;
		Huff[i].rchild=-1; 
	}
	printf("Input 1~n value of leaf:\n");
	for(i=0;i<n;i++)
	  scanf("%d",&Huff[i].weight);
	for(i=0;i<n-1;i++)
	{
		m1=m2=32767;
		x1=x2=0;
		for(j=0;j<n+i;j++)
		{
			if(Huff[j].parent==-1&&Huff[j].weight<m1)
			{
				m2=m1;
				x2=x1;
				m1=Huff[j].weight;
				x1=j;
			}
			else
			  if(Huff[j].parent==-1&&Huff[j].weight<m2)
			  {
			  	m2=Huff[j].weight;
			  	x2=j;
			  }
		}
	//将找出的两棵子树合并为一棵新的子树
	Huff[x1].parent=n+i;//两棵子树根结点的双亲结点序号为n+i 
	Huff[x2].parent=n+i;
	Huff[n+i].weight=Huff[x1].weight+Huff[x2].weight;//新子树根结点的权值为两棵子树根结点权值之和 
	Huff[n+i].lchild=x1;
	Huff[n+i].rchild=x2; 
	}
	printf("Huff weight  lchild   rchild   prent\n");
	for(i=0;i<2*n-1;i++)
	   printf("%3d  %5d  %10d  %10d   %10d\n",i,Huff[i].weight,Huff[i].lchild,Huff[i].rchild,Huff[i].parent);
}

void HuffmanCode()
{
	HNode HuffNode[MAXSIZE];//MAXSIZE为二叉树所有结点的最大个数 
	HCode HuffCode[MAXSIZE/2],cd;//MAXSIZE/2为叶结点的最大个数 
	int i,j,c,p,n;
	printf("Input numbers of leaf:\n");//n为叶结点个数 
	scanf("%d",&n);
	HuffTree(HuffNode,n);
	for(i=0;i<n;i++)//求每个叶结点的哈夫曼编码 
	{
		HuffCode[i].weight=HuffNode[i].weight;//保存叶结点权值 
		cd.start=MAXBIT-1;//存放分支编码从数组cd.bit最后一个元素位置开始向前进行 
		c=i;//c为叶结点在数组HuffNod中的序号 
		p=HuffNode[c].parent;
		while(p!=-1) //从叶结点开始沿双亲链直到根结点，根结点的双亲值为-1
		{
			if(HuffNode[p].lchild==c)//双亲的左孩子序号为c
			  cd.bit[cd.start]=0;//该分支编码为0
			else
			  cd.bit[cd.start]=1;//该分支编码为1
			cd.start--;//前移一个位置准备存放下一个分支编码 
			c=p;//c移至其双亲结点序号 
			p=HuffNode[c].parent; //p再定位于c的双亲结点序号 
		 } 
		for(j=cd.start+1;j<MAXBIT;j++) //保存该叶结点字符的哈夫曼编码 
		   HuffCode[i].bit[j]=cd.bit[j];
		HuffCode[i].start=cd.start;//保存该编码在数组bit中的起始位置
	}
	printf("HuffCode weight   bit\n");
	for(i=0;i<n;i++)
	{
		printf("%5d %8d     ",i,HuffCode[i].weight);
		for(j=HuffCode[i].start+1;j<MAXBIT;j++)
		   printf("%d",HuffCode[i].bit[j]);
		printf("\n");
	 } 
}

int main()
{
	HuffmanCode();
}
