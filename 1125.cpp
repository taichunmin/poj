#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define oo 1000000000
using namespace std;

int d[101][101];
int ia;

void debug()
{
    puts("dist:");
    for(int i=1;i<=ia;i++)
        for(int j=1;j<=ia;j++)
            printf("%d%c",d[i][j],j==ia?'\n':' ');
}

int main()
{
    while( scanf("%d",&ia)!=EOF, ia )
    {
        for(int i=0;i<=ia;i++)
            for(int j=0;j<=ia;j++)
                d[i][j] = i==j?0:oo;
        for(int i=1;i<=ia;i++)
        {
            int ib,ic,id;
            scanf("%d",&ib);
            while(ib--)
            {
                scanf("%d %d",&ic,&id);
                d[i][ic] = id;
            }
        }
//        debug();
        for(int k=1;k<=ia;k++)
            for(int i=1;i<=ia;i++)
                for(int j=1;j<=ia;j++)
                    d[i][j] = min( d[i][k] + d[k][j], d[i][j] );
//        debug();
        int ans_p = -1, ans_t = oo;
        for(int i=1;i<=ia;i++)
        {
            int ib=-oo;
            for(int j=1;j<=ia;j++)
                ib = max(d[i][j],ib);
            if(ib<ans_t)
            {
                ans_p = i;
                ans_t = ib;
            }
        }
        printf("%d %d\n",ans_p,ans_t);
    }
}
