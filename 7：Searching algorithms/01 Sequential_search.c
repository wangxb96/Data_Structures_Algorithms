//顺序查找
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}SeqList; 
int SeqSearch(SeqList R[],int n,int k)
{
	int i=n;
	R[0].key=k;  //R[0].key为查找不成功的监视哨
	while(R[i].key!=k)  //由表尾向表头方向查找
	  i--;
	return i; 
}

int main()
{
	int i=0,j,x;
	SeqList R[MAXSIZE];
	printf("Input data of list(-1 stop):\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		R[i].key=x;
		scanf("%d",&x);
		i++;
	}
	printf("Output data of list(-1 stop):\n");
	for(j=0;j<i;j++)
	   printf("%4d",R[j].key);
	printf("\nSearch data in SeqList,Input data(-1 stop)");
	scanf("%d",&x);
	while(x!=-1)
	{
		i=SeqSearch(R,i,x);
		if(i>0)
		   printf("Position of %d in Seqlist is %d\n",x,i+1);
		else
		   printf("No found %d in SeqList!\n",x);
		printf("\nSearch data in Seqlist,Input data(-1 stop):\n");
		scanf("%d",&x);
	}
	return 0;
}
