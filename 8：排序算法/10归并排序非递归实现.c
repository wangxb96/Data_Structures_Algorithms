//归并排序非递归实现
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;

void Merge(RecordType R[],RecordType R1[],int k,int n)
{//R1为归并中使用的暂存数组 
	int i,j,l1,u1,l2,u2,m;//l1、l2和u1、u2分别为进行归并的两个有序子表的上、下界
	l1=0;  //初始时l1为第一个有序子表的下界值0 
    m=0;  //m为数组R1的存放指针 
	while(l1+k<n) //归并中的两个子表其第一个子表长度为k时 
	{
	  l2=l1+k;  //l2指向归并中第二个子表的开始处
	  u1=l2-1;  //u1指向归并中第一个子表的末端(与第二个子表相邻)
	  if(l2+k-1<n)
	    u2=l2+k-1; //u2指向归并中第二个子表的末端
      else 
	    u2=n-1; //归并中第二个子表为最后一个子表且长度小于k
      for(i=l1,j=l2;i<=u1&&j<=u2;m++)//两有序子表归并为一个有序子表且暂存于R1 
	     if(R[i].key<=R[j].key)
		    R1[m]=R[i++];
	     else
		    R1[m]=R[j++];
	  while(i<=u1) //第二个子表已归并完，将第一个子表的剩余记录复制到R1
	     R1[m++]=R[j++];
	  while(j<=u2) //第一个子表已归并完，将第二个子表的剩余记录复制到R1
	     R1[m++]=R[j++];
	  l1=u2+1;    //将l1调整到下两个未归并子表的开始处继续进行归并	 	 									
	} 	
 } 

void MergeSort(RecordType R[],int n)
{//将无序表R[s]~R[t]归并为一个有序表R1[s]~R1[t]
    int i,k;
	RecordType R1[MAXSIZE];
	k=1;   //初始时待归并的有序子表长度均为1
	while(k<n)  //整个表未归并为一个有序表时(子表长度k小于n)继续归并 
	{
		Merge(R,R1,k,n);  //对所有子表进行一趟二路归并
		for(i=0;i<n;i++)  //将暂存于R1的一趟归并结果复制到R中 
		  R[i]=R1[i]; 
		k=2*k;  //一趟归并后有序子表长度是原子表长度的2倍 
	} 
 }

int main()
{
	int i=1,j,x;
	RecordType R[MAXSIZE];
	printf("Input data of list （-1 stop):\n");
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
	MergeSort(R,i-1);
	printf("\nOutput data in list after Sort:\n");  //输出归并排序后的结果
	for(j=1;j<i;j++)
	  printf("%4d",R[j].key);
	printf("\n");
	return 0;     
 } 
  
