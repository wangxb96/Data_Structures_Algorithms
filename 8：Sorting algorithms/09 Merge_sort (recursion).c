//归并排序递归实现
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;

void Merge(RecordType R[],RecordType R1[],int s,int m,int t)
{//将有序表R[s]~R[m]及R[m+1]~R[t]合并为一个有序表R1[s]~R1[t] 
	int i,j,k;
	i=s;
	j=m+1;
	k=s;
	while(i<=m&&j<=t)
	//将两个有序表的记录按关键字大小收集到表R1中使表R1也为有序表
     if(R[i].key<=R[j].key)
	    R1[k++]=R[i++];
     else
	    R1[k++]=R[j++];
	while(i<=m)
	   R1[k++]=R[i++];
	while(j<=t)
	   R1[k++]=R[j++];   				 
}

void MSort(RecordType R[],RecordType R1[],int s,int t)
{//将无序表R[s]~R[t]归并为一个有序表R1[s]~R1[t] 
	int m;
	RecordType R2[MAXSIZE];
	if(s==t)
	   R1[s]=R[s];
	else
	{
		m=(s+t)/2;  //找到无序表R[s]~R[t]的中间位置 
		MSort(R,R2,s,m);
		MSort(R,R2,m+1,t);
		Merge(R2,R1,s,m,t);  //进行一趟将有序表R2[s]~R2[m]和R2[m+1]~R2[t]归并到有序表R1[s]~R1[t]的操作 
		}    
}

int main()
{
	int i=1,j,x;
	RecordType R[MAXSIZE],R1[MAXSIZE];
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
	MSort(R,R1,1,i-1);
	printf("\nOutput data in list after Sort:\n");
	for(j=1;j<i;j++)
	   printf("%4d",R[j].key);
	printf("\n");
	return 0;      
 } 
