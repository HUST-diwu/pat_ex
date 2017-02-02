#include <cstdio>
#include <cstring>
using namespace std;

int h[20]={0};
int remain;
int ans=0;

void generate(int index)//the index day eat
{
	int i;
	if(remain==0)
	{
		ans++;
		return;
	}
	for(i=1;i<=remain&&i<=2;i++)
	{
		h[index]=i;
		remain-=i;
		generate(index+1);
		remain+=i;
	}

}

int main()
{
	while(scanf("%d",&remain))
	{
		generate(1);
		printf("%d",ans);
		ans=0;
		memset(h,0,sizeof(h));
	}
	return 0;
} 