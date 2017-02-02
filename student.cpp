#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Student{
	char id[10];
	char name[10];
	int score;
};


Student stu[100010];

bool cmp1(const Student &a,const Student &b)
{
	return strcmp(a.id,b.id)<0;
}

bool cmp2(const Student &a,const Student &b)
{
	if(a.name!=b.name)
		return strcmp(a.name,b.name)<0;
	else
		return strcmp(a.id,b.id)<0;
}

bool cmp3(const Student &a,const Student &b)
{
	if(a.score!=b.score)
		return a.score<b.score;
	else
		return strcmp(a.id,b.id)<0;
}

int main()
{
	int n,c,count;
	count=1;
	while(scanf("%d %d",&n,&c)!=EOF&&n)
	{
		memset(stu,0,sizeof(stu));
		
		for(int i=0;i<n;i++)
		{
			scanf("%s %s %d",&stu[i].id,&stu[i].name,&stu[i].score);
		}
		if(c==1)
		{
			sort(stu,stu+n,cmp1);
		}
		else if(c==2)
		{
			sort(stu,stu+n,cmp2);
		}
		else{
			sort(stu,stu+n,cmp3);
		}

		printf("Case %d:\n",count++);
		for(int i=0;i<n;i++)
		{
			printf("%s %s %d\n",stu[i].id,stu[i].name,stu[i].score);
		}
	}
	return 0;
}