#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

char m[729][730];
int arr[]={0,1,3,9,27,81,243,729},ia;
void fa()
{
    for( int i=0; i<arr[ia] ; i++ )
    {
        m[i][ arr[ia] ] = 0;
        puts(m[i]);
    }
    puts("-");
}
void dp(int x, int y, int s)
{
    if( x<0 || x>=arr[ia] || y<0 || y>=arr[ia] )
        return;
    if( s == 1 )
    {
        m[ x ][ y ] = 'X';
        return;
    }
    const int dir[5][2] = { {0,0}, {0,2}, {1,1}, {2,0}, {2,2} };
    for(int i=0;i<5;i++)
        dp( x + arr[s-1]*dir[i][0], y + arr[s-1]*dir[i][1], s-1 );
}
int main()
{
    while(cin>>ia,ia>0)
    {
        memset(m,' ',sizeof(m));
        dp(0,0,ia);
        fa();
    }
}
