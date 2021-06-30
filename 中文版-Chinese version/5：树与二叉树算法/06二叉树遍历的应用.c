//二叉树遍历的应用 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	char data;
	struct node *lchild,*rchild;
}BSTree;

void Preorder(BSTree *p)
{
	if(p!=NULL)
	{
		printf("%3c",p->data);
		Preorder(p->lchild);
		Preorder(p->rchild); 
	}
 } 
 
BSTree *Search(BSTree *p,char x)//中序遍历查找数据元素 
{
	BSTree *stack[MAXSIZE];
	int i=0;
	stack[0]=NULL;
	while(i>=0)//当指针p不空或栈stack不空(i>o) 
	{
		if(p!=NULL)
		{
			if(p->data==x)
			   return p;
			else
			  stack[++i]=p;//将该结点压栈 
			p=p->lchild;//沿左子树向下遍历 
		}
		else
		{
			p=stack[i--];//将这个无左子树的结点由栈中弹出 
			p=p->rchild;//从该结点右子树的根开始继续沿左子树向下遍历 
		}
		if(p==NULL&&i==0)
		   break;
	 } 
	return NULL;
}

int Countleaf(BSTree *bt)//统计二叉树中叶子结点的个数
{
	if(bt==NULL)
	   return 0;
	if(bt->rchild==NULL&&bt->lchild==NULL)
	   return 1;
	return(Countleaf(bt->lchild)+Countleaf(bt->rchild));
 } 

int Depth(BSTree *p)//后序遍历求二叉树的深度 
{
	int lchild,rchild;
	if(p==NULL)
	   return 0;
	else
	{
		lchild=Depth(p->lchild);
		rchild=Depth(p->rchild);
		return lchild>rchild?(lchild+1):(rchild+1);
	}
}

void Createb(BSTree **p)
{
	char ch;
	scanf("%c",&ch);
	if(ch!='.')
	{
		*p=(BSTree*)malloc(sizeof(BSTree));
		(*p)->data=ch;
		Createb(&(*p)->lchild);
		Createb(&(*p)->rchild);
	}
	else
	  *p=NULL;
}

int main()
{
	BSTree *root,*p;
	char x;
	printf("Preorder enter bitree with'..':\n");
	Createb(&root);
	printf("Preorder output:\n");
	Preorder(root);
	printf("\n");
	getchar();
	printf("Input element of Search:\n");
	scanf("%c",&x);
	p=Search(root,x);
	if(p==NULL)
	   printf("No found!\n");
	else
	   printf("Element Searched is %c\n",p->data);
	printf("leaf of tree is %d\n",Countleaf(root));
	printf("Depth of tree is %d\n",Depth(root));
	return 0;
 } 
