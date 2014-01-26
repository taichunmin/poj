#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int arr1[1000001];
int p[100000] = {2,3,5,7}, p_cnt =4;

bool is_prime( int ia )
{
    for(int i=0;i<p_cnt && p[i]*p[i]<=ia;i++)
        if( ia % p[i] == 0 )
            return false;
    return true;
}

void build_prime()
{
    for( int i=11, j=2; i<1000000; i+=j, j=6-j )
        if( is_prime(i) )
            p[ p_cnt++ ] = i;
}

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
bool bsearch_prime(int ia)
{
    return bsearch(&ia, p, p_cnt, sizeof (int), cmp)!=NULL;
}
int fa(int ia)
{
    if( arr1[ia] == -1 )
    {
        int ib = ia/2;
        bool ba = true;
        for(int i=0;i<p_cnt && p[i]<=ib;i++)
            if( bsearch_prime(ia-p[i]) )
            {
                ba = false;
                arr1[ia] = p[i];
                break;
            }
        if(ba) arr1[ia]=0;
    }
    return arr1[ia];
}

int main()
{
    memset(&arr1,-1,sizeof(arr1));
    build_prime();

    int ia;
    while(cin>>ia,ia)
    {
        int ib = fa(ia);
        if(ib==0) puts("Goldbach's conjecture is wrong.");
        else printf("%d = %d + %d\n", ia, ib, ia-ib);
    }
}
