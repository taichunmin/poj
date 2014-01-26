#include<iostream>
#include<cstdio>
#include<sstream>
using namespace std;

int arr1[15];

int main()
{
    int ia,cnt1=0,ans=0;
    while(cin>>ia,ia+1)
    {
        if(ia==0)
        {
            cout<<ans<<endl;
            cnt1=ans=0;
            continue;
        }
        arr1[cnt1++] = ia;
        for(int i=0;i<cnt1-1;i++)
        {
            if( ia%2==0 && arr1[i] == ia/2 )
                ans++;
            if( arr1[i] == ia*2 )
                ans++;
        }
    }
}
