#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
using namespace std;
int A,B,C;
int vis[105][105]={false};
int pre[105][105]={0};
struct node{
	int a,b;//capcity of a and b.
	node(){}
	node(int a,int b):a(a),b(b){}
};
struct pre_node_info{
	int a,b,type;
	pre_node_info(){}
	pre_node_info(int a,int b,int type):a(a),b(b),type(type){}
};
pre_node_info pni[10100];

node BFS(node start)
{
	memset(vis,0,sizeof(vis));
	int cnt=0;
	queue<node> Q;
	Q.push(start);
	vis[start.a][start.b]=true;
	while(!Q.empty())
	{
		node temp=Q.front();Q.pop();
		int a=temp.a,b=temp.b;
		for(int i=0;i<6;i++)
		{
			int new_a,new_b;
			if(i==0){new_a=A;new_b=b;}
			else if(i==1){new_a=a;new_b=B;}
			else if(i==2){new_a=0;new_b=b;}
			else if(i==3){new_a=a;new_b=0;}
			else if(i==4){
				int all=a+b;
				new_a=all>=B?all-B:0;
				new_b=all>=B?B:all;
			}
			else if(i==5){
				int all=a+b;
				new_a=all>=A?A:all;
				new_b=all>=A?all-A:0;
			}
			if(vis[new_a][new_b]==false)
			{
				node to=node(new_a,new_b);
				vis[new_a][new_b]=true;
				pni[cnt++]=pre_node_info(a,b,i);
				pre[new_a][new_b]=cnt-1;
				Q.push(to);
				if(new_b==C)
				{
					return to;
				}

			}
		}
	}
	node f=node(-1,-1);
	return f;
}
int main()
{
	node start=node(0,0);
	while(scanf("%d%d%d",&A,&B,&C)==3)
	{
		node end=BFS(start);
		stack<int> s;
		int a=end.a;
		int b=end.b;
		while(true)
		{
			int index=pre[a][b];
			s.push(pni[index].type);
			a=pni[index].a;b=pni[index].b;
			if(a==0&&b==0)
				break;
		}
		 while(!s.empty())  
        {  
            int t=s.top();s.pop();  
            if(t==0) printf("fill A\n");  
            else if(t==1) printf("fill B\n");  
            else if(t==2) printf("empty A\n");  
            else if(t==3) printf("empty B\n");  
            else if(t==4) printf("pour A B\n");  
            else if(t==5) printf("pour B A\n");  
        }  
        printf("success\n");  
    }  
	
}