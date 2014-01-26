#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define oo 2147483647
#define __MAX(x,y) (x)>(y)?(x):(y)
#define __MIN(x,y) (x)<(y)?(x):(y)
using namespace std;

struct Node
{
    int x,y,w,p;
    bool v;
}p[200];

int d[200][200];
int ia;

void debug()
{
    for(int i=0;i<ia;i++)
        printf("%d: (%d,%d) w=%d v=%d p=%d\n",i,p[i].x,p[i].y,p[i].w,p[i].v,p[i].p);
}

void add_node(int pa, int pb)
{
    p[pb].v = true;
    p[pb].w = __MAX(p[pb].w,p[pa].w);
    p[pb].p=0;
    for(int i=0;i<ia;i++)
        if( !p[i].v && ( p[i].w > d[pb][i] || (p[pb].w == d[pb][i] && p[i].p>0 && p[p[i].p].w > p[pb].w) ) )
        {
            p[i].w = d[pb][i];
            p[i].p = pb;
        }
//    printf("Link %d to %d:\n", pa, pb);
//    debug();
//    cin.get();
}
void prim()
{
//    cout<<"ia="<<ia<<endl;
    p[0].w = 0;
    add_node(0,0);
    while( !p[1].v )
    {
        int nmin = oo, np = -1;
        for(int i=0;i<ia;i++)
            if( !p[i].v && nmin>p[i].w )
            {
                np = i;
                nmin = p[i].w;
            }
        add_node(p[np].p, np);
    }
}

int inline dista( Node &pa, Node &pb )
{
    int x = pa.x-pb.x, y=pa.y-pb.y;
    return x*x + y*y;
}

int main()
{
    int t0=0;
    while(cin>>ia,ia)
    {
        memset(d,0,sizeof(d));
        for(int i=0;i<ia;i++)
        {
            cin>>p[i].x>>p[i].y;
            p[i].w=oo;
            p[i].v=false;
            p[i].p=-1;
        }
        for(int i=0;i<ia;i++)
            for(int j=i;j<ia;j++)
                d[i][j] = d[j][i] = dista( p[i], p[j] );
//        cout<<"ia="<<ia<<endl;
        prim();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",++t0,sqrt(p[1].w+.0));
    }
}
