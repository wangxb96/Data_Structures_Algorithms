//中序线索二叉树 
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char data;
	int ltag,rtag;
	struct node *lchild;
	struct node *rchild;
}TBTree;
TBTree *pre;
void Thread(TBTree *p)
{
	if(p!=NULL)
	{
		Thread(p->lchild);//先对*p的左子树线索化，到此，*p结点的左子树不存在或已线索化，接下来对*p线索化
		if(p->lchild==NULL)
		{
			p->lchild=pre;
			p->ltag=1;
		 } 
		else
		   p->ltag=0;
		if(pre->rchild==NULL)
		{
			pre->rchild=p;
			pre->rtag=1;
		}
		else
		   pre->rtag=0;
	    pre=p;
	    Thread(p->rchild);
	}
 } 
 
TBTree *CreaThread(TBTree *b)
{
	TBTree *root;
	root=(TBTree*)malloc(sizeof(TBTree));
	root->ltag=0;
	root->rtag=1;
	if(b==NULL)
	{
		root->lchild=root;
	}
	else
	{
		root->lchild=b;  //root的lchild指针指向二叉树结点*b 
		pre=root;     //*pre是*p的前驱结点，pre指针用于线索 
		Thread(b);   //对二叉树b进行中序线索化 
		pre->rchild=root;//最后处理，加入指向头结点的线索 
		pre->rtag=1;
		root->rchild=pre;//头结点的rchild指针线索化为指向最后一个结点 
	}
	return root;//返回线索化后指向二叉树的头结点的指针 
}

void Inorder(TBTree *b)
{//*b为中序线索二叉树的头结点
   TBTree *p;
   p=b->lchild;
   while(p!=b)//当p不等于指向头结点的指针b时 
   {
   	  while(p->ltag==0)
   	     p=p->lchild;
   	  printf("%3c",p->data);
   	  while(p->rtag==1&&p->rchild!=b)
   	  {
   	  	p=p->rchild;
   	  	printf("%3c",p->data);
		 }
	  p=p->rchild;
   }
}

void Preorder(TBTree *p)
{
	if(p!=NULL)
	{
		printf("%3c",p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void Createb(TBTree **p)
{
	char ch;
	scanf("%c",&ch);
	if(ch!='.')
	{
		*p=(TBTree*)malloc(sizeof(TBTree));
		(*p)->data=ch;
		Createb(&(*p)->lchild);
		Createb(&(*p)->rchild);
	}
	else
	   *p=NULL;
}

int main()
{
	TBTree *root,*p;
	printf("Preorder enter bitree with'...':\n");
	Createb(&root);
	printf("Preorder output:\n");
	Preorder(root);
	printf("\n");
	p=CreaThread(root);//中序线索化
	printf("Inorder output:\n");
	Inorder(p);
	printf("\n");
	return 0; 
}
