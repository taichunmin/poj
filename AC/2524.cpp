#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int reli[50001],n,m;

void debug()
{
    for(int i=1;i<=n;i++)
        printf("%d%c",reli[i],(i==n?'\n':' '));
}

int find_reli(int ia)
{
    if( reli[ia] == -1 || reli[ia] == ia )
        return ia;
    return reli[ia] = find_reli(reli[ia]);
}

int main()
{
    int t0=0;
    while(scanf("%d %d",&n,&m),n+m)
    {
        int ia,ib;
        memset(reli,-1,sizeof(reli));
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&ia,&ib);
            reli[ find_reli(ib) ] = find_reli(ia);
//            debug();
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(find_reli(i)==i)
                ans++;
        printf("Case %d: %d\n",++t0,ans);
    }
}
