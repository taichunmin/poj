#include<iostream>
#include<cstdio>
#include<algorithm>
#define oo 2147483647
using namespace std;

struct Stick
{
    int d[2],u;
}s[5000];

int stick_cmp(const void* aa, const void* bb)
{
    static Stick *a, *b;
    a = (Stick *)aa; b = (Stick *)bb;
    if( a->d[0] != b->d[0] )
        return a->d[0] - b->d[0];
    return a->d[1] - b->d[1];
}

void debug(int ia)
{
    for(int i=0;i<ia;i++)
        cout<<s[i].d[0]<<' '<<s[i].d[1]<<' ';
    cout<<endl;
}

int main()
{
    int T; cin>>T;
    while(T--)
    {
        int ia; cin>>ia;
        for(int i=0;i<ia;i++)
        {
            cin>>s[i].d[0]>>s[i].d[1];
            s[i].u=0;
        }
        qsort(s,ia,sizeof(Stick),stick_cmp);
//        debug(ia);
        int stick_cnt = ia, ans=0;
        while( stick_cnt > 0 )
        {
            int ib = -oo,ic = -oo;
            ans++;
            for(int i=0;i<ia;i++)
                if( s[i].u==0 && s[i].d[0]>=ib && s[i].d[1]>=ic )
                {
                    ib = s[i].d[0];
                    ic = s[i].d[1];
                    s[i].u = 1;
                    stick_cnt--;
//                    cout<<"del "<<i<<endl;
                }
//            cout<<"stick_cnt="<<stick_cnt<<endl;
        }
        cout<<ans<<endl;
    }
}
