//二叉树以二叉链表为存储结构，试设计一个算法，若结点左孩子的data域值大于右孩子的data域值，则交换其左右子树 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	char data;
	struct node *lchild,*rchild;
}BSTree;
void Inorder(BSTree *p)
{
	if(p!=NULL)
	{
		Inorder(p->lchild);
		printf("%3c",p->data);
		Inorder(p->rchild);
	}
}

void Change(BSTree *p)
{
	BSTree *q;
	if(p!=NULL)
	{
		if(p->lchild!=NULL&&p->rchild!=NULL&&p->lchild->data>p->rchild->data)
		{//交换左、右孩子指针 
			q=p->lchild;
			p->lchild=p->rchild;
			p->rchild=q;
		}
		Change(p->lchild);
		Change(p->rchild);
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
	BSTree *root;
	printf("Make a tree:\n");
	Createb(&root);
	printf("Inorder output:\n");
	Inorder(root);
	printf("\n");
	Change(root);
	printf("Inorder output of change:\n");
	Inorder(root);
	printf("\n");
	return 0; 
}
