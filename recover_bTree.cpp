#include <cstdio>
#include <cstring>
struct node
{
	char data;
	node *rchild;
	node *lchild;
};
char pre[100]={0};char in[100]={0};


node *creat(int preL,int preR,int inL,int inR)
{
	if(preL>preR)
	{
		return NULL;
	}
	node *root=new node;
	root->data=pre[preL];
	int k;
	for(k=inL;k<=inR;k++)
	{
		if(in[k]==pre[preL])
			break;
	}
	int number_left=k-inL;
	root->lchild=creat(preL+1,preL+number_left,inL,k-1);
	root->rchild=creat(preL+number_left+1,preR,k+1,inR);
	return root;
}

void post_order(node *root)
{
	if(root==NULL)
	{
		return ;
	}
	post_order(root->lchild);
	post_order(root->rchild);
	printf("%c",root->data);
}

int main()
{
	while(scanf("%s %s",pre,in)!=EOF)
	{
		int len_pre=strlen(pre);
		int len_in=strlen(in);
		node *root=creat(0,len_pre-1,0,len_in-1);
		post_order(root);
		printf("\n");
	}
	return 0;
}