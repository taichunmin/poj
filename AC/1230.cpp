#include<iostream>
#include<cstdio>
#include<algorithm>
#define oo 2147483647
using namespace std;

struct Wall
{
    int p[3], del; // j, left, right
}wall[100];

bool inline in_range(Wall wa, int col)
{
    return wa.del==0 && wa.p[1] <= col && col <= wa.p[2];
}

void debug()
{

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int ia,ib,col_max=0,wall_cnt,ans=0;
        cin>>ia>>ib;
        for(int i=0;i<ia;i++)
        {
            cin>>wall[i].p[1]>>wall[i].p[0]>>wall[i].p[2]>>wall[i].p[0];
            wall[i].del = 0;
            if( wall[i].p[1]>wall[i].p[2] )
                swap(wall[i].p[1],wall[i].p[2]);
            col_max = max(col_max,wall[i].p[2]);
        }
        col_max++;
        for(int i=0;i<col_max;i++)
        {
            wall_cnt=0;
            for(int j=0;j<ia;j++)
                if( in_range(wall[j],i) )
                    wall_cnt++;
//            printf("col=%d wall_cnt=%d\n",i,wall_cnt);
            while( wall_cnt > ib )
            {
                int del=-1;
                for(int j=0;j<ia;j++)
                    if(in_range(wall[j],i) && (del<0 || wall[j].p[2]>wall[del].p[2]))
                        del = j;
//                printf("del %d\n",del);
                wall[del].del = 1;
                wall_cnt--;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}
