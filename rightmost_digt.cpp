#include <cstdio>
using namespace std;

int pow(int A,int B)
{
	if(A==0)
	{
		return 0;
	}
	if(B==0)
	{
		return 1;
	}
	A=A%10;
	if(B%2==0)
	{
		int tmp=pow(A,B/2);
		return (tmp*tmp)%10;
	}
	if(B%2==1)
	{
		int tmp=pow(A,B/2);
		return (tmp*tmp*A)%10;
	}
}
int main()
{
	int N;
	int m;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&m);
		m=pow(m,m);
		printf("%d\n",m%10);
	}
	return 0;
}