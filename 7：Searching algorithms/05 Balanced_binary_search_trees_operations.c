//平衡二叉树的建立、结点的查找和删除
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	int key;
	struct node *lchild,*rchild;
}BSTree;
int Depth(BSTree *p)//求二叉树的深度(后序遍历) 
{
	int lchild,rchild;
	if(p==NULL)
	   return 0;
	else
	{
		lchild=Depth(p->lchild); //求左子树高度 
		rchild=Depth(p->rchild); //求右子树高度
		return lchild>rchild?(lchild+1):(rchild+1); 
	}
 } 

void AVL_Revolve(BSTree **p,int k)//对二叉树进行平衡处理
{
	BSTree *q,*r;
	switch(k){
		case 1:r=(*p)->lchild;
		       (*p)->lchild=r->rchild;
		       r->rchild=*p;
		       break;   //LL型旋转处理
		case 2:q=(*p)->lchild;
		       r=q->lchild;
			   (*p)->lchild=r->rchild;
			   q->rchild=r->lchild;
			   r->lchild=q;
			   r->rchild=*p;
			   break;  //LR型旋转处理 
		case 3:q=(*p)->rchild;
		       r=q->lchild;
		       (*p)->rchild=r->lchild;
			   q->lchild=r->lchild;
			   r->rchild=q;
			   r->lchild=*p;
			   break;  //RL行旋转处理 
		case 4:r=(*p)->rchild;
		       (*p)->rchild=r->lchild;
			   r->lchild=*p;  //RR型旋转处理   
	}
	*p=r;   //保存旋转处理后的子树根结点指针 
 } 
 
int Preorder_AVL(BSTree **t)//先序遍历二叉树进行平衡处理
{
	BSTree *stack[MAXSIZE],*p=*t,*r=p;
	int i=0,k,m=0,b=0;
	stack[0]=NULL;
	while(p!=NULL||i>0) //当指针p不空或栈不空(i>0)
	  if(p!=NULL)
	  {
	  	k=0;
	  	if(Depth(p->lchild)-Depth(p->rchild)==2)  //左右子树深度差值为2时
		   if(Depth(p->lchild->lchild)>Depth(p->lchild->rchild))
		       k=1;     //LL型
		   else
		       k=2;     //LR型
		if(Depth(p->lchild)-Depth(p->rchild)==-2)  //左右子树深度差值为-2时
		   if(Depth(p->rchild->lchild)>Depth(p->rchild->rchild))
		       k=3;    //RL型 
		   else
		       k=4;   //RR型
	    if(k>0)
		{
			if(*t==p)
			  m=1; //待平衡处理的子树根结点是平衡二叉树的根结点时置m=1
			AVL_Revolve(&p,k);   //对子树p进行平衡处理
			if(m)
			  *t=p;  //m=1应将平衡后的子树根结点作为平衡二叉树的根结点 
			if(b&&p!=*t)
			   r->rchild=p;  //子树根结点不为根结点时将其作为父结点的右孩子
			if(!b&&p!=*t)
			   r->lchild=p;  //子树根结点不为根结点时将其作为父结点的左孩子
			return 1;   //有平衡处理 
			} 
			stack[++i]=p;  //将该结点压栈
			r=p,b=0; //r指向*p的父结点，b=0表示*p是*r的左孩子
		    p=p->lchild; //沿左子树向下遍历   
	   } 
	   else
	   {
	   	 p=stack[i--];  //将这个无左子树的结点由栈中弹出 
	   	 r=p;b=1;   //r指向*p的父结点，b=1表示*p是*r的右孩子
	     p=p->rchild;  //从该结点右子树的根开始继续沿左子树向下遍历 
		} 
		return 0;   //无平衡处理 
 }
 
void AVL_TreeCreat(BSTree **t,int key)
{
	BSTree *p,*q;
	q=*t;
	while(q!=NULL)
	  if(key==q->key)
	     goto L1;   //查找成功，不插入新结点
	  else
	if(key<q->key)//k小于结点*q的关键字值则到t的左子树查找 
	{
		p=q;
		q=q->lchild;
	 } 
	else //k大于结点*q的关键字值则到t的右子树查找
	{
		p=q;
		q=p->rchild;
	 } 
	q=(BSTree*)malloc(sizeof(BSTree));
	q->key=key;
	q->lchild=NULL; //因作为叶结点插入，故左、右指针均为空
	q->rchild=NULL;
	if(p->key>key)
	  p->lchild=q;  //作为原叶结点*p的左孩子插入
	else
	  p->rchild=q;  //作为原叶结点*p的右孩子插入
	while(Preorder_AVL(t)); //进行平衡处理
   L1: ; 
  }  
  
