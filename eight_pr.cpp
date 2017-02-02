#include <cstdio>
#include <algorithm>
using namespace std;
int lie_used[9]={0};
int index[9]={0};
int final[92]={0};
int cou=0;
void generateP(int in)
{
	if(in==9)
	{
		final[cou]=index[1]*10000000+index[2]*1000000+
		index[3]*100000+index[4]*10000+index[5]*1000+
		index[6]*100+index[7]*10+index[8];
		cou++;
		return;
	}
	for(int i=1;i<=8;i++)
	{
		if(lie_used[i]==0)
		{
			bool flag=true;
			for(int pre=1;pre<in;pre++)
			{
				if((in-pre)==(i-index[pre])||(pre-in)==(i-index[pre]))
				{	flag=false;
					break;
				}
			}
			if(flag)
			{
				index[in]=i;
				lie_used[i]=true;
				generateP(in+1);
				lie_used[i]=false;
			}
		}
	}
}

int main()
{
	int m,location;
	generateP(1);
	sort(final,final+92);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&location);
		printf("%d",final[location-1]);
		if(i!=m-1)
			printf("\n");
	}
	return 0;
}