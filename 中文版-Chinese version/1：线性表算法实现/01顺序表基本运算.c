//顺序表基本运算 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct{
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
 	printf("Input length of list:\n");
 	scanf("%d",&n);
 	printf("Input elements of list:\n");
 	for(i=1;i<=n;i++)
 	scanf("%d",&(*L)->data[i]);
    (*L)->len=n;
    return 0;
 }

void Insert_SeqList(SeqList *L,int i,int x)
{
	int j;
	if(L->len==MAXSIZE-1)
	  printf("The list is full!\n");
	else
	  if(i<1||i>L->len+1)
	     printf("The position is invalid!\n");
	  else
	  {
	  	for(j=L->len;j>=i;j--)
	  	   L->data[j+1]=L->data[j];
	  	L->data[i]=x;
	  	L->len++;
	  }
}

void Delete_SeqList(SeqList *L,int i)
{
	int j;
	if(L->len==0)
	  printf("The list is empty!\n");
	else
	  if(i<1||i>L->len)
	     printf("The position is invalid!\n");
	  else
	  {
	  	for(j=i+1;j<=L->len;j++)
	  	  L->data[j-1]=L->data[j];
	  	L->len--;
	  }
}

int Location_SeqList(SeqList *L,int x)
{
	int i=1;
	while(i<L->len&&L->data[i]!=x)
	  i++;
	if(L->data[i]==x)
	  return i;
	else
	  return 0;
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
	SeqList *s;
	int i,x;
	s=Init_SeqList();
	printf("Creat List:\n");
	CreatList(&s);
	printf("Output list:\n");
	print(s);
	printf("Input element and size of insert:\n");
	scanf("%d %d",&x,&i);
	Insert_SeqList(s,i,x);
	printf("Output lis:\n");
	print(s);
	printf("Input element site of delete:\n");
	scanf("%d",&i);
	Delete_SeqList(s,i);
	printf("Output list:\n");
	print(s);
	printf("Input element value of location:\n");
	scanf("%d",&x);
	i=Location_SeqList(s,x);
	printf("element %d site is %d\n",x,i);
	return 0;
}
