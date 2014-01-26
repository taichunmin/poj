#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

int cnt[10];
bool prior_check( int n )
{
    if(n<0)n=-n;
    for(n++;n<10;n++)
        if( cnt[n]!=0 )
            return false;
    return true;
}
void debug()
{
    cout<<"cnt: ";
    for(int i=1;i<10;i++)
        cout<<cnt[i]<<' ';
    cout<<endl;
}

int main()
{
    int T,ia,ib,ic;
    cin>>T;
    while(T--)
    {
        cin>>ia>>ib;
        deque<int> arr1;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<ia;i++)
        {
            cin>>ic;
            arr1.push_back(i==ib?-ic:ic);
            cnt[ic]++;
        }
        while(arr1.size()>0)
        {
            int tmp = arr1.front();
            bool ba = false;
            if(!prior_check(tmp))
                arr1.push_back( tmp );
            else cnt[ tmp<0?-tmp:tmp ]--,ba=true;
            arr1.pop_front();
            if(ba && tmp<0)
                break;
        }
        cout<<ia-arr1.size()<<endl;
    }
}
