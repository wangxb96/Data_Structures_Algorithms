//冒泡排序
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;

void BubbleSort(RecordType R[],int n)
{//对R[1]~R[n]这n个记录进行冒泡排序
  int i,j,swap;
  for(i=1;i<n;i++)
  {
  	swap=0;
  	for(j=1;j<=n-i;j++) //对R[1]~R[n-i]记录进行两两比较
	  if(R[j].key>R[j+1].key)
	  {
	  	R[0]=R[j];
	  	R[j]=R[j+1];
	  	R[j+1]=R[0];
	  	swap=1; //有交换发生 
	   } 
  	if(swap==0)
	   break;     //本趟比较中未出现交换则结束排序(已排好) 
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
	BubbleSort(R,i-1);
	printf("\nOutput data in list after Sort:\n");
	for(j=1;j<i;j++)
	  printf("%4d",R[j].key);
	printf("\n");
	return 0;    
 } 
