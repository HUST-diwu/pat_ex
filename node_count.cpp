#include <cstdio>
struct node{
	int data;
	int lchild;
	int rchild;
};
node b_tree[100000];
void init_tree(int n)
{
	for(int i=1;i<(n/2);i++)
	{
		b_tree[i].lchild=2*i;
		b_tree[i].rchild=2*i+1;
	}
	if(n%2==0)
	{
		b_tree[n/2].lchild=n;
		b_tree[n/2].rchild=0;
	}
	else{
		b_tree[n/2].lchild=n-1;
		b_tree[n/2].rchild=n;
	}
	for(int i=(n/2)+1;i<=n;i++)
	{
		b_tree[i].lchild=0;
		b_tree[i].rchild=0;
	}
}

int count_of_tree(int root)
{
	int ct=0;
	if(root==0)
	{
		return 0;
	}
	ct++;
	ct+=count_of_tree(b_tree[root].lchild);
	ct+=count_of_tree(b_tree[root].rchild);
	return ct;
}
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n),m!=0&&n!=0)
	{
		init_tree(n);
		printf("%d\n",count_of_tree(m));
	}
	return 0;
}