#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char str[1000];
    int ia,ans=0;
    char ca;
    while(scanf("%s",str),str[0]!='#')
    {
        if(strlen(str)==1 && str[0]=='0')
        {
            cout<<ans<<endl;
            ans=0;
            continue;
        }
        scanf(" %s %d %c",str,&ia,&ca);
        if(ca=='F')
            ans += ia*2;
        else if(ca=='B')
            ans += ia*1.5 + ia%2;
        else ans += ia<1 ? 0 : ( ia>500 ? ia : 500 );
    }
}
