#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int ia;
    while(cin>>ia)
    {
        int ib=0,ic;
        for(int i=0;i<ia;i++)
        {
            cin>>ic;
            ib ^= ic;
        }
        if(ib)
            puts("Yes");
        else puts("No");
    }
}
