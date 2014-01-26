#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char w[10001], t[1000001];
int kmp_arr[10001];

void build_kmp()
{
    kmp_arr[0] = -1;
    int strl = strlen(w), k=-1;
    for(int i=1;i<=strl;i++)
    {
        while( k >= 0 && w[k]!=w[i-1] )
            k = kmp_arr[k];
        kmp_arr[i] = ++k;
    }
}

void kmp_debug()
{
    cout<<"kmp:"<<endl;
    for(int i=0;i<=strlen(w);i++)
        cout<<kmp_arr[i]<<' ';
    cout<<endl;
}

int main()
{
    int T;
    cin>>T;cin.get();
    while(T--)
    {
        gets(w);
        gets(t);
        build_kmp();
//        kmp_debug();
        int ia=0,ib=0,lenw = strlen(w), lent=strlen(t), cnt = 0;
        while( ia<lent && ib<lenw )
        {
//            printf("ia=(%d,%c), ib=(%d,%c)\n",ia,t[ia],ib,t[ib]);
            if( ib == -1 || t[ia]==w[ib] )
            {
                ia++; ib++;
            }
            else ib = kmp_arr[ib];
            if(ib>lenw-1)
            {
                cnt++;
                ib = kmp_arr[ib];
            }
        }
        printf("%d\n",cnt);
    }
}
