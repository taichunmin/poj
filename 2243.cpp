#include<iostream>
#include<algorithm>
#include<cstdio>
#define oo 100000000
using namespace std;

int d[8][8][8][8], dir[][2] = { {2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};

void debug_a(int ix, int iy)
{
    for(int jx=0;jx<8;jx++)
        for(int jy=0;jy<8;jy++)
            printf("%d%c",d[ix][iy][jx][jy],(jy==7?'\n':' ') );
    puts("");
}

int main()
{
    for(int ix=0;ix<8;ix++)
        for(int iy=0;iy<8;iy++)
        {
            for(int jx=0;jx<8;jx++)
                for(int jy=0;jy<8;jy++)
                    d[ix][iy][jx][jy] = (ix==jx && iy==jy)?0:oo;
            for(int i=0;i<8;i++)
                if( 0<=ix+dir[i][0] && ix+dir[i][0]<8 && 0<=iy+dir[i][1] && iy+dir[i][1]<8 )
                    d[ix][iy][ ix+dir[i][0] ][ iy+dir[i][1] ] = 1;
//            for(int jx=0;jx<8;jx++)
//                for(int jy=0;jy<8;jy++)
//                    printf("%c%c",d[ix][iy][jx][jy]<2?d[ix][iy][jx][jy]+'0':'-',jy==7?'\n':' ');
//            puts("");
//            getchar();
        }
    for(int kx=0;kx<8;kx++)
        for(int ky=0;ky<8;ky++)
            for(int ix=0;ix<8;ix++)
                for(int iy=0;iy<8;iy++)
                    for(int jx=0;jx<8;jx++)
                        for(int jy=0;jy<8;jy++)
                            d[ix][iy][jx][jy] = min( d[ix][iy][jx][jy], d[ix][iy][kx][ky]+d[kx][ky][jx][jy] );
//    debug_a(0,0);
    char ca[4];
    while(scanf(" %c%c %c%c",&ca[0],&ca[1],&ca[2],&ca[3])!=EOF)
    {
        printf("To get from %c%c to %c%c takes %d knight moves.\n",
            ca[0],ca[1],ca[2],ca[3],d[ca[0]-'a'][ca[1]-'1'][ca[2]-'a'][ca[3]-'1']);
    }
}
