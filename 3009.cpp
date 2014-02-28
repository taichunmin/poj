#include<iostream>
#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;

int m,n;

struct bfs_state
{
    char ca[20][21];
    int m,s[2];
}start,goal;

bool in_range(int ia,int ib)
{
    return 0<=ia && ia<ib;
}
bool in_range(bfs_state aa)
{
    return in_range(aa.s[0],m) && in_range(aa.s[1],n);
}
bool is_goal(bfs_state aa)
{
    return aa.s[0]==goal.s[0] && aa.s[1]==goal.s[1];
}

deque<bfs_state> q;

bfs_state move(bfs_state aa, int di)
{
    const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
    int nx = aa.s[0]+dir[di][0], ny = aa.s[1]+dir[di][1];
    aa.m++;
    bool ba = false;
    while( !is_goal(aa) && in_range(aa) && ( !(in_range(nx,m) && in_range(ny,n)) || aa.ca[nx][ny] == '0') )
    {
        aa.s[0]=nx; aa.s[1]=ny;
        nx = aa.s[0]+dir[di][0];
        ny = aa.s[1]+dir[di][1];
        ba = true;
    }
    if( in_range(nx,m) && in_range(ny,n) && aa.ca[nx][ny] == '1' && ba )
        aa.ca[nx][ny] = '0';
    return aa;
}
void debug(bfs_state aa)
{
    printf("bfs_state (%d,%d), m=%d\n",aa.s[0],aa.s[1],aa.m);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( aa.ca[i][j]=='1' )
                printf("1");
            else if( i==aa.s[0] && j==aa.s[1] )
                printf("S");
            else if( i==goal.s[0] && j==goal.s[1] )
                printf("G");
            else printf("-");
        }
        puts("");
    }
    getchar();
}

int main()
{
    while(scanf("%d %d",&n,&m))
    {
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                scanf(" %c",&start.ca[i][j]);
                if(start.ca[i][j]>'1')
                {
                    if(start.ca[i][j]=='2')
                    {
                        start.s[0] = i;
                        start.s[1] = j;
                    }
                    else
                    {
                        goal.s[0] = i;
                        goal.s[1] = j;
                    }
                    start.ca[i][j] = '0';
                }
            }
        start.m=0;
        q.resize(0);
        q.push_back(start);
        bfs_state tmp1,tmp2;
        bool no_ans = true;
        while(q.size()>0)
        {
            tmp1 = q.front();
            q.pop_front();
//            debug(tmp1);
            if( !in_range(tmp1) || tmp1.m>10 )
                continue;
            if( is_goal(tmp1) )
            {
                printf("%d\n",tmp1.m);
                no_ans = false;
                break;
            }
            for(int i=0;i<4;i++)
                q.push_back(move(tmp1,i));
        }
        if(no_ans)
            printf("%d\n",-1);
    }
}
