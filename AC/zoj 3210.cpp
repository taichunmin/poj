#include<iostream>
using namespace std;

int arr1[2][100];
string str[]={"neither", "stack", "queue", "both"};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int ia,ib=0;
        cin>>ia;
        for(int i=0;i<ia;i++)
            cin>>arr1[0][i];
        for(int i=0;i<ia;i++)
            cin>>arr1[1][i];
        ib|=2;
        for(int i=0;i<ia && (ib&2);i++)
            if( arr1[0][i] != arr1[1][i] )
                ib ^= 2;
        ib|=1;
        for(int i=0;i<ia && (ib&1);i++)
            if( arr1[0][i] != arr1[1][ia-i-1] )
                ib ^= 1;
        cout<<str[ib]<<endl;
    }
}
