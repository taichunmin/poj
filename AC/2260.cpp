#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int arr1[2][100];

int main()
{
    int ia, ib, ans[2], odd[2];
    while(scanf("%d",&ia),ia)
    {
        memset(arr1,0,sizeof(arr1));
        odd[0] = odd[1] = 0;
        for(int i=0;i<ia;i++)
            for(int j=0;j<ia;j++)
            {
                cin>>ib;
                arr1[0][i]+=ib;
                arr1[1][j]+=ib;
            }
        for(int i=0;i<2;i++)
            for(int j=0;j<ia;j++)
                if( arr1[i][j]&1 )
                {
                    odd[i]++;
                    ans[i]=j;
                }
//        printf("odd=(%d,%d)\n",odd[0],odd[1]);
        if( odd[0]+odd[1] == 0 )
            puts("OK");
        else if( odd[0]==1 && odd[1]==1 )
            printf("Change bit (%d,%d)\n",ans[0]+1,ans[1]+1);
        else puts("Corrupt");
    }
}
