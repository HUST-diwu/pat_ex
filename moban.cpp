#include <cstdio>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
struct node{
	vector<char> v;
	char type;
	node(){}
	node(vector<char> v,char type):v(v),type(type){};
};
vector<node> States(8*7*6*5*4*3*2*1);
map<vector<char>,int> pre_index;//no pre 
std::vector<char> _END(8),start(8);
void BFS()
{
	pre_index.clear();
	int cnt=0;
	queue<vector<char> > Q;
	Q.push(start);
	pre_index[start]=-1;//start has no pre node
	while(!Q.empty())
	{
		std::vector<char> temp=Q.front();Q.pop();
		for(int i='A';i<='C';i++)
		{
			vector<char> new_state=temp;
			if(i=='A')
			{
				swap(new_state[0],new_state[7]);swap(new_state[1],new_state[6]);swap(new_state[2],new_state[5]);
				swap(new_state[3],new_state[4]);
			}
			else if(i=='B')
			{
				char t1=new_state[3],t2=new_state[4];
				for(int j=3;j>0;j--)
					new_state[j]=new_state[j-1];
				for(int j=5;j<=7;j++)
					new_state[j-1]=new_state[j];
				new_state[0]=t1,new_state[7]=t2;
			}
			else{
				char t1=new_state[1],t2=new_state[2],t3=new_state[5],t4=new_state[6];
				new_state[1]=t4;
				new_state[2]=t1;
				new_state[5]=t2;
				new_state[6]=t3;
			}
			if(pre_index.find(new_state)==pre_index.end())//new state has never been searched
			{
				States[cnt++]=node(temp,i);
				pre_index[new_state]=cnt-1;
				Q.push(new_state);
				if(new_state==_END)
				{
					return;
				}
			}
		}
	}
}
int main()
{
	for(int i=0;i<8;i++) start[i]=i+1;
	while(scanf("%d%d%d%d%d%d%d%d",&_END[0],&_END[1],&_END[2],&_END[3],&_END[4],&_END[5],&_END[6],&_END[7])!=EOF)
	{
		BFS();
		stack<char> s;
		std::vector<char> temp_state=_END;
		while(true)
		{
			int pos=pre_index[temp_state];
			s.push(States[pos].type);
			temp_state=States[pos].v;
			if(temp_state==start)
				break;
		}
		printf("%d\n",s.size());
		while(!s.empty())
		{
			char t=s.top();
			s.pop();
			printf("%c",t);
		}
		printf("\n");
	}
	return 0;
}

