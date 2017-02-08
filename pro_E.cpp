#include <stack>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct node{
	char symbol;
	bool if_block;
	bool if_left;
	char A;
};

bool do_it(string str)
{
	bool res=true;
	stack<node> s;
	node temp;
	for(int i=0;i<str.length();)
	{
		if(str[i]!='['&&str[i]!=']'&&str[i]!='{'&&str[i]!='}'&&str[i]!='('&&str[i]!=')')
		{
			temp.symbol=str[i];
			temp.if_block=false;
			s.push(temp);
			i++;
		}
		else if(str[i]=='['||str[i]=='{'||str[i]=='(')
		{
			if(str[i]=='[')
				temp.A=']';
			else if(str[i]=='{')
				temp.A='}';
			else temp.A=')';
			temp.symbol=str[i];
			temp.if_block=true;
			temp.if_left=true;
			s.push(temp);
			i++;
		}
		else{
			while(!s.empty()&&!s.top().if_block)
				s.pop();
			if(s.empty())
				return false;
			if(s.top().A!=str[i])
			{
				s.pop();
				i++;
				return false;
			}
			else {
				s.pop();
				i++;
			}

		}
	}
	while(!s.empty())
	{
		if(s.top().if_block)
			return false;
		else
			s.pop();
	}
	return res;
}

int main()
{
	int n_line;
	string test;
	scanf("%d",&n_line);
	for(int i=0;i<n_line;i++)
	{
		cin>>test;
		if(do_it(test)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}