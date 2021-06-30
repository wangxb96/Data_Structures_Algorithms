//’€∞Î≤È’“
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}SeqList;

int BinSearch(SeqList R[],int n,int k)
{
	int low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(R[mid].key==k)
		   return mid;
		else
		  if(R[mid].key>k)
		     high=mid-1;
		  else
		     low=mid+1;
	}
	return -1;
 } 
 
int main()
{
	int i;
	SeqList R[MAXSIZE];
	for(i=1;i<=12;i++)
	  R[i].key=i*2;
	printf("Search 20 in SeqList:\n");
	i=BinSearch(R,12,20); 
	if(i!=-1)
	  printf("Position 0f 20 in Seqlist is %d\n",i);
	else
	  printf("No found 20 in SeqList!\n");
    printf("Search 21 Seqlist:\n");
    i=BinSearch(R,12,21);
    if(i!=-1)
      printf("Position of 21 in Seqlist is %d\n",i);
    else
      printf("No found 21 in Seqlist!\n");
    return 0;
}
