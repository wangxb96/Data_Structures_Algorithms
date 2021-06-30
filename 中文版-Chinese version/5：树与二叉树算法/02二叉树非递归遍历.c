//二叉树非递归遍历 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	char data;
	struct node *lchild,*rchild;
}BSTree;

void Preorder(BSTree *p)
{
	BSTree *stack[MAXSIZE];
	int i=0;
	stack[0]=NULL;
	while(p!=NULL||i>0)
	 if(p!=NULL)
	 {
	 	printf("%3c",p->data);
	 	stack[++i]=p;
	 	p=p->lchild;
	 }
	 else
	 {
	 	p=stack[i--];
	 	p=p->rchild;
     }
}

void Inorder(BSTree *p)
{
	BSTree *stack[MAXSIZE];
	int i=0;
	stack[0]=NULL;
	while(i>=0)
	{
		if(p!=NULL)
		{
			stack[++i]=p;
			p=p->lchild;
		}
		else
		{
			p=stack[i--];
			printf("%3c",p->data);
			p=p->rchild;
		}
		if(p==NULL&&i==0)
		   break;
	}
}

void Postorder(BSTree *p)
{
	BSTree *stack[MAXSIZE];
	int b[MAXSIZE],i=0;//数组b用于标识每个结点是否已遍历过其左、右子树 
	stack[0]=NULL;
	do{
		if(p!=NULL)
		{
			stack[++i]=p;
			b[i]=0;//置该结点右子树未访问过的标志 
			p=p->lchild;
		}
		else
		{
			p=stack[i--];//将这个无左子树（或左子树已遍历过）的当前结点由栈中弹出 
			if(!b[i+1])//b[i+1]为0则当前结点的右子树未遍历 
			{
				stack[++i]=p;//将当前结点重新压栈 
				b[i]=1;//置当前结点右子树已访问过标志 
				p=p->rchild;
			}
			else//当前结点的左、右子树都已遍历（即结点信息都已输出） 
			{
				printf("%3c",p->data);
				p=NULL;//将指向当前结点的指针置为空 
			}
		}
	}while(p!=NULL||i>0);//当指针p不空或栈stack不空(i>0)时继续遍历 
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
	BSTree *root;
	printf("Preorder enter bitree with'..':\n");
	Createb(&root);
	printf("Preorder output:\n");
	Preorder(root);
	printf("\n");
	printf("Inorder output:\n");
	Inorder(root);
	printf("\n");
	printf("Postorder output:\n");
	Postorder(root);
	printf("\n");
	return 0;
}
