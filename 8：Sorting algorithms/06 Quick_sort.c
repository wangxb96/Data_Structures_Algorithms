//快速排序
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;
int Partition(RecordType R[],int i,int j)
{//对R[i]~R[j]，以R[i]为基准记录进行划分，并返回R[i]在划分后的正确位置 
	R[0]=R[i];   //暂存基准记录
	while(i<j)
	{
		while(i<j&&R[j].key>=R[0].key)
		    j--;
		if(i<j)
		{
		  R[i]=R[j];
		  i++;	
		}
		while(i<j&&R[i].key<=R[0].key)
		    i++;
		if(i<j)
		{
			R[j]=R[i];
			j--;
		}	    
	 }
	R[i]=R[0];   //将基准记录R[0]送入最终(指排好序时)应放置的位置
	return i;   //返回基准记录R[0]最终放置的位置  
 }

void QuickSort(RecordType R[],int s,int t)
{
	int i;
	if(s<t)
	{
		i=Partition(R,s,t); //i为基准记录的位置并由此将表分为R[s]~R[i-1]和R[i+1]~R[t]两部分
		QuickSort(R,s,i-1);
		QuickSort(R,i+1,t); 		
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
  QuickSort(R,1,i-1);
  printf("\nOutput data in list after Sort:\n");
  for(j=1;j<i;j++)
    printf("%4d",R[j].key);
  printf("\n");
  return 0;			
}  
