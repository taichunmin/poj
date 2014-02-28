#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int arr1[100000][2];

int main()
{
    int m,ia,ib,len1=0;
    scanf("%d",&m);
    while(scanf("%d %d",&ia,&ib),ia+ib)
    {
        if(ia>ib)
            swap(ia,ib);
        if( ia<=0 && m<=ib )
        {
            arr1[len1][0] = ia;
            arr1[len1][1] = ib;
            len1++;
        }
    }
    if(len1)
    {
        printf("%d\n",len1);
        for(int i=0;i<len1;i++)
            printf("%d %d\n",arr1[i][0],arr1[i][1]);
    }
    else puts("No solution");
}
