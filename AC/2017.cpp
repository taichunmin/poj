#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int T;
    while(cin>>T,T+1)
    {
        int ia,ib,time_last=0,miles=0;
        while(T--)
        {
            cin>>ia>>ib;
            miles += ia * (ib-time_last);
            time_last = ib;
        }
        cout<<miles<<" miles"<<endl;
    }
}
