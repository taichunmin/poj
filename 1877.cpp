#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int arr1[1000];

int cmp(const void *aa, const void *bb)
{
    return *(int*)aa - *(int*)bb;
}
int dcmp(double da,double db)
{
    const double exp = 1e-5;
    return (da-db<-exp) ? -1 : (da-db>exp);
}
void debug(int n)
{
    for(int i=0;i<n+1;i++)
        printf("%d ",arr1[i]);
    puts("");
}

int main()
{
    int m,n,t0=0;
    double flood;
    while(scanf("%d %d",&m,&n),m+n)
    {
        printf("Region %d\n",++t0);
        n *= m;
        for(int i=0;i<n;i++)
            scanf("%d",&arr1[i]);
        arr1[n]=2147483647;
        qsort(arr1,n+1,sizeof(int),cmp);
//        debug(n);
        cin>>flood;
        flood /= 100;
        if(dcmp(flood,0)<=0)
        {
            printf("Water level is %.2f meters.\n",.0);
            printf("%.2f percent of the region is under water.\n\n",.0);
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(arr1[i-1]==arr1[i])
                continue;
            m = i-1;
            while(m>=0 && arr1[m]==arr1[i])
                m--;
            if(m<0)
                continue;
//            printf("flood=%.2f, i=%d, m=%d, (arr1[i]-arr1[m])*i=%.2f\n",flood,i,m,(arr1[i]-arr1[m]+.0)*i);
            if( dcmp( (arr1[i]-arr1[m]+.0)*i, flood )>=0 )
            {
                printf("Water level is %.2f meters.\n",arr1[m]+flood/i);
                printf("%.2f percent of the region is under water.\n\n",(i+.0)/n*100 );
                break;
            }
            else flood -= (arr1[i]-arr1[m]+.0)*i;
        }
    }
}
