#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int ia,ib;
string m[20];
int v[20][20];
int arr1[4][2] = {1,0,-1,0,0,1,0,-1};

void debug()
{
    for(int i=0;i<ia;i++)
    {
        for(int j=0;j<ib;j++)
            cout<<v[i][j]<<' ';
        cout<<endl;
    }
    cin.get();
}

int fa(int x, int y)
{
    if( x<0 || ia<=x || y<0 || ib<=y || m[x][y]=='#' || v[x][y]==1 )
        return 0;
    v[x][y]=1;
    int step = 1;
    for(int i=0;i<4;i++)
        step += fa( x+arr1[i][0], y+arr1[i][1] );
    return step;
}

int main()
{
    while(cin>>ib>>ia,ia+ib)
    {
        cin.get();
        for(int i=0;i<ia;i++)
            getline(cin,m[i]);
        memset(v,0,sizeof(v));
        for(int i=0;i<ia;i++)
            for(int j=0;j<ib;j++)
                if( m[i][j]=='@' )
                {
                    cout<<fa(i,j)<<endl;
                    i=ia; j=ib;
                }
    }
}
