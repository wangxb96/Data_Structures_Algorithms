//选择排序
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;

void SelectSort(RecordType R[],int n)
{
	int i,j,k;
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)//从第i个记录开始的n-i+1个无序记录中选出关键字最小的记录
		   if(R[j].key<R[k].key)
		      k=j;        //记录关键字最小的记录其存放位置
		if(i!=k)
		{
		   R[0]=R[k];
		   R[k]=R[i];
		   R[i]=R[0];	
		}	   
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
	   printf("%4d",R[i].key);
	printf("\nSort:\n");
	SelectSort(R,i-1);
	printf("\nOutput data in list after Sort:\n");
	for(j=1;j<i;j++)
	   printf("%4d",R[j].key);
	printf("\n");
	return 0;      
 } 
