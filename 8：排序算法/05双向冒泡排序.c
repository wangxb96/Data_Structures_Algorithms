//双向冒泡排序
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;
void DBubbleSort(RecordType R[],int n)
{
	int i,j,swap=1;
	for(i=1;swap!=0;i++)
	{
		swap=0;
		for(j=n-i;j>=i;j--)  //从右到左进行冒泡排序 
		  if(R[j+1].key<R[j].key) 
		  {
		  	R[0]=R[j];
		  	R[j]=R[j+1];
		  	R[j+1]=R[0];
		  }
		for(j=i+1;i<=n-i;j++)  //从左到右 
		{
			R[0]=R[j];
			R[j]=R[j+1];
			R[j+1]=R[0];
			swap=1;
		}  
	}
 } 
 
int main()
{
	int i=1,j,x;
	RecordType R[MAXSIZE];
	printf("Input data of list(-1 top):\n"); //给每一记录输入关键字直至-1结束
	scanf("%d",&x);
	while(x!=-1)
	{
		R[i].key=x;
		scanf("%d",&x);
		i++;
	 } 
	printf("Output data in list after sort:\n");
	for(j=1;j<i;j++)
	  printf("%4d",R[j].key);
	printf("\n");
	return 0;   
 } 
