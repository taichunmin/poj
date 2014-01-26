#include<iostream>
#include<cstdio>
using namespace std;

int arr1[10001] = {};

void fa( int x, int sign = 0 )
{
    if( x < 1 || x > 10000 || arr1[x]!=0 )
        return;
    arr1[x] = sign;
    int ia = x, ib = x;
    while( ib>0 )
    {
        ia += ib % 10;
        ib /= 10;
    }
    fa( ia, 1 );
}

int main()
{
    for(int i=1;i<=10000;i++)
        if(arr1[i]==0)
        {
            printf("%d\n",i);
            fa(i);
        }
}
