#include <cstdio>
using namespace std;

int fb[40];
void fb_init()
{
	fb[0]=0;
	fb[1]=1;
	fb[2]=1;
	for(int i=3;i<40;i++)
	{
		fb[i]=fb[i-1]+fb[i-2];
	}
}

void show(int space,int num)
{
	if(num==-1)
	{

		return;
	}
	show(space+2,num-2);
	for(int i=0;i<space;i++)
	{
		printf(" ");
	}
	for(int i=0;i<num;i++)
	{
		if(i!=num-1)
		printf("%d ",fb[i]);
		else
			printf("%d",fb[i]);
	}
	printf("\n");
}

int main()
{
	int m,n;
	fb_init();
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&n);
		show(0,2*n-1);
	}
	return 0;
}