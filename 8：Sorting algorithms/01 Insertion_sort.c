//插入排序
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;
void D_Insert(RecordType R[],int n)
{//对n个记录序列R[1]~R[n]进行直接插入排序 
   	int i,j;
   	for(i=2;i<=n;i++)//进行n-1趟排序 
   	   if(R[i].key<R[i-1].key)
   	   {//R[i].key小于R[i-1].key时需将R[i]插入到有序序列R[1]~R[i-1]中 
   	   	  R[0]=R[i];   //设置查找监视哨并保存待插入记录R[i]值
		  j=i-1;		 
		  while(R[j].key>R[0].key)
		  {//将关键字值大于R[i].key(即此时的R[0].key)的所有R[j](j=i-1,i-2,...)顺序后移一个记录位置 
		  	R[j+1]=R[j];
		  	j--;
		  }		
		  R[j=1]=R[0];   //将R[i](也即此时的R[0]）插入应插到的位置上 
		}
} 

int main()
{
	int i=1,j,x;
	RecordType R[MAXSIZE];
	printf("Input data of list(-1 stop):\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		R[i].key=x;
		scanf("%d",&x);
		i++;
	}
	printf("Output data in list:\n");
	for(j=1;j<i;j++)
	   printf("%4d",R[j].key);
	printf("\nSort:\n");
	D_Insert(R,i-1);  //进行直接插入排序
	printf("\nOutput data in list after Sort:\n");
	for(j=1;j<i;j++)
	   printf("%4d",R[j].key);
	printf("\n");
	return 0;    
}

