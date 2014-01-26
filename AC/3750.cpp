#include<iostream>
#include<vector>
using namespace std;

vector<string> arr;

int main()
{
    int ia,ib,ic;
    arr.reserve(64);
    char ca;
    string str;
    cin>>ia;
    for(int i=0;i<ia;i++)
    {
        cin>>str;
        arr.push_back(str);
    }
    cin>>ib>>ca>>ic;
    ib = (ib-1+arr.size())%arr.size();
    while(arr.size()>0)
    {
        ib=(ib+ic-1)%arr.size();
        cout<<arr.at(ib)<<endl;
        arr.erase(arr.begin()+ib);
    }
}
