#include<iostream>
#include<cstdio>
using namespace std;

int map1[19][19];
const int direction[4][2]={{-1,1},{0,1},{1,1},{1,0}};

bool inline in_map( int x, int y )
{
    return !(x < 0 || x > 18 || y < 0 || y > 18);
}

bool fb( int x, int y, int direc, int len=4 )
{
    int ax = x + direction[direc][0], ay = y + direction[direc][1];
    //printf("fb: x=%d, y=%d, ax=%d, ay=%d, len=%d\n",x,y,ax,ay,len);
    if(len==0)
        return !in_map(ax,ay) || map1[x][y] != map1[ax][ay];
    else
    {
        if( !in_map(ax,ay) || map1[x][y]!=map1[ax][ay] )
            return false;
        return fb(ax,ay,direc,len-1);
    }
}

bool fa( int x, int y )
{
    if( map1[x][y]==0 )
        return false;
    for(int i=0;i<4;i++)
    {
        int ax = x - direction[i][0], ay = y - direction[i][1];
        if( in_map(ax,ay) && map1[ax][ay] == map1[x][y] )
            continue;
        if( !fb( x,y,i ) )
            continue;
        return true;
    }
    return false;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        for(int i=0;i<19;i++)
            for(int j=0;j<19;j++)
                cin>>map1[i][j];
        bool ba = true;
        for(int i=0;i<19;i++)
            for(int j=0;j<19;j++)
                if( fa(i,j) )
                {
                    ba = false;
                    cout<<map1[i][j]<<endl<<i+1<<' '<<j+1<<endl;
                    break;
                }
        if(ba)
            cout<<0<<endl;
    }
}
