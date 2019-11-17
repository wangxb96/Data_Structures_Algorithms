//由二叉树的遍历序列恢复二叉树
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	char data;
	struct node *lchild,*rchild;
}BSTree;
char pred[MAXSIZE],ind[MAXSIZE];
int i=0,j=0;
void Preorder(BSTree *p)
{
	if(p!=NULL)
	{
		pred[i++]=p->data;
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
 } 

void Inorder(BSTree *p)
{
	if(p!=NULL)
	{
		Inorder(p->lchild);
		ind[j++]=p->data;
		Inorder(p->rchild);
	}
}

void Pre_In_order(char pre[],char ind[],int i,int j,int k,int h,BSTree **p)
{//i、j和k、h分别为当前子树先序序列和中序序列的下、上界 
	int m;
	*p=(BSTree*)malloc(sizeof(BSTree));
	(*p)->data=pred[i];
	m=k;//m指向ind数组所存储的中序序列中的第一个结点 
	while(ind[m]!=pred[i])//找到根结点在中序序列所在的位置 
	   m++;
	if(m==k)//根结点是中序序列的第一个结点时则无左子树 
	  (*p)->lchild=NULL;
	else
	  Pre_In_order(pred,ind,i+1,i+m-k,k,m-1,&(*p)->lchild);//根据根结点所划分出中序序列的两个部分继续构造左、右两棵子树 
	if(m==h)//根结点是中序序列的最后一个结点时则无右子树
	  (*p)->rchild=NULL;
	else
	  Pre_In_order(pred,ind,i+m-k+1,j,m+1,h,&(*p)->rchild);//根据根结点所划分出中序序列的两个部分继续构造左、右两棵子树 
}

void Print_Inorder(BSTree *p)
{
	if(p!=NULL)
	{
		Print_Inorder(p->lchild);
		printf("%3c",p->data);
		Print_Inorder(p->rchild);
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
	BSTree *root,*root1;
	printf("Preorder enter bitree with'..':\n");
	Createb(&root);
	printf("Inorder output root:\n");
	Print_Inorder(root);
	printf("\n");
	Preorder(root);
	printf("Inorder output:\n");
	Inorder(root);
	if(i>0)
	   Pre_In_order(pred,ind,0,i-1,0,j-1,&root1);
	printf("Inorder output root1:\n");
	Print_Inorder(root1);
	printf("\n");
	return 0;
}
