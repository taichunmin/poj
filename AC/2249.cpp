#include<iostream>
using namespace std;

int arr1[10000000],top=0;
int gcd( int a, int b )
{
    if(b<1) return a;
    return gcd(b,a%b);
}

void debug()
{
    cout<<"top: ";
    for(int i=0;i<top;i++)
        cout<<arr1[i]<<" ";
    cout<<endl;
}

int main()
{
    long long n,k,ans;
    while(cin>>n>>k,n+k)
    {
        top=0;
        if(k>=n/2)
            k = n-k;
        for(int i=0;i<k;i++)
            arr1[top++] = n-i;
        for(int i=2;i<=k;i++)
        {
            int ia = i, ib=0;
            while(ia>1 && ib<top)
            {
                int tmp = gcd( arr1[ib], ia );
//                cout<<"gcd = "<<tmp<<endl;
                if( tmp > 1 )
                {
                    ia /= tmp;
                    arr1[ib]/=tmp;
                }
                if(arr1[ib]<=1)
                {
                    arr1[ib]=arr1[top-1];
                    top--;
                }
                else ib++;
            }
//            debug();
        }
        ans = 1;
        for(int i=0;i<top;i++)
            ans *= arr1[i];
        cout<<ans<<endl;
    }
}

/*#include<iostream>
#include<map>
using namespace std;

typedef long long int uint;

map< uint, map<uint,uint> > combi;

uint C( uint n, uint k )
{
    if( n<1 || k<0 || k>n )
        return 0;
    if( combi[n][k] == 0 )
    {
        if(k==0 || n==k)
            combi[n][k]=1;
        else combi[n][k] = C( n-1, k ) + C( n-1, k-1 );
    }
    return combi[n][k];
}

int main()
{
    uint n,k;
    while(cin>>n>>k,n+k)
        cout<<C(n,k)<<endl;
}
*/
