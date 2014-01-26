#include<iostream>
#include<cmath>
using namespace std;

int arr1[6], r2, r1, arr2[4]={0,5,3,1};

int main()
{
    int ans;
    while( true )
    {
        ans = 0;
        for(int i=0;i<6;i++)
        {
            cin>>arr1[i];
            ans+=arr1[i];
        }
        if(ans==0) break;
        ans = arr1[5] + arr1[4] + arr1[3] + ceil(arr1[2]/4.0);
//        cout<<"ans3 = "<<ans<<endl;
        r2 = arr1[3] * 5 + arr2[arr1[2]%4];
//        cout<<"r2 = "<<r2<<endl;
        if( r2 < arr1[1] )
            ans += ceil((arr1[1]-r2)/9.0);
//        cout<<"ans2 = "<<ans<<endl;
        r1 = ans*36 - ( arr1[5]*36 + arr1[4]*25 + arr1[3]*16 + arr1[2]*9 + arr1[1]*4 );
//        cout<<"r1 = "<<r1<<endl;
        if( r1 < arr1[0] )
            ans += ceil((arr1[0]-r1)/36.0);
//        cout<<"ans1 = "<<ans<<endl;
        cout<<ans<<endl;
    }
}
