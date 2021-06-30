//分块查找
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}SeqList;
typedef  struct{
	int key; //用于存放块内的最大关键字 
	int link; //用于指向块的起始位置 
}IndexType;

int IndexSearch(IndexType I[],int m,SeqList R[],int k)
{//索引表I长度为m
   int low=0,high=m-1,mid,i,j;
   while(low<=high)
   {
   	mid=(low+high)/2;
   	if(I[mid].key>=k)
   	   high=mid-1;
   	else
   	   low=mid+1;
	} 
	if(low<m)//在索引表中找到所求的块，接下来在顺序表(即数组R)中顺序查找
	{
		i=I[low+1].link-1;
		j=I[low].link;
		while(R[i].key!=k&&i>=j)
		  i--;
		if(i>=j)
		  return i;
	 } 
	return -1;
 } 
 
int main()
{
	int i;
	IndexType I[4]={18,0,38,4,71,9,90,11};
	SeqList R[16]={18,' ',6,' ',10,' ',11,' ',21,' ',31,' ',20,' ',38,' ',19,' ',60,' ',71,' ',75,' ',88,' ',73,' ',79,' ',90,' '};
	i=IndexSearch(I,4,R,38);
	if(i>-1)
	   printf("Site of 38 is %d\n",i);
	else
	   printf("Not find 38!\n");
	i=IndexSearch(I,4,R,26);
	if(i>-1)
	   printf("Site of 26 is %d\n",i);
	else
	   printf("Not find 26!\n");
	return 0; 
 } 
