//基数排序
#include<stdio.h>
#define MAXSIZE 30
#define Radix_MAX 10
#define d_MAX 3
typedef struct{
	int key;
	int keys[d_MAX]; //存放拆分后的各关键字项，d_MAX为关键字项的最长度值 
	int next;
	char data;
}RecType;

void RadixSort(RecType R[],int d,int c1,int ct)
{//对R[1]~R[n]进行基数排序，d为关键字项数，c1~ct为基数(即权值)的范围
    int i,j,k,m,p,t,f[Radix_MAX],e[Radix_MAX];
	p=1;
	for(i=0;i<d;i++) //进行d趟分配与收集 
	{
		for(j=c1;j<=ct;j++) //分配前清空队头指针 
		   f[j]=0;
		while(p!=0)//未分配到最后一个记录R[n]，其标记为R[n].next等于0 
		{
			k=R[p].keys[i];  //k为R[p]中第i项关键字值 
			if(f[k]==0)  //第k个队列是否为空 
			  f[k]=p;    //R[p]作为第k个队列的队头结点插入 
			else
			  R[e[k]].next=p;  //将R[p]链到第k个队列的队尾结点
			e[k]=p;  //第k个队列的队尾指针e[k]指向新的队尾结点
			p=R[p].next;  //取出排在R[p]之后的记录继续分配   
		}
		j=c1; //收集c1~ct个队列上的记录
		while(f[j]==0) //j队列为空时继续查找下一个非空队列
		  j++;
		p=f[j];
		t=e[j]; //找到第一个非空队列使p指向队头，t指向队尾
		while(j<ct) //未收集完最后一个队列时则继续收集
		{
			j++;
			if(f[j]!=0)//后应该队列不为空时
			{
				R[t].next=f[j];  //将后一个队列的队头链到前一个队列的队尾
				t=e[j];  //使t指向这后一个队列的队尾继续进行对下一个队列的收集 
			 } 
			R[t].next=0;  //收集完毕置最后一个记录R[t]为收集队列的队尾标志 
		 } 
		m=p;   //m指向链队列的队头
		printf("%5d",R[m].key);
		do
		{
			m=R[m].next;
			printf("%5d",R[m].key);
		 }while(R[m].next!=0);
		printf("\n");    
	 } 
 } 

void DistKeys(RecType R[],int n,int d,int c1,int ct)
{//将单关键字分离为多关键字的基数排序 
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		R[i].next=i+1;  //将记录R[1]~R[n]先链成一个链队列
		k=R[i].key; //取出R[i]的单关键字
		for(j=0;j<d;j++)
		{
			R[i].keys[j]=k%(ct+1); //将R[i]的单关键字key分离为多关键字存于R[i].keys[0]~R[i].keys[d]
			k=k/(ct+1); 
		 } 
	}
	R[n].next=0;  //置最后一个记录R[n]的队尾标志
	RadixSort(R,d,c1,ct); 
 } 
 
 int main()
 {
 	int i=1,j,x;
 	RecType R[MAXSIZE];
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
	printf("\nSort, Output data in list after Sort:\n");
	DistKeys(R,i-1,d_MAX,0,9);  //进行基数排序
	return 0;    
 }
