#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define oo 2147483647
using namespace std;

struct Edge
{
    int a,b,w,use;
}e[15001];

int v[1001], n, edge;

int connectable(Edge ea)
{
    return v[ ea.a ] ? ( v[ ea.b ] ? -1 : ea.b ) : ( v[ ea.b ] ? ea.a : -2 );
}

int edge_cmp( const void * aa, const void * bb )
{
    static Edge *a, *b;
    a = (Edge*)aa; b = (Edge*)bb;
    return a->w - b->w;
}

void debug()
{
    fflush(stdin);
    cout<<"edge:"<<endl;
    for(int i=0;i<edge;i++)
        printf("%d: (%d,%d) w=%d use=%d\n", i, e[i].a, e[i].b, e[i].w, e[i].use);
    cout<<"visit:"<<endl;
    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
    cin.get();
}

int main()
{
    while(cin>>n>>edge)
    {
        for(int i=0;i<edge;i++)
        {
            cin>>e[i].a>>e[i].b>>e[i].w;
            e[i].a--; e[i].b--; e[i].use=0;
        }
        memset(v,0,sizeof(v));
        int visit_cnt = 1, ans = 0, max_edge = -oo;
        qsort(e,edge,sizeof(Edge),edge_cmp);
        v[0] = 1;
        while( visit_cnt < n )
        {
            int ia=0, ib;
            while( ia < edge && connectable(e[ia])<0 )
                ia++;
            ib = connectable(e[ia]);
            e[ia].use = 1;
            v[ib] = 1;
            ans += e[ia].w;
            max_edge = max( max_edge, e[ia].w );
            visit_cnt++;
//            debug();
        }
        printf("%d\n%d\n",max_edge,ans);
        for(int i=0;i<edge && e[i].use<2;i++)
            if(e[i].use==1)
                printf("%d %d\n",e[i].a+1,e[i].b+1);
    }
}
