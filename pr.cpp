#include <cstdio>
using namespace std;
const int MAXN = 100001;
int prime[MAXN],pnum=0;
bool p[MAXN]={false};
void Find_Prime()
{
	for(int i=2;i<MAXN;i++)
	{
		if(p[i]==false)
		{
			prime[pnum++]=i;
			for(int j=i+i;j<MAXN;j+=i)
			{
				p[j]=true;
			}
		}
	}
}

int main()
{
	Find_Prime();
	printf("total prime is %d\n",pnum);
	for(int i=0;i<pnum;i++)
	{
		printf("%d",prime[i]);
		if((i+1)%28!=0)printf(" ");
		else printf("\n");
	}
	return 0;
}