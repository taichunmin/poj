#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    float dsum = 0, da;
    for(int i=0;i<12;i++)
    {
        cin>>da;
        dsum += da;
    }
    cout<<"$"<<dsum/12<<endl;
}
