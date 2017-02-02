#include <cstdio>
#include <cmath>
using namespace std;
struct factor{
	int x,cnt;
}fac[10];

const int MAX=10001;
int prime[MAX],pNum=0;
bool p[MAX]={0};
void find_prime()
{
	for(int i=2;i<MAX;i++)
	{
		if(p[i]==false)
		{
			prime[pNum++]=i;
			for(int j=i+i;j<MAX;j+=i)
				p[j]=true;
		}
	}
}

int wanshu(int n)
{
	int temp=n;
	int sum=1;
	int num=0;//num of p factor
	int sqr=(int)sqrt(1.0*n);
	for(int i=0;i<pNum&&prime[i]<=sqr;i++)
	{
		if(n%prime[i]==0)
		{
			fac[num].x=prime[i];
			fac[num].cnt=0;
			while(n%prime[i]==0)
			{
				fac[num].cnt++;
				n/=prime[i];
			}
			num++;
		}
		if(n==1) break;
	}
	if(n!=1)
	{
		fac[num].x=n;
		fac[num++].cnt=1;
	}
	for(int i=0;i<num;i++)
	{
		sum+=fac[i].x;
	}
	if(temp==sum)
		return true;
	else return false;
}

int main()
{
	int n;
	int cnt=0,w[10]={0};
	find_prime();
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=6;i<=n;i++)
		{
			if(wanshu(i))
			{
				w[cnt++]=i;
			}

		}
		for(int i=0;i<cnt;i++)
		{
			if(i!=cnt-1)
			{
				printf("%d ",w[i]);
			}
			else printf("%d",w[i]);
		}
	}
	return 0;
}