//堆排序
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;

void HeapAdjust(RecordType R[],int s,int t)
{//对R[s]~R[t]除R[s]外均满足堆的定义，即只对R[s]进行调整使R[s]为根的完全二叉树成为一个堆 
	int i,j;
	R[0]=R[s];
	i=s;
	for(j=2*i;j<=t;j=2*j) //沿关键字较大的孩子向下调整，先假定为左孩子 
	{
		if(j<t&&R[j].key<R[j+1].key)
		  j=j+1;         //右孩子结点的关键字大则沿右孩子向下调整 
		if(R[0].key>R[j].key)  //R[0](即R[s])的关键字已大于R[j]的关键字值，即已满足堆的定义，故不再向下调整 
		  break;
		R[i]=R[j];  //将关键字大的孩子结点R[j]调整至双亲结点R[i]
		i=j;  //定位于孩子结点继续向下调整   
	 } 
	R[i]=R[0];   //找到满足堆定义的R[0](即R[s])放置位置i，将R[s]调整于此 
 } 

void HeapSort(RecordType R[],int n)
{
    int i;
	for(i=n/2;i>0;i--) //将完全二叉树非终端结点按R[n/2],R[n/2-1],...,R[1]的顺序建立初始堆 
		HeapAdjust(R,i,n);
    for(i=n;i>1;i--)
	{
	  R[0]=R[1]; //堆顶的R[1]与堆底的R[i]交换 
	  R[1]=R[i];
	  R[i]=R[0];
	  HeapAdjust(R,1,i-1);  //将未排序的前i-1个结点重新调整为堆	
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
	HeapSort(R,i-1);
	printf("\nOutput data in list after Sort:\n"); 
	for(j=1;j<i;j++)
	  printf("%4d",R[j].key);
	printf("\n");
	return 0;     
}
