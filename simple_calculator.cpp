/*
author:Di-Wu
time:2017.Feb.2.16:35
note:enter '0' to close program
*/


#include <cstdio>       
#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <map>
using namespace std;

struct node{
	double num;
	char op;
	bool flag;     //true for number,false for op.
};

string str;
stack<node> s;
queue<node> q;
map<char,int> op;

void change()
{
	node temp;
	for(int i=0;i<str.length();)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			temp.flag=true;
			temp.num=str[i++]-'0';
			while(i<str.length()&&str[i]>='0'&&str[i]<='9')
			{
				temp.num=temp.num*10+(str[i]-'0');
				i++;
			}
			q.push(temp);
		}
		else if(str[i]=='('||str[i]==')')
		{

			if(str[i]=='(')
			{
				temp.flag=false;
				temp.op='(';
				s.push(temp);
			}
			else if(str[i]==')')
			{
				while(!s.empty()&&s.top().op!='(')
				{
					q.push(s.top());
					s.pop();
				}
				s.pop();
			}
			i++;
		}
		else
		{
			temp.flag=false;
			while(!s.empty()&&op[str[i]]<=op[s.top().op])
			{
				q.push(s.top());
				s.pop();
			}
			temp.op=str[i];
			s.push(temp);
			i++;
		}
	}
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
}

double cal()
{
	double temp1,temp2;
	node cur,temp;
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		if(cur.flag) s.push(cur);
		else{
			temp2=s.top().num;
			s.pop();
			temp1=s.top().num;
			s.pop();
			temp.flag=true;
			if(cur.op=='+') temp.num=temp1+temp2;
			else if(cur.op=='-') temp.num=temp1-temp2;
			else if(cur.op=='*') temp.num=temp1*temp2;
			else temp.num=temp1/temp2;
			s.push(temp);
		}
	}
	return s.top().num;

}

int main()
{
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	while(getline(cin,str),str!="0")
	{
		for(string::iterator it=str.begin();it!=str.end();it++)
		{
			if(*it==' ')
				str.erase(it);
		}
		while(!s.empty()) s.pop();
		change();
		printf("%.2f\n",cal());
	}

	
	return 0;
}