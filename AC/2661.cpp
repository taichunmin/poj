#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int arr1[24];

int main()
{
    int ia=0,ib=0;
    double log_sum=0;
    for(int i=0;i<=23;i++)
    {
        ia = 1<<i;
        while(log_sum<ia)
        {
            log_sum += log2(++ib);
//            printf("i=%d, ia=%d, ib=%d, log_sum=%.2f\n",i,ia,ib,log_sum);
//            getchar();
        }
        arr1[i]=ib-1;
    }
//    for(int i=0;i<=23;i++)
//        printf("%d ",arr1[i]);
//    puts("");

    while(cin>>ia,ia)
    {
        printf("%d\n",arr1[(int)floor((ia-1960)/10.0)+2]);
    }
}
