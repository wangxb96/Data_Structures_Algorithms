//串的基本运算 
#include<stdio.h>
#define MAXSIZE 50
int StrLength(char *s)
{
	int i=0;
	while(s[i]!='\0')
	   i++;
	return i;
 } 
 
int StrCat(char s1[],char s2[])
{
	int i,j,len1,len2;
	len1=StrLength(s1);
	len2=StrLength(s2);
	if(len1+len2>MAXSIZE-1)
	   return 0;
	i=0;j=0;
	while(s1[i]!='\0')
	  i++;
	while(s2[j]!='\0')
	  s1[i++]=s2[j++];
	s1[i]='\0';
	return 1;
}

int SubStr(char *s,char t[],int i,int len)
{
	int j,slen;
	slen=StrLength(s);
	if(i<1||i>slen||len<0||len>slen-i+1)
	   return 0;
	for(j=0;j<len;j++)
	   t[j]=s[i+j-1];
	t[j]='\0';
	return 1;
}

int StrCmp(char *s1,char *s2)
{
	int i=0;
	while(s1[i]==s2[i]&&s1[i]!='\0')
	   i++;
	return (s1[i]-s2[i]);
}

int StrInsert(char *s,int i,char *t)
{
	char str[MAXSIZE];
	int j,k,len1,len2;
	len1=StrLength(s);
	len2=StrLength(t);
	if(i<0||i>len1+1||len2>MAXSIZE-1)
	   return 0;
	k=i;
	for(j=0;s[k]!='\0';j++)
	  str[i]=s[k++];
	str[j]='\0';
	j=0;
	while(t[j]!='\0')
	  s[i++]=t[j++];
	j=0;
	while(str[j]!='\0')
	  s[i++]=str[j++];
	s[i]='\0';
	return 1;
}

int main()
{
	char x1[50]="abcdefghijk",x2[30]="mnopqrstuvwxyz",x3[20];
	puts(x1);
	printf("Length of string x1 is %d\n",StrLength(x1));
	if(StrCat(x1,x2))
	{
		printf("Output x1 after chain:\n");
		puts(x1);
	}
	else
	  printf("Chain x1 and x2 fail!\n");
	if(SubStr(x1,x3,5,12))
	{
		printf("String:\n");
		puts(x3);
	}
	else
	   printf("Error!\n");
	if(StrCmp(x1,x2)>0)
	   printf("x1 is larger!\n");
	else
	   if(StrCmp(x1,x2)==0)
	      printf("Equal!\n");
	    else
	      printf("x2 is larger!\n");
	if(StrInsert(x2,5,"aaaaa"))
	{
		printf("Output x2 after insert:\n");
		puts(x2);
	}
	else
	   printf("Insert fail!\n");
	return 0;
}
