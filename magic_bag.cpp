#include <cstdio>
using namespace std;

int bag[40]={0};

int solution(int left,int right,int request)
{
	if(request==0)
		return 1;
	int count=0;
	int count_left=0;
	int count_right=0;
	if(left==right)
	{
		if(request==bag[left])
		return 1;
		else return 0;
	}
	for(int i=0;i<=request/2;i++)
	{
		count_left=solution(left,(left+right)/2,i);
		count_right=solution((left+right)/2+1,right,request-i);
		count+=count_left*count_right;
	}
	return count;

}

int main()
{
	bag[0]=1,bag[1]=2,bag[2]=3;
	printf("%d\n",solution(0,2,3));
	return 0;
}