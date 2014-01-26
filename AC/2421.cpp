#include<iostream>
#include<cstdio>
#include<cstring>
#define oo 2147483647
#define __MAX(x,y) (x)>(y)?(x):(y)
#define __MIN(x,y) (x)<(y)?(x):(y)
using namespace std;

struct Node
{
    int w,v;
}p[100];

int d[100][100];
int ia;

void debug()
{
    for(int i=0;i<ia;i++)
        printf("%d: w=%d v=%d\n",i,p[i].w,p[i].v);
}

int main()
{
    while(cin>>ia && ia+0)
    {
        for(int i=0;i<ia;i++)
        {
            for(int j=0;j<ia;j++)
                scanf(" %d",&d[i][j]);
            p[i].w = oo;
            p[i].v = 0;
        }
        int ib,ic,id;
        cin>>ib;
        while(ib--)
        {
            cin>>ic>>id;
            d[ic-1][id-1] = d[id-1][ic-1] = 0;
        }
        int visit_cnt = 1, ans = 0;
        p[0].v = 1;
        for(int i=0;i<ia;i++)
            if( p[i].v==0 && p[i].w>d[0][i] )
                p[i].w = d[0][i];
        while( visit_cnt < ia )
        {
            ib = oo, ic = -1;
            for(int i=0;i<ia;i++)
                if( p[i].v==0 && ib>=p[i].w )
                {
                    ib = p[i].w;
                    ic = i;
                }
            ans += ib;
            p[ic].v = 1;
            visit_cnt++;
            for(int i=0;i<ia;i++)
                if( p[i].v==0 && p[i].w>d[ic][i] )
                    p[i].w = d[ic][i];
//            debug();
//            cin.get();
        }
        cout<<ans<<endl;
    }
}
