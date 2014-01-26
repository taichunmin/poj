#include<iostream>
#include<cstdio>
#include<map>
#include<deque>
using namespace std;

deque<int> q_new;
int m1[10000001];

int main()
{
    int ia,ib,ic,t0=0;
    char str[100];
    while(cin>>ia,ia)
    {
        printf("Scenario #%d\n",++t0);
        deque< deque<int> > q1;
        for(int i=0;i<ia;i++)
        {
            cin>>ib;
            while(ib--)
            {
                scanf("%d",&ic);
                m1[ic] = i;
            }
        }
        while(scanf(" %s", str), str[0]!='S')
        {
            if(str[0]=='D')
            {
                printf("%d\n",q1.front().front());
                q1.front().pop_front();
                if(q1.front().size()==0)
                    q1.pop_front();
            }
            else
            {
                cin>>ib;
                ic = m1[ib];
                deque< deque<int> >::iterator it=q1.begin();
                while( it<q1.end() && m1[it->front()] != ic )
                    it++;
                if(it==q1.end()){
                    q1.push_back(q_new);
                    it = q1.end()-1;
                }
                it->push_back(ib);
            }
        }
        cout<<endl;
    }
}
