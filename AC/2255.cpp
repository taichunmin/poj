#include<iostream>
#include<cstdio>
using namespace std;

string str[3];

void fa( int ua, int ub, int uc, int ud, int ue, int uf )
{
//    printf("ab(%d,%d), cd(%d,%d), ef(%d,%d)\n",ua,ub,uc,ud,ue,uf);
    int strl = str[0].size();
    if( ua<0 || ua>=strl || ub<0 || ub>=strl || ua>ub )
        return;
    if( uc<0 || uc>=strl || ud<0 || ud>=strl || uc>ud )
        return;
    if( ue<0 || ue>=strl || uf<0 || uf>=strl || ue>uf )
        return;
    int mid = 0;
    while( str[0][ua] != str[1][uc+mid] )
        mid++;
    str[2][uf]=str[0][ua];
//    cout<<"str[2]="<<str[2]<<endl;
    fa( ua+1, ua+mid, uc, uc+mid-1, ue, ue+mid-1 );
    fa( ua+mid+1, ub, uc+mid+1, ud, ue+mid, uf-1 );
}

int main()
{
    while(cin>>str[0]>>str[1])
    {
        str[2].assign(str[0].size(),' ');
        fa( 0, str[0].size()-1, 0, str[0].size()-1, 0, str[0].size()-1 );
        cout<<str[2]<<endl;
    }
}
