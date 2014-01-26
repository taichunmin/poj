#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int arr1[100];

int cmp( const void* aa, const void *bb )
{
    return *(int*)bb - *(int*)aa;
}

int main()
{
    int ia;
    cin>>ia;
    for(int i=0;i<ia;i++)
        cin>>arr1[i];
    qsort(arr1,ia,sizeof(int),cmp);
    double da = arr1[0];
    for(int i=1;i<ia;i++)
    {
        da = 2 * sqrt(da * arr1[i]);
    }
    printf("%.3f\n",da);
}
