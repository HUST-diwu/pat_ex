#include <cstdio>
#include <algorithm>
using namespace std;
struct station{
	double pos;
	double price;
};

station sta[502];
bool cmp(const station &a,const station &b){
	if(a.pos<b.pos)
		return true;
	else return false;
}
int main()
{
	double capcity,distance,Davg;
	int i, N;
	scanf("%lf%lf%lf%d",&capcity,&distance,&Davg,&N);
	for(int i=0;i<N;i++)
	{
		scanf("%lf%lf",&sta[i].price,&sta[i].pos);
	}
	sort(sta,sta+N,cmp);
	if(distance==0)
	{
		printf("0.00\n");
		return 0;
	}
	if(sta[0].pos!=0)
	{
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	int cur_num=0;
	double cur_gas=0;
	double cur_cost=0;
	bool flag=false;
	double max_disance=capcity*Davg;
	while(!flag)
	{
		bool tag=false;		//zui da ju li nei shifou you gasstation
		bool ifcheaper=false;
		double cheapest=10000;
		for(i=cur_num+1;i<N;i++)
		{
			if((sta[i].pos-sta[cur_num].pos)<=max_disance)
			{
				tag=true;
				if(sta[i].price<sta[cur_num].price)
				{
					
				}
			}
		}	

	}
	
}