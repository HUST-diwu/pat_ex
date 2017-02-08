/**************************************************************
    Problem: 5978
    User: hust_wd
    Language: C++
    Result: 正确
    Time:490 ms
    Memory:1252 kb
****************************************************************/

#include <cstdio>
#include <vector>
using namespace std;
struct node{
    int x,y;
};
bool martix[50][16];
int n,m,solution=0;
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
int visited[1000]={false};
vector<node> path;
void display(vector<node>& path)
{
    int n=path.size();
    for(int i=0;i<n;i++)
    {
        printf("(%d,%d)",path[i].x,path[i].y);
        if(i!=n-1)
        printf("->");
        else printf("\n");
    }
}
bool test(node p)
{
    if(p.x>n||p.x<=0||p.y>m||p.y<=0) return false;
    if(martix[p.x][p.y]==false) return false;
    if(visited[p.x*m+p.y]) return false;
    return true;
}
void DFS(node start,node end)
{
    if(start.x==end.x&&start.y==end.y)
    {
        visited[start.x*m+start.y]=true;
        path.push_back(start);
        display(path);
        solution++;
        return;
    }
        visited[start.x*m+start.y]=true;
        path.push_back(start);
        for(int i=0;i<4;i++)
        {
            node next;
            next.x=start.x+X[i],next.y=start.y+Y[i];
            if(test(next))
            {
                DFS(next,end);
                visited[next.x*m+next.y]=false;
                path.pop_back();
            }
        }
}
  
 int main()
 {
    node start,end;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        scanf("%d",&martix[i+1][j+1]);
    }
    scanf("%d%d",&start.x,&start.y);
    scanf("%d%d",&end.x,&end.y);
    DFS(start,end);
    if(solution==0)
    printf("-1\n");
    return 0;
 }
