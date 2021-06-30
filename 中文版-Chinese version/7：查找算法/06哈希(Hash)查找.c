//哈希(Hash)查找
#include<stdio.h>
#define MAXSIZE 11
#define key 11   //哈希查找采用除留取余法(x%key) 
void Hash_Insert(int Hash[],int x)
{
	int i=0,t;
	t=x%key;
	while(i<MAXSIZE)
	{
		if(Hash[t]<=-1)//找到存放位置
		{
			Hash[t]=x;
			break;
		 } 
		else
		  t=(t+1)%key;
		i++;
	 } 
	if(i==MAXSIZE)
	  printf("Hashlist is full!\n");
}

void Hash_search(int Hash[],int x)
{
	int i=0,t;
	t=x%key;
	while(Hash[t]!=-1&&i<MAXSIZE)
	{
		if(Hash[t]==x)
		{
			printf("Hash position of %d is %d\n",x,t);//找到则输出该关键字及其存放位置
			break; 
		}
		else
		  t=(t+1)%key;  //用开放定址法确定下一个要查找的位置 
		i++;
	}
	if(Hash[t]==-1||i==MAXSIZE) //查到空位置标记-1或已到表的最大值
	  printf("No found!\n"); 
}

void Hash_Delete(int Hash[],int x)//哈希表的删除
{
	int i=0,t;
	t=x%key;
	while(Hash[t]!=-1&&i<MAXSIZE)  //当查找的位置标记不为-1或未到表的最大值
	{
		if(Hash[t]==x)
		{
			Hash[t]=-2;
			printf("%d in Hashlist is deleted!\n",x);
			break;
		}
		else
		  t=(t+1)%key;
		i++;
	 }
	 if(i==MAXSIZE)
	    printf("Delete fail!\n"); 
 } 

int main()
{
	int i,x,Hash[MAXSIZE];
	for(i=0;i<MAXSIZE-1;i++)
	   Hash[i]=-1;
	i=0;
	printf("Make Hashlist,Input data(-1 stop):\n");
	scanf("%d",&x);
	while(x!=-1&&i<MAXSIZE)
	{
		Hash_Insert(Hash,x);
		scanf("%d",&x);
	}
	printf("Output Hashlist:\n");
	for(i=0;i<MAXSIZE;i++)
	  printf("%4d",Hash[i]);
	printf("\nInput search data:\n");
	scanf("%d",&x);
	Hash_search(Hash,x);
	printf("\nDelete record in Hashlist,Input key:\n");
	scanf("%d",&x);
	Hash_Delete(Hash,x);
	printf("Output Hashlist after record deleted:\n");
	for(i=0;i<MAXSIZE;i++)
	  printf("%4d",Hash[i]);
	printf("\nInsert key of record in Hashlist:\n");
	scanf("%d",&x);
	Hash_Insert(Hash,x);
	printf("Output Hashlist after record inserted:\n");
	for(i=0;i<MAXSIZE;i++)
	  printf("%4d",Hash[i]);
	printf("\n");
	return 0;
}
