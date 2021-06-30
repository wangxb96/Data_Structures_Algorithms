//有顺序表A和B，其表中元素均由小到大的顺序排列。编写一个算法将它们合并成一个顺序表C，
//并且要求表C中的元素也按由小到大的顺序排列 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef  struct{
	int data[MAXSIZE];
	int len;
}SeqList;

SeqList *Init_SeqList()
{
	SeqList *L;
	L=(SeqList*)malloc(sizeof(SeqList));
	L->len=0;
	return L;
}

void CreatList(SeqList **L)
{
	int i,n;
	printf("Input length of List:\n");
	scanf("%d",&n);
	printf("Input elements of List:\n");
	for(i=1;i<=n;i++)
	   scanf("%d",&(*L)->data[i]);
	(*L)->len=n;
}

void Merge(SeqList *A,SeqList *B,SeqList **C)
{//将两个升序的顺序表A和B合并为一个升序的顺序表C
    int i=1,j=1,k=1;
	if(A->len+B->len>=MAXSIZE)
	   printf("ERROR!\n");
	else
	{
		*C=(SeqList*)malloc(sizeof(SeqList));
		while(i<=A->len&&j<=B->len)
		  if(A->data[i]<B->data[j])
		    (*C)->data[k++]=A->data[i++];
		  else
		    (*C)->data[k++]=B->data[j++];
		while(i<=A->len)
		    (*C)->data[k++]=A->data[i++];
		while(j<=B->len)
		    (*C)->data[k++]=B->data[j++];
		(*C)->len=k-1;
	 } 
}

void print(SeqList *L)
{
	int i;
	for(i=1;i<=L->len;i++)
	   printf("%4d",L->data[i]);
	printf("\n");
}

int main()
{
	SeqList *A,*B,*C;
	A=Init_SeqList();
	printf("Creat List A:\n");
	CreatList(&A);
	printf("Output list A:\n");
	print(A);
	B=Init_SeqList();
	printf("Creat List B:\n");
	CreatList(&B);
	printf("Output list B:\n");
	print(B);
    C=Init_SeqList();
    printf("Merge list A and B TO C:\n");
    Merge(A,B,&C);
    printf("Output list C:\n");
    print(C);
    return 0;
}
