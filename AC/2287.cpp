#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int ans;
deque<int> qa, qb;

int fa( bool ba, bool bb )
{
    deque<int>::iterator it = ba? qa.begin() : qa.end()-1;
    deque<int>::iterator jt = bb? qb.begin() : qb.end()-1;
    if( *it < *jt )
        ans-=200;
    else if( *it > *jt )
        ans+=200;
    qa.erase(it);
    qb.erase(jt);
}

int main()
{
    int ia;
    while(cin>>ia,ia)
    {
        int ib;
        qa.clear(); qb.clear();
        for(int i=0;i<ia;i++)
        {
            cin>>ib;
            qa.push_back(ib);
        }
        for(int i=0;i<ia;i++)
        {
            cin>>ib;
            qb.push_back(ib);
        }
        sort(qa.rbegin(),qa.rend());
        sort(qb.rbegin(),qb.rend());
        ans=0;
        while( qa.size()>0 )
        {
            if( qa.back()>qb.back() )
                fa( false, false );
            else if( qa.front()>qb.front() )
                fa( true, true );
//            else if( qa.back()<qb.back() )
//                fa( false, true );
//            else if( qa.front()<qb.front() )
//                fa( true, false );
            else fa( false, true );
        }
        cout<<ans<<endl;
    }
}
