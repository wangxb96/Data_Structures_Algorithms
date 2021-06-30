//串的简单模式匹配 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct{
	char data[MAXSIZE];
	int len;
}SeqString;

int StrIndex_BF(SeqString *S,SeqString *T)
{
	int i=0,j=0;
	while(i<S->len&&j<T->len)
	   if(S->data[i]==T->data[j])
	   {
	   	i++;
	   	j++;
	   }
	   else
	   {
	   	i=i-j+1;
	   	j=0;
	   }
	if(j>=T->len)
	   return (i-T->len);
	else
	   return -1;
}

void gets1(SeqString *p)
{
	int i=0;
	char ch;
	p->len=0;
	scanf("%c",&ch);
	while(ch!='\n')
	{
		p->data[i++]=ch;
		p->len++;
		scanf("%c",&ch);
	}
	p->data[i++]='\0';
}

int main()
{
	int i;
	SeqString *s,*t;
	s=(SeqString*)malloc(sizeof(SeqString));
	t=(SeqString*)malloc(sizeof(SeqString));
	printf("Input main string S:\n");
	gets1(s);
	printf("Output main string S:\n");
	puts(s->data);
	printf("Input substring T:\n");
	gets1(t);
	printf("Output substring T:\n");
	puts(t->data);
	i=StrIndex_BF(s,t);
	if(i==-1)
	  printf("No match string!\n");
	else
      printf("Match position:%d\n",i+1);
    return 0;
}