BSTree *BSTSearch(BSTree *t,int k)//二叉排序树查找
{//在指针t所指的二叉排序树中查找关键字值为k的结点 
	while(t!=NULL)
	if(k==t->key)
	   return t;  
	else
	  if(k<t->key)
	     t=t->lchild;  //k小于根结点*t的关键字值则到t的左子树查找
	  else
	     t=t->rchild;
	return NULL; 
 } 
 
void Preorder(BSTree *p)
{
	if(p!=NULL)
	{
		printf("%4d",p->key);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
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

void BSTDelete(BSTree **t,int key)//在平衡二叉树中删去结点 
{
	BSTree *p,*q,*r;
	q=*t;
	p=*t;
	if(q==NULL)
	 goto L2;
	if(q->lchild==NULL&&q->rchild==NULL&&q->key==key)
	{//树t中仅有一个待删结点*q
	   q=NULL;
	   goto L2; 
	 } 
	while(q!=NULL)
	  if(key==q->key)
	     goto L1;
	  else
	    if(key<q->key)
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
	  goto L2; //树中无此待删结点*q
	L1:if(q->lchild==NULL&&q->rchild==NULL) //待删结点*q为叶结点，即第(1)种情况
		  if(p->lchild==q)
		    p->lchild=NULL;
		  else
		    p->rchild=NULL;
	   else
	    if(q->lchild==NULL) //待删结点*q无左子树，即第（2）种情况
		  if(p->lchild==q) //待删结点*q的右子树根来取代待删结点*q
		    p->lchild=q->rchild;
		  else
		    p->rchild= q->rchild;
		else
		  if(q->rchild==NULL) //待删结点*q无右子树，即第（3）种情况
		     if(p->lchild==q)//待删结点*q的左子树根来取代待删结点*q 
			   p->lchild=q->lchild;
			 else
			   p->rchild=q->lchild;
		  else //待删结点*q有左、右子树，即第(4)种情况
		  {
		    r=q->rchild;
			if(r->lchild==NULL&&r->rchild==NULL)
			{//待删结点*q的右子树仅有一个根结点
			   q->key=r->key; //将右子树这个根结点取代待删结点*q
			   q->rchild=NULL; 
			}
			else
			{
			  p=q; //用p指向"最左下结点"的双亲结点
			  while(r->lchild!=NULL) //查找"最左下结点"
			  {
			  	p=r;
			  	r=r->lchild;
			   } 
			  q->key=r->key;  //"最左下结点"的关键字值送待删结点*q的关键字
			  if(p->lchild==r)  //删去"最左下结点”
			     p->lchild=r->rchild;
			  else
			     p->rchild=r->rchild; 
			}	
		  }			 
	while(Preorder_AVL(t));//进行平衡处理 
   L2: ;		  	 
}

int main()
{
	BSTree *p,*root;
	int i,n,x;
	printf("Input number of BSTree keys:\n");  //生成一棵平衡二叉树
	scanf("%d",&n);
	printf("Input key of BSTree:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(i==0)
		{//生成平衡二叉树的根结点
		  root=(BSTree*)malloc(sizeof(BSTree));
		  root->lchild=NULL;
		  root->rchild=NULL;
		  root->key=x; 
		}
		else
		  AVL_TreeCreat(&root,x);//非空平衡二叉树中插入一个结点 
	 } 
	printf("Output keys of BSTree by Preorder:\n");
	Preorder(root);
	printf("\nOutput keys of BSTree by Inorder:\n");
	Inorder(root);
	printf("\nDepth=%d\n",Depth(root));  //输出平衡二叉树的深度
	printf("Input key for search:\n");
	scanf("%d",&x);
	p=BSTSearch(root,x);
	if(p!=NULL)
	  printf("Found!Key is %d!\n",p->key);
	else
	  printf("No found!\n");
	printf("Input key for delete:\n");
	scanf("%d",&x);
	BSTDelete(&root,x);  //在平衡二叉树中删除该关键字的记录
	printf("Output keys of BSTree by Preorder:\n");
	Preorder(root);
	printf("\nOutput keys of BSTree by deleted:\n");
	Inorder(root);
	printf("\nDepth=%d\n",Depth(root)); //输出平衡二叉树的深度
	return 0; 
}
