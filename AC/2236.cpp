#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,d;
int coor[2000][2],s[2000];
bool mp[2000][2000],v[2000];

void debug()
{
    for(int i=0;i<n;i++)
        printf("%d ",s[i]);
    puts("");
    getchar();
}

int find(int ia)
{
    if(s[ia]==-1 || s[ia]==ia)
        return ia;
    return s[ia] = find(s[ia]);
}

int main()
{
    scanf("%d %d",&n,&d);
    d*=d;
    for(int i=0;i<n;i++)
        scanf("%d %d",&coor[i][0],&coor[i][1]);
    memset(mp,0,sizeof(mp));
    memset(s,-1,sizeof(s));
    memset(v,0,sizeof(v));
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            mp[i][j] = mp[j][i] = (coor[i][0]-coor[j][0])*(coor[i][0]-coor[j][0]) + (coor[i][1]-coor[j][1])*(coor[i][1]-coor[j][1]) <= d;
    char ca;
    while(scanf(" %c",&ca)!=EOF)
    {
        int ia,ib;
        switch(ca)
        {
        case 'O':
            scanf("%d",&ia);
            ia--;
            v[ia]=true;
            for(int i=0;i<n;i++)
                if(v[i] && mp[ia][i])
                    s[find(ia)] = find(i);
//            debug();
            break;
        case 'S':
            scanf("%d %d",&ia,&ib);
            ia--; ib--;
//            printf("%d %d\n",ia,ib);
            if(find(ia)==find(ib))
                puts("SUCCESS");
            else puts("FAIL");
            break;
        }
    }
}
