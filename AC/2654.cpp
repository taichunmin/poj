#include<cstring>
#include<cstdio>
using namespace std;

int arr1[101][2];
bool is_winner(char sa, char sb)
{
    if( sa=='s' && sb=='p' )
        return true;
    if( sa=='p' && sb=='r' )
        return true;
    if( sa=='r' && sb=='s' )
        return true;
    return false;
}

int main()
{
    int ia,ib,ic,pa,pb;
    char ca[10],cb[10];
    bool isfirst = true;
    while(scanf("%d",&ia),ia)
    {
        scanf("%d",&ib);
        ic = ib*ia*(ia-1)/2;
        memset(arr1,0,sizeof(arr1));
        for(int i=0;i<ic;i++)
        {
            scanf("%d %s %d %s",&pa,ca,&pb,cb);
            if(ca[0]!=cb[0])
            {
                arr1[pa][0]++;
                arr1[pa][1] += is_winner(ca[0],cb[0]);
                arr1[pb][0]++;
                arr1[pb][1] += is_winner(cb[0],ca[0]);
            }
        }
        if(isfirst) isfirst = false;
        else puts("");
        for(int i=1;i<=ia;i++)
        {
            if(arr1[i][0]!=0)
                printf("%.3f\n",(double)arr1[i][1]/arr1[i][0]);
            else puts("-");
        }
    }
}
