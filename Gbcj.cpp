#include <cstdio>
using namespace std;

int prime[30001],pnum=0;
bool p[30001]={0};
void find_prime()
{
	for(int i=2;i<30001;i++)
	{
		if(p[i]==false)
		{
			prime[pnum++]=i;
			for(int j=i+i;j<30001;j+=i)
			{
				p[j]=true;
			}
		}
	}
}
int two_pointer(int sum,int *a,int left,int right)
{
	int count=0;
	int i=left,j=right;
	while(i<=j)
	{
		if(a[i]+a[j]==sum)
		{
			i++;
			j--;
			count++;
		}
		else if(a[i]+a[j]<sum)
		{
			i++;
		}
		else{
			j--;
		}
	}
	return count;
}

int main()
{
	int n;
	int flag=true;
	find_prime();
	for(int i=4;i<=40000;i+=2)
	{	
		if(two_pointer(i,prime,0,pnum-1)==0)
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		printf("Goldbach's Conjecture is true in 40000\n");
	}
	else
		printf("Goldbach's Conjecture is false in 40000\n");

}