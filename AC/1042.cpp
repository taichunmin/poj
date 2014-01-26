#include<cstdio>
#include<cstring>
#define oo 2147483647
using namespace std;

int n,h,f[25],d[25],t[25];

struct Node
{
    int n,h,ans,f[25],t[25];
}ans,na;

void print_node( Node nn )
{
    for(int i=0;i<n;i++)
        printf("%s%d",(i?", ":""),nn.t[i]*5);
    printf("\nNumber of fish expected: %d\n",nn.ans);
}

int cmp_node( Node aa, Node bb )
{
    if( aa.ans != bb.ans )
        return aa.ans > bb.ans ? 1 : -1;
    for(int i=0;i<n;i++)
        if( aa.t[i] != bb.t[i] )
            return aa.t[i] > bb.t[i] ? 1 : -1;
    return 0;
}

void fishing(int aa)
{
//    printf("fishing(%d)\n",aa);
    memset( &na, 0, sizeof(na) );
    na.n = aa+1;
    na.h = h - t[aa];
    if(na.h<=0) return;
    na.ans = 0;
    for(int i=0;i<na.n;i++)
        na.f[i] = f[i];
    while(na.h>0)
    {
//        print_node(na);
//        getchar();
        int ia = -1;
        for(int i=0;i<na.n;i++)
            if( na.f[i]>0 && (ia<0 || na.f[i]>na.f[ia]) )
                ia = i;
        if(ia<0)
        {
            na.t[0] += na.h;
            break;
        }
        na.ans += na.f[ia];
        na.f[ia] -= d[ia];
        na.t[ia]++;
        na.h--;
    }
    if( cmp_node(na,ans)>0 )
        ans = na;
}

int main()
{
    bool isfirst = true;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&h);
        h*=12;
        for(int i=0;i<n;i++)
            scanf("%d",&f[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&d[i]);
        t[0]=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d",&t[i]);
            t[i] += t[i-1];
        }
//        debug();
        ans.ans = -oo;
        for(int i=0;i<n;i++)
            fishing(i);
        if(isfirst) isfirst = false;
        else puts("");
        print_node( ans );
    }
}
