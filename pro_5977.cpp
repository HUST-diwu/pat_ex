/**************************************************************
    Problem: 5977
    User: hust_wd
    Language: C++
    Result: 正确
    Time:142 ms
    Memory:1252 kb
****************************************************************/



#include <stack>
#include <cstdio>
using namespace std;
int con=0,n;
stack<int> s,final;
void gp(int left_top)
{
    if(final.size()==n)
    {
        con++;
         
        return;
    }
    //push
    if(left_top>0)
    {
    s.push(left_top);
    gp(left_top-1);
    s.pop();
    }
    //pop
    if(!s.empty())
    {
        int temp=s.top();
        s.pop();
        final.push(temp);
        gp(left_top);
        final.pop();
        s.push(temp);
    }
}
int main()
{
    scanf("%d",&n);
    gp(n);
    printf("%d",con);
    return 0;
}
 
