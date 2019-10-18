#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct{
	char data;
	int cursor;
}SNode;

void InsertList(SNode L[],int i,char x)
{
	int j,j1,j2,k;
	j=L[0].cursor;
	if(i==1)
	{
		if(j==0)
		{
		  L[1].data=x;
		  L[0].cursor=1;
		  L[1].cursor=0;	
		}
	else
	{
		k=j+1;
		while(k!=j)
		  if(L[k].cursor==-1)
		     break;
		  else
		    k=(k+1)%MAXSIZE;
		if(k!=j)
		{
			L[k].data=x;
			L[k].cursor=L[0].cursor;
			L[0].cursor=k;
		}
		else
		  printf("List overflow!\n");
	}
   }
else
{
	k=0;
	while(k<i-2&&j!=0)
	{
		k++;
		j=L[j].cursor;
	}
	if(j==0)
	  printf("Insert error!\n");
	else
    {
    	j1=j;
    	j2=L[j].cursor;
    	k=j+1;
    	while(k!=i)
    	  if(L[k].cursor==-1)
    	    break;
    	  else
    	    k=(k+1)%MAXSIZE;
    	if(k!=j)
    	{
    		L[k].data=x;
    		L[j1].cursor=k;
    		L[k].cursor=j2;
		}
		else
		   printf("List overflow!\n");
	}
}
}

void print(SNode *L)
{
	int i;
	i=L[0].cursor;
	while(i!=0)
	{
		printf("%c,",L[i].data);
		i=L[i].cursor;
	}
	printf("\n");
}

int main()
{
	SNode L[MAXSIZE];
	int i;
	char x;
	for(i=1;i<MAXSIZE;i++)
	   L[i].cursor=-1;
	L[0].cursor=0;
	i=1;
	printf("Input elements of list:\n");
	scanf("%c",&x);
	while(x!='\n')
	{
		InsertList(L,i,x);
		i++;
		scanf("%c",&x);
	}
	printf("Input site and element of insert:\n");
	scanf("%d,%c",&i,&x);
	InsertList(L,i,x);
	printf("Output list:\n");
	print(L);
	return 0;
}

