//折半插入排序
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;
void B_InsertSort(RecordType R[],int n)
{//对n个记录序列R[1]~R[n]进行折半插入排序 
	int i,j,low,high,mid;
	for(i=2;i<=n;i++)//进行n-1趟排序
	{
		R[0]=R[i];  //设置查找监视哨并保存待插入记录R[i]值
		low=1,high=i-1; //设置初始查找区间
		while(low<=high)
		{
			mid=(low+high)/2;
			if(R[0].key>R[mid].key)
			  low=mid+1;
			else
			  high=mid-1;  
		}
		for(j=i-1;j>=high+1;j--)//high+1为插入位置，将R[i-1],R[i-2],...,R[high+1]顺序后移一个位置
		  R[j+1]=R[j];
		R[high+1]=R[0];  //将R[i](现为R[0]放入应插入的位置high+1)   
	 } 
 } 

int main()
{
	int i=1,j,x;
	RecordType R[MAXSIZE];
	printf("Input data of list(-1 stop):\n");  //给每一个记录输入关键字直至-1结束 
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
	B_InsertSort(R,i-1); //进行折半插入排序
	for(j=1;j<i;j++)
	  printf("%4d",R[j].key);
	printf("\n");
	return 0;     
}
