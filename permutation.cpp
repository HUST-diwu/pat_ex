#include <cstdio>
using namespace std;
const int MAXN=11;
int per[MAXN],used[MAXN]={false};
int n;
void generatep(int index)//1 to index-1 has been generated
{
	if(index==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d",per[i]);
		}
		printf("\n");
		return ;
	}
	for(int x=1;x<=n;x++)
	{
		if(used[x]==false)
		{
			per[index]=x;
			used[x]=true;
			generatep(index+1);
			used[x]=false;
		}
	}

}

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("more args\n");
		return -1;
	}
	sscanf(argv[1],"%d",&n);
	generatep(1);
	return 0;
}