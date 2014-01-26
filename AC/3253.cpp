#include<iostream>
#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;

int debug(deque<long long> &arr1)
{
    deque<long long>::iterator it = arr1.begin();
    while( it < arr1.end() )
    {
        printf("%lld ",*it);
        it++;
    }
    puts("");
}

long long read_ll()
{
    static char str[100];
    scanf("%s",str);

    long long la=0;
    for(int i=0;i<30 && str[i]!='\0';i++)
    {
        la*=10;
        la+=str[i]-'0';
    }
    return la;
}

int main()
{
    long long ia, ib, ans=0;
    ia = read_ll();
    deque<long long> arr1;
    while(ia--)
    {
        ib = read_ll();
        arr1.push_back(ib);
    }
    sort(arr1.begin(),arr1.end());
    while(arr1.size()>1)
    {
        ia = arr1.front(); arr1.pop_front();
        ia += arr1.front(); arr1.pop_front();
        ans += ia;
        deque<long long>::iterator it = arr1.begin();
        while( it<arr1.end() && ia>*it )
            it++;
        arr1.insert(it,ia);
//        debug(arr1);
    }
    printf("%lld\n",ans);
}
