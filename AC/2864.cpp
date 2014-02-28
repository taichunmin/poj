#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int arr1[101];

int main()
{
    int n,m,ia;
    while(scanf("%d %d",&m,&n),n+m)
    {
        memset(arr1,0,sizeof(arr1));
        for(int j=0;j<n;j++)
            for(int i=0;i<m;i++)
            {
                scanf("%d",&ia);
                arr1[i]+=ia;
            }
        bool ba = false;
        for(int i=0;i<m;i++)
            if(arr1[i]==n)
                ba = true;
        if(ba) puts("yes");
        else puts("no");
    }
}
