#include<iostream>
#include<cstdio>
#define oo 2147483647
using namespace std;

int main()
{
    int T,ia,ib,ic,ans[2];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&ia,&ib);
        ans[0] = ans[1] = -oo;
        for(int i=0;i<ib;i++)
        {
            scanf("%d",&ic);
            if( ic>ia/2 )
                ic = ia-ic;
            ans[0] = max(ans[0],ic);
            ans[1] = max(ans[1],ia-ic);
        }
        printf("%d %d\n",ans[0],ans[1]);
    }
}
