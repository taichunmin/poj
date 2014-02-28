#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
double e[101][101];
int n,m;

int main()
{
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                e[i][j] = (i==j)?100.0:.0;
        int ia,ib,ic;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&ia,&ib,&ic);
            e[ia][ib] = e[ib][ia] = ic;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    e[i][j] = max( e[i][j], e[i][k]*e[k][j]/100.0 );
        cout.precision(6);
        cout.setf(ios::fixed,ios::floatfield);
        cout<<e[1][n]<<" percent"<<endl;
    }
}

/*
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

bool ev[101][101];

int float_cmp( double da, double db )
{
    double e = 1e-5;
    return ( da - db < e )? -1 :( da - db > e );
}

double dfs(int dist)
{
    if(dist==1) return 100.0l;
    double saferate = .0,da;
    for(int i=1;i<=n;i++)
        if( ev[i][dist]==0 && e[i][dist]>0 )
        {
            ev[i][dist] = 1;
            da = dfs(i) * e[i][dist] / 100.0l;
            if( float_cmp(da,saferate) >= 0 )
                saferate = da;
            ev[i][dist] = 0;
        }
    return saferate;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        int ia,ib,ic;
        memset(e,-1,sizeof(e));
        memset(ev,-1,sizeof(ev));
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&ia,&ib,&ic);
            e[ia][ib] = e[ib][ia] = ic;
        }
//        printf("%.6f percent\n",dfs(n));
        cout.precision(6);
        cout.setf(ios::fixed,ios::floatfield);
        cout<<dfs(n)<<" percent"<<endl;
    }
}
*/
