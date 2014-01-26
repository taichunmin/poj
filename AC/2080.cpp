#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int md[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
char dayofweek[][20] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

bool leap(int y)
{
    return y%4==0 && y%100!=0 || y%400==0;
}

int main()
{
    int ia;
    while(cin>>ia,ia>=0)
    {
        int y=2000, m=1, d, w=(ia+6)%7, ib;
        while( ib=(leap(y)?366:365), ia>=ib )
        {
            y++;
            ia-=ib;
        }
        md[2] = 28 + leap(y);
        for(int i=1;i<=12 && ia>=md[i];i++)
        {
            m++;
            ia-=md[i];
        }
        d = ia+1;
        printf("%04d-%02d-%02d %s\n",y,m,d,dayofweek[w]);
    }
}
