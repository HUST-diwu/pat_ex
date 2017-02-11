#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
/*
坑有点多。。。。。
1.结构体or类中不能初始化对象。。。。必须要在初始化列表中初始化，如要用vector...若是没在列表中初始化，容易段错误
2.copy(....) 的用法是起始指针，结束指针（下一个），目的地址
3.以后还是少用using namespace std;坑
4.用MAP做used[]数组用时，找不到就是false，即find(first key)返回map.end().访问时，在插入就等于赋值true.还是要学会用unorder_map啊，map速度有点慢
5.BFS在入队邻接点时，应先确定此点是否有访问意义。即test().
*/
struct state{
	vector<int> v;
	int x,y,step;
	state():v(9){}
}start,End,temp;
map<vector<int>,int> Hash;
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
bool test(int x,int y)
{
	if(x>=3||x<0||y>=3||y<0) return false;
	else return true;
}
int BFS()
{
	queue<state> q;
	q.push(start);
	while(!q.empty())
	{
		state top=q.front();
		q.pop();
		Hash[top.v]=true;
		if(top.v==End.v)
			return top.step;
		for(int i=0;i<4;i++)
		{
			int newx=top.x+X[i];
			int newy=top.y+Y[i];
			if(test(newx,newy))
			{
				temp.x=newx;
				temp.y=newy;
				vector<int> tv(top.v);
				swap(tv[top.x*3+top.y],tv[newx*3+newy]);
				if(Hash.find(tv)==Hash.end())
				{
					Hash[tv]=true;
					copy(tv.begin(),tv.end(),temp.v.begin());
					temp.step=top.step+1;
					q.push(temp);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int in;
	for(int i=0;i<9;i++)
	{
		scanf("%d",&start.v[i]);
		//start.v.push_back(in);
		if(start.v[i]==0)
		{
			start.x=i/3;
			start.y=i-start.x*3;
			start.step=1;
		}
	}
	for(int i=0;i<9;i++)
	{
		scanf("%d",&End.v[i]);
		//end.v.push_back(in);
		if(End.v[i]==0)
		{
			End.x=i/3;
			End.y=i-start.x*3;
		}
	}
	printf("%d\n",BFS());
	return 0;
}
