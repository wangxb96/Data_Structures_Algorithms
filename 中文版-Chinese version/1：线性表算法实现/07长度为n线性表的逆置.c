//已知线性表A长度为n，试写出将该线性表逆置的算法 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct 
{
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

void Coverts(SeqList *A)
{
	int i,n;
	int x;
	n=A->len;
	for(i=1;i<=n/2;i++)
	{
		x=A->data[i];
		A->data[i]=A->data[n-i+1];
		A->data[n-i+1]=x;
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
	SeqList *A;
	A=Init_SeqList();
	printf("Creat List A:\n");
	CreatList(&A);
	printf("Output list A:\n");
	print(A);
	printf("Covert list A:\n");
	Coverts(A);
	printf("Output list A:\n");
	print(A);
	return 0;
}
 
