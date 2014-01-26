#include<iostream>
#include<cstdio>
#include<cmath>
#define oo 2147483647
using namespace std;

int main()
{
    int T, ia, ib, min_ts;
    while(cin>>T,T)
    {
        min_ts = oo;
        while(T--)
        {
            cin>>ia>>ib;
            if(ib<0) continue;
            ia = ib + ceil( 16200.0 / ia );
            if(ia<min_ts)
                min_ts = ia;
        }
        cout<<min_ts<<endl;
    }
}

