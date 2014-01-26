#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int find_int;
int p[200000] = {2,3,5,7}, p_cnt =4;

bool is_prime( int ia )
{
    for(int i=0;i<p_cnt && p[i]*p[i]<=ia;i++)
        if( ia % p[i] == 0 )
            return false;
    return true;
}

void build_prime()
{
    for( int i=11, j=2; i<=1300000; i+=j, j=6-j )
        if( is_prime(i) )
            p[ p_cnt++ ] = i;
}

int cmp( const void * aa, const void * bb )
{
    int a = *(int*)aa;  // "aa" is always the value you are looking for.
    int *ptr = (int*)bb ;
    return ( a < ptr[0] ) ? -1 : ( a >= ptr[1] );
}

int main()
{
    build_prime();
    while(cin>>find_int,find_int)
    {
        int *ptr = (int*)bsearch( &find_int, p, p_cnt-1, sizeof(int), cmp );
        if(ptr[0]==find_int)
            cout<<0<<endl;
        else cout<<ptr[1]-ptr[0]<<endl;
    }
}
