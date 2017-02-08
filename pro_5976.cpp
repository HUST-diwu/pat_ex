/**************************************************************
    Problem: 5976
    User: hust_wd
    Language: C++
    Result: 正确
    Time:25 ms
    Memory:1216 kb
****************************************************************/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,_count,p[11],used[11]={false};
std::vector<int> final;
void gp(int index)
{
    if(index==n+1)
    {
        bool flag=true;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
                if(abs(i-j)==abs(p[i]-p[j]))
                    flag=false;
        }
        if(flag){
            _count++;
            for(int i=1;i<=n;i++)
            {
                printf("%d",p[i]);
                if(i==n)printf("\n");
                else printf(" ");
            }
            //final.push_back(temp);
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==false)
        {
            p[index]=i;
            used[i]=true;
            gp(index+1);
            used[i]=false;
        }
    }
}
 
/*bool cmp(string a,string b)
{
    return a<b;
}*/
int main()
{
    scanf("%d",&n);
    gp(1);
    if(_count==0)
    {
        printf("no solute!\n");
    }
    /*else{
        sort(final.begin(),final.end(),cmp);
        for(int i=0;i<count;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%c",final[i][j]);
                if(j!=n)
                    printf(" ");
            }
            if(i!=count-1)
                printf("\n");
        }
    }*/
    return 0;
}
