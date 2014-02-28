#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int d[1000][1000],n,log[1000];
bool v[1000],v_cnt;

int prim_dfs(int base)
{
    v[base]=1;
    v_cnt++;
    int dist=-1;
    for(int i=0;i<n;i++)
        if(!v[i])
        {
            log[i] = min( log[i], d[base][i] );
            if( dist==-1 || log[dist]>log[i] )
                dist = i;
        }
    if(dist==-1)
        return 0;
    return max(log[dist],prim_dfs(dist));
}

int prim(int base)
{
    memset(v,0,sizeof(v));
    v_cnt = v[base] = 1;
    int dist = -1;
    for(int i=0;i<n;i++)
        if(!v[i])
        {
            log[i] = d[base][i];
            if(dist==-1 || log[dist]>log[i])
                dist = i;
        }
    return max(log[dist],prim_dfs(dist));
}

int main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&d[i][j]);
        printf("%d\n",prim(0));
    }
}
