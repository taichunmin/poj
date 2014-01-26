#include<iostream>
#include<deque>
#include<cstring>
#include<cstdio>
using namespace std;

int p[10000] = {2,3,5,7}, p_cnt =4;
bool b_prime[10][10][10][10], visit[10][10][10][10];

struct Node
{
    short d[4];
    int len;
};

bool is_prime( int ia )
{
    for(int i=0;i<p_cnt && p[i]*p[i]<=ia;i++)
        if( ia % p[i] == 0 )
            return false;
    return true;
}
void build_prime()
{
    for( int i=11, j=2; i<10000; i+=j, j=6-j )
        if( is_prime(i) )
            p[ p_cnt++ ] = i;
}
Node node_assign( int n, int len=0 )
{
    Node tmp = { {n/1000%10, n/100%10, n/10%10, n%10}, 0 };
    return tmp;
}
bool node_cmp( Node na, Node nb )
{
    return na.d[0]==nb.d[0] && na.d[1]==nb.d[1] && na.d[2]==nb.d[2] && na.d[3]==nb.d[3];
}
bool range_ok(int d, int left=0, int right=9)
{
    return (left<=d && d<=right);
}
bool range_ok(Node na)
{
    return range_ok(na.d[0],1) && range_ok(na.d[1]) && range_ok(na.d[2]) && range_ok(na.d[3]);
}
bool is_prime(Node na)
{
    return b_prime[na.d[0]][na.d[1]][na.d[2]][na.d[3]];
}
void debug(Node na)
{
    printf("(%d%d%d%d,%d) ",na.d[0],na.d[1],na.d[2],na.d[3],na.len);
    cin.get();
}
bool is_visit(Node na)
{
    return visit[na.d[0]][na.d[1]][na.d[2]][na.d[3]];
}
bool set_visit(Node na, bool ba=true)
{
    visit[na.d[0]][na.d[1]][na.d[2]][na.d[3]] = ba;
}

int main()
{
    build_prime();
    memset(b_prime,0,sizeof(b_prime));
    int ia=0,ib;
    while( ia<p_cnt && p[ia]<1000 )
        ia++;
    for(;ia<p_cnt && p[ia]<10000;ia++)
        b_prime[ p[ia]/1000%10 ][ p[ia]/100%10 ][ p[ia]/10%10 ][ p[ia]%10 ] = true;
    int T; cin>>T;
    while(T--)
    {
        memset(visit,0,sizeof(visit));
        cin>>ia>>ib;
        if(ia==ib)
        {
            cout<<0<<endl;
            continue;
        }
        if( !is_prime(ib) )
        {
            cout<<"Impossible"<<endl;
            continue;
        }
        bool no_answer = true;
        Node start = node_assign(ia), stop = node_assign(ib);
        deque<Node> q1;
        q1.push_back(start);
        while( q1.size()>0 )
        {
//            debug(q1.front());
            if( node_cmp( q1.front(), stop ) )
            {
                cout<< q1.front().len << endl;
                no_answer = false;
                break;
            }
            Node tmp = q1.front();
            tmp.len++;
            for(int i=0;i<4;i++)
            {
                for(tmp.d[i]=0;tmp.d[i]<=9;tmp.d[i]++)
                {
                    if( tmp.d[i]==q1.front().d[i] || !range_ok(tmp) || !is_prime(tmp) || is_visit(tmp) )
                        continue;
                    q1.push_back(tmp);
                    set_visit(tmp);
                }
                tmp.d[i] = q1.front().d[i];
            }
            q1.pop_front();
        }
        if(no_answer)
            cout<<"Impossible"<<endl;
    }
}
