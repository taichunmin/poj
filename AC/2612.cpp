#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char ca[2][100][101];
int mp[100][100],dir[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};

int main()
{
    int m;
    scanf("%d",&m);
    getchar();
    for(int i=0;i<2;i++)
        for(int j=0;j<m;j++)
            gets(ca[i][j]);
    memset(mp,0,sizeof(mp));
    bool touched = false;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            if( ca[0][i][j]=='*' )
            {
                for(int k=0;k<8;k++)
                    mp[i+dir[k][0]][j+dir[k][1]]++;
                if(ca[1][i][j]=='x')
                    touched = true;
            }
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
        {
            if(touched && ca[0][i][j]=='*')
                printf("*");
            else if(ca[1][i][j]=='x')
                printf("%c",mp[i][j]+'0');
            else printf(".");
            if(j==m-1)puts("");
        }
}
