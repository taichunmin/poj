#include<iostream>
using namespace std;

double arr1[1000000] = {.5};

int dzero( double da )
{
    const double delta = 1e-8;
    return ( da < -delta ) ? -1 : ( da > delta );
}

int main()
{
    int cnt1=1;
    while( dzero( arr1[cnt1-1] - 5.20 ) <= 0 )
    {
        arr1[cnt1] = arr1[cnt1-1] + 1.0/(cnt1+2);
        cnt1++;
    }
    double da;
    while(cin>>da,dzero(da))
    {
        for(int i=0;i<cnt1;i++)
            if( dzero(arr1[i]-da) > 0 )
            {
                cout<<i+1<<" card(s)"<<endl;
                break;
            }
    }
}
