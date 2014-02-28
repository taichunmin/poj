#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool r[10001];
int q[10001];

int main()
{
    int m,n,ia,r_cnt,p,ri;
    char ca;
    bool isfirst = true;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        getchar();
        memset(r,0,sizeof(r));
        memset(q,0,sizeof(q));
        r_cnt=ri=0;
        p=1;
        while(ca=getchar())
        {
            if(ca=='\n')
                break;
            ungetc(ca,stdin);
            scanf("%d",&ia);
            r[ia] = true;
            r_cnt=max(r_cnt,ia);
        }
//        puts("r:");
//        for(int i=1;i<=r_cnt;i++)
//            printf("%d ",r[i]);
//        puts("");
        if(isfirst) isfirst = false;
        else puts("");
        while(scanf(" %c",&ca),ca!='e')
        {
            switch(ca)
            {
            case 'a':
                scanf("%d",&ia);
                q[ia] ++;
                m = max(m,ia);
                n = min(n,ia);
//                printf("add %d",ia);
                break;
            case 'r':
                ri++;
//                printf("remove r[%d]=%d  ",ri,r[ri]);
                if(p==1)
                {
                    if( r[ri] )
                        printf("%d\n",(n<=m && q[n])?n:-1);
                    q[n]--;
                    while(n<=m && !q[n])n++;
                }
                else
                {
                    if( r[ri] )
                        printf("%d\n",(n<=m && q[m])?m:-1);
                    q[m]--;
                    while(m>=n && !q[m])m--;
                }
                break;
            case 'p':
                scanf("%d",&p);
                break;
            }
//            printf(", min=%d, max=%d\n",n,m);
        }
    }
}
