#include<iostream>
#include<deque>
using namespace std;

int main()
{
    int T,ia,ib,top;
    deque<int> arr1;
    cin>>T;
    while(T--)
    {
        cin>>ia;
        top = 0;
        for(int i=0;i<ia;i++)
        {
            cin>>ib;
            if(i) cout<<' ';
            if(ib==top)
                cout<<ib-arr1.back()+1;
            else
            {
                while(top<ib)
                    arr1.push_back(++top);
                cout<<1;
            }
            arr1.pop_back();
        }
        cout<<endl;
    }
}
