//二叉排序树建立、结点的查找和删除
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	int key;
	struct node *lchild,*rchild;
}BSTree;
void BSTreeCreat(BSTree *t,int k)
{//非空二叉排序树中插入一个结点 
	BSTree *p,*q;
	q=t;
	while(q!=NULL)
	  if(k==q->key)
	    goto L1;
	  else if(k<q->key){//k小于结点*q的关键字则到t是左子树查找 
	  	p=q;
	  	q=q->lchild;
	  }
	  else
	  {//k大于结点*q的关键字值则到t的右子树查找 
	  	p=q;
	  	q=p->rchild;
	  }
	  q=(BSTree*)malloc(sizeof(BSTree));
	  q->key=k;
	  q->lchild=NULL;
	  q->rchild=NULL;
	  if(p->key>k)
	     p->lchild=q;//作为原叶结点*p的左孩子插入 
	  else
	     p->rchild=q;//作为原叶结点*p的右孩子插入
	  L1: ;   
 } 
BSTree *BSTSearch(BSTree *t,int k)
{//在指针t所指的二叉排序树中查找关键字值为k的结点 
	while(t!=NULL)
	if(k==t->key)
	   return t;
	else
	   if(k<t->key)
	     t=t->lchild;//k小于结点*q的关键字则到t是左子树查找 
	   else 
	     t=t->rchild;//k大于结点*q的关键字则到t是右子树查找
	return NULL; 
}

void Inorder(BSTree *p)
{
	if(p!=NULL)
	{
		Inorder(p->lchild);
		printf("%4d",p->key);
		Inorder(p->rchild);
	}
}

void BSTDelete(BSTree **t,int k)//在二叉排序树中删去结点
{
	BSTree *p,*q,*r;
	q=*t;
	p=*t;
	if(q==NULL)
	  goto L2;
	if(q->lchild==NULL&&q->rchild==NULL&&q->key==k)
	{
		q=NULL;
		goto L2;
	}
	while(q!=NULL)
	 if(k==q->key)
	   goto L1;
	 else
	   if(k<q->key)
	   {
	   	 p=q;
	   	 q=q->lchild;
	   }
	   else
	   {
	   	 p=q;
	   	 q=q->rchild;
	   }
	if(q==NULL)
	  goto L2;   //树中无此待删结点*q 
	L1:if(q->lchild==NULL&&q->rchild==NULL) //待删结点*q为叶结点,第一种情况 
	  if(p->lchild==q)
	    p->lchild=NULL; 
	  else
	    p->rchild=NULL;
	else
	  if(q->lchild==NULL)//待删结点*q无左子树，第二种情况 
	    if(p->lchild==q)
		  p->lchild=q->rchild;
		else
		  p->rchild=q->rchild;
	  else
	    if(q->rchild==NULL)//待删结点*q无右子树，第三种情况 
		  if(p->lchild==q) //用待删结点*q的左子树根来取代待删结点*q
		    p->lchild=q->lchild;
		  else
		    p->rchild=q->lchild;
		else//待删结点*q有左、右子树，第四种情况 
		{
			r=q->rchild;
			if(r->lchild==NULL&&r->rchild==NULL)
			{
				q->key=r->key;
				q->rchild=NULL;
			}
			else
			{
				p=q;
				while(r->lchild!=NULL)
				{
					p=r;
					r=r->lchild;
				}
				q->key=r->key;
				if(p->lchild==r)
				  p->lchild=r->rchild;
				else
				  p->rchild=r->rchild;
			}
		  }  
    L2: ;
 } 
 
int main()
{
	BSTree *p,*root;
	int i,n,x;
	printf("Input number of BSTree keys：\n");
	scanf("%d",&n);
	printf("Input key of BSTree:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(i==0)
		{
			root=(BSTree*)malloc(sizeof(BSTree));//生成二叉排序树的根结点 
			root->lchild=NULL;
			root->rchild=NULL;
			root->key=x;
		}
		else
		   BSTreeCreat(root,x); 
	}
	printf("Output keys of BSTree by inorder:\n");
	Inorder(root);
	printf("\nInput key for search:\n");
	scanf("%d",&x);
	p=BSTSearch(root,x);
	if(p!=NULL)
	  printf("Found,key is %d!\n",p->key);
	else
	  printf("No found!\n");
	printf("\nInput key for delete:\n");
	scanf("%d",&x);
	BSTDelete(&root,x);
	printf("Output keys of BSTree by deleted:\n");
	Inorder(root);
	printf("\n");
	return 0; 
}
