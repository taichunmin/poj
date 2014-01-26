#include<iostream>
using namespace std;

int arr1[10001] = {};
int p[10000] = {2,3,5,7}, p_cnt =4;

bool is_prime( int ia )
{
    for(int i=0;i<p_cnt && p[i]*p[i]<=ia;i++)
        if( ia % p[i] == 0 )
            return false;
    return true;
}

void build_prime()
{
    for( int i=11, j=2; i<10000; i+=j, j=6-j )
        if( is_prime(i) )
            p[ p_cnt++ ] = i;
}

int main()
{
    build_prime();
    for(int i=0;i<p_cnt;i++)
    {
        int sum = p[i];
        arr1[ sum ]++;
        for(int j=i+1;j<p_cnt;j++)
        {
            sum += p[j];
            if(sum>10000)break;
            arr1[ sum ]++;
        }
    }
    int ia;
    while(cin>>ia,ia)
        cout<<arr1[ia]<<endl;
}
