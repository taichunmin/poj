#include<iostream>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;

struct People
{
    int t;
}p[1000];

int people_cmp(const void *aa, const void* bb)
{
    static People *a, *b;
    a = (People*)aa; b = (People*)bb;
    return a->t - b->t;
}

int main()
{
    int ia,people_cnt,ans;
    cin>>ia;
    people_cnt=ia;
    ans=0;
    for(int i=0;i<ia;i++)
        cin>>p[i].t;
    qsort(p,ia,sizeof(People),people_cmp);
    ostringstream sout;
    while( people_cnt > 3 )
    {
        if( (2*p[0].t + p[people_cnt-2].t + p[people_cnt-1].t) < ( p[0].t + 2*p[1].t + p[people_cnt-1].t ) )
        {
            sout<<p[0].t<<' '<<p[people_cnt-1].t<<endl;
            sout<<p[0].t<<endl;
            sout<<p[0].t<<' '<<p[people_cnt-2].t<<endl;
            sout<<p[0].t<<endl;
            ans += 2*p[0].t + p[people_cnt-2].t + p[people_cnt-1].t;
            people_cnt-=2;
        }
        else
        {
            sout<<p[0].t<<' '<<p[1].t<<endl;
            sout<<p[0].t<<endl;
            sout<<p[people_cnt-2].t<<' '<<p[people_cnt-1].t<<endl;
            sout<<p[1].t<<endl;
            ans += p[0].t + 2*p[1].t + p[people_cnt-1].t;
            people_cnt-=2;
        }
    }
    if(people_cnt==2)
    {
        sout<<p[0].t<<' '<<p[1].t<<endl;
        ans += p[1].t;
    }
    else if(people_cnt == 3)
    {
        sout<<p[0].t<<' '<<p[2].t<<endl;
        sout<<p[0].t<<endl;
        sout<<p[0].t<<' '<<p[1].t<<endl;
        ans += p[0].t+p[1].t+p[2].t;
    }
    else if(people_cnt==1)
    {
        sout<<p[0].t<<endl;
        ans += p[0].t;
    }
    cout<<ans<<endl;
    cout<<sout.str();
}
