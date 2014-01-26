#include<iostream>
#include<cmath>
#define PI 2.0 * acos(0.0)
using namespace std;

int main()
{
    int ta;
    cin>>ta;
    double da,db;
    for(int t1=0;t1<ta;t1++)
    {
        cin>>da>>db;
        cout<<"Property "<<t1+1<<": This property will begin eroding in year "<<ceil( PI * (da*da + db*db) / 100.0 )<<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
}
