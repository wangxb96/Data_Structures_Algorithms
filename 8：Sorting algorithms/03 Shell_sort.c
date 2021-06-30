//希尔(Shell)排序
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;
void ShellInsert(RecordType R[],int n,int d)
{//对R[1]~R[n]中的记录进行希尔排序，d为增量(步长)因子
   int i,j;
   for(i=d+1;i<=n;i++)
     if(R[i].key<R[i-d].key)
	 {//当R[i].key小于前一步长d的R[i-d].key应向前找寻其插入位置 
	 	R[0]=R[i];  //暂存待插入记录R[i]的值
		for(j=i-d;j>0&&R[0].key<R[j].key;j=j-d)
		  R[j+d]=R[j];
		  /*将位于R[i]之前下标差值为增量步长的倍数且关键字大于R[0].key(即原R[i].key)的所有 R[j]都顺序后移一个增量步长位置*/
		R[j+d]=R[0];   
	  } 
 } 

void ShellSort(RecordType R[],int n)
{//按递增序列d[0]、d[1]、...、d[t-1]对顺序表R[1]~R[n]做希尔排序
   int d[10],t,k;
   printf("\n输入增量因子的个数：\n");
   scanf("%d",&t);
   printf("由大到小输入每一个增量因子：\n");
   for(k=0;k<t;k++)
      scanf("%d",&d[k]);  //由大到小输入每一个增量因子
   for(k=0;k<t;k++)
     ShellInsert(R,n,d[k]); //按增量因子d[k]对顺序表R进行一趟希尔排序	   
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
	ShellSort(R,i-1);
	printf("\nOutput data in list after Sort:\n");
	for(j=1;j<i;j++)
	  printf("%4d",R[j].key);
	printf("\n");
	return 0;     
 } 
