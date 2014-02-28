#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int m,n,p[1000];
bool e[1000][1000],v[1000];

int dfs(int i)
{
    for(int j=0;j<n;j++)
        if( !v[j] && e[i][j] )
        {
            v[j] = 1;
            if(p[j]==-1 || dfs(p[j]))
            {
                p[j] = i;
                return 1;
            }
        }
    return 0;
}

int main()
{
    int ia,ib,ic,ans=0;
    scanf("%d %d %d",&m,&n,&ia);
    memset(e,0,sizeof(e));
    memset(p,-1,sizeof(p));
    while(ia--)
    {
        scanf("%d %d",&ib,&ic);
        e[ib-1][ic-1]=1;
    }
    for(int i=0;i<m;i++)
    {
        memset(v,0,sizeof(v));
        if(dfs(i))ans++;
    }
    printf("%d\n",m+n-ans);
}
