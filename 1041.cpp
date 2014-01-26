#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

vector<short> e[46][46];
vector<short> ans;
int visit[2000];
int deg[46];
int r_cnt, start, pos, v_max;

bool dfs_rec(int es, int ed, int eno)
{
    if( visit[e[es][ed][eno]] )
        return false;
//    printf("start=%d, end=%d, no=%d, road_cnt=%d\n",es, ed, eno, ans.size());
    visit[ e[es][ed][eno] ] = 1;
    ans.push_back(e[es][ed][eno]);
    if(ans.size()==r_cnt)
        return true;

    for(int i=1;i<=v_max;i++)
        for(int j=0;j<e[ed][i].size();j++)
            if(dfs_rec(ed,i,j))return true;

    ans.pop_back();
    visit[ e[es][ed][eno] ] = 0;
    return false;
}

bool dfs()
{
    for(int i=1;i<=v_max;i++)
        for(int j=0;j<e[start][i].size();j++)
            if(dfs_rec(start,i,j))return true;
    return false;
}

int main()
{
    ans.reserve(2000);
    for(int i=1;i<=45;i++)
        for(int j=1;j<=45;j++)
            e[i][j].reserve(2000);

    int ia,ib,ic;
    while(scanf("%d %d",&ia,&ib),ia+ib)
    {
        scanf("%d",&ic);
        start = min( ia, ib );
        r_cnt=1;
        memset(visit,0,sizeof(visit));
        memset(deg,0,sizeof(deg));
        e[ia][ib].push_back(ic);
        e[ib][ia].push_back(ic);
        v_max = max(ia,ib);
        deg[ia]++; deg[ib]++;
        while( scanf("%d %d",&ia,&ib), ia+ib )
        {
            scanf("%d",&ic);
            e[ia][ib].push_back(ic);
            e[ib][ia].push_back(ic);
            deg[ia]++; deg[ib]++;
            v_max = max( v_max, max( ia,ib ) );
            r_cnt++;
        }
        bool has_odd_deg = false;
        for(int i=1;i<=v_max;i++)
            has_odd_deg |= (deg[i]&1);
        if(has_odd_deg)
        {
            puts("Round trip does not exist.");
            continue;
        }
        if(dfs())
            for(int i=0;i<ans.size();i++)
                printf("%d%c",ans.at(i),(i==ans.size()-1?'\n':' '));
        else puts("Round trip does not exist.");
        for(int i=1;i<=v_max;i++)
            for(int j=1;j<=v_max;j++)
                e[i][j].resize(0);
    }
}

/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct Road
{
    int a[2],id,t;
}r[2000];
int r_cnt,start,pos,arr1[46];
bool dfs_stop;

int cmp_id( const void *aa, const void *bb )
{
    static Road *a, *b;
    a = (Road*)aa; b = (Road*)bb;
    return a->id - b->id;
}

int cmp_t( const void *aa, const void *bb )
{
    static Road *a, *b;
    a = (Road*)aa; b = (Road*)bb;
    return a->t - b->t;
}

bool connectable( Road rr, int id )
{
    return rr.t == 0 && (rr.a[0]==id || rr.a[1]==id);
}

void debug()
{
    fflush(stdin);
    printf("start=%d, pos=%d\n",start,pos);
    cout<<"id: ";
    for(int i=0;i<r_cnt;i++)
        cout<<r[i].id<<(i==r_cnt-1?'\n':' ');
    cout<<"t: ";
    for(int i=0;i<r_cnt;i++)
        cout<<r[i].t<<(i==r_cnt-1?'\n':' ');
    cin.get();

}

void dfs(int road_cnt = 0)
{
//    debug();
    if( road_cnt == r_cnt )
    {
        if(start == pos) dfs_stop = true;
        return;
    }
    int tmp_pos = pos;
    for(int i=0;i<r_cnt;i++)
        if( connectable(r[i],tmp_pos) )
        {
            r[i].t = road_cnt+1;
//            printf("! tmp_pos=%d, r.a[0]=%d, r.a[1]=%d\n",tmp_pos,r[i].a[0], r[i].a[1]);
            pos = ( r[i].a[0] == tmp_pos ? r[i].a[1] : r[i].a[0] );
            dfs(road_cnt+1);
            if( dfs_stop ) return;
            r[i].t = 0;
        }
    pos = tmp_pos;
}

int main()
{
    int ia,ib;
    while(scanf("%d %d",&ia,&ib),ia+ib)
    {
        r_cnt=1;
        r[0].a[0] = ia; r[0].a[1] = ib; r[0].t=0;
        scanf("%d",&r[0].id);
        start = pos = min( r[0].a[0], r[0].a[1] );
        dfs_stop = false;
        while( scanf("%d %d",&r[r_cnt].a[0],&r[r_cnt].a[1]), r[r_cnt].a[0]+r[r_cnt].a[1] )
        {
            scanf("%d",&r[r_cnt].id);
            r[r_cnt].t=0;
            r_cnt++;
        }
        memset(arr1,0,sizeof(arr1));
        for(int i=0;i<r_cnt;i++)
        {
            arr1[ r[i].a[0] ]++;
            arr1[ r[i].a[1] ]++;
        }
        for(int i=1;i<=45;i++)
            dfs_stop |= (arr1[i] & 1) ;
        if(dfs_stop)
        {
            puts("Round trip does not exist.");
            continue;
        }
        qsort(r,r_cnt,sizeof(Road),cmp_id);
        dfs();
        qsort(r,r_cnt,sizeof(Road),cmp_t);
        if(dfs_stop)
            for(int i=0;i<r_cnt;i++)
                printf("%d%c",r[i].id,(i==r_cnt-1?'\n':' '));
        else puts("Round trip does not exist.");
    }
}
*/
