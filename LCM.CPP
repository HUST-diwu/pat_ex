#include <cstdio>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else return gcd(b,a%b);
}

int lcm(int a,int b)
{
	int temp=gcd(a,b);
	return a/temp*b;
}

int a[10000]={0};

int main()
{
	int cases,m,out;
	scanf("%d",&cases);
	for(int i=0;i<cases;i++)
	{
		out=1;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[j]);
		}
		for(int j=0;j<m;j++)
		{
			out=lcm(a[j],out);
		}
		printf("%d\n",out);
	}
	
	return 0;
}