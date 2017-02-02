#include <cstdio>
#include <algorithm>
using namespace std;
int v[200];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}

		sort(v,v+n);
		printf("%d\n",v[n-1]);
		if(n==1)
			printf("%d\n",-1);
		else
			{
		for(int i=0;i<n-1;i++)
		{
			printf("%d",v[i]);
			if(i==n-2)
				printf("\n");
			else printf(" ");
		}
		}
		//printf("\n");
	}
	return 0;
}