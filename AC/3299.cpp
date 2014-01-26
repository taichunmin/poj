#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double toT( double d, double h )
{
    return h - 0.5555 * (( 6.11 * exp(5417.7530 * ( 1/273.16 - 1/(d+273.16)) )) - 10.0);
}
double toD( double h, double t )
{
    return 1/(1/273.16-log(((h - t)/0.5555+10.0)/6.11)/5417.7530)-273.16;
}
double toH( double d, double t )
{
    return t + 0.5555 * (( 6.11 * exp(5417.7530 * ( 1/273.16 - 1/(d+273.16)) )) - 10.0);
}

int main()
{
    double da, db, arr1[3];
    // T, D, H
    char ca, cb;
    while( cin>>ca )
    {
        if(ca=='E')break;
        cin>>da>>cb>>db;
        if( ca > cb )
        {
            char tmpc = ca;
            ca = cb;
            cb = tmpc;
            double tmpd = da;
            da = db;
            db = tmpd;
        }
        if( ca == 'D' && cb == 'H' )
        {
            printf("T %.1f D %.1f H %.1f\n",(float)toT(da,db),(float)da,(float)db);
        }
        if( ca == 'D' && cb == 'T' )
        {
            printf("T %.1f D %.1f H %.1f\n",(float)db,(float)da,(float)toH(da,db));
        }
        if( ca == 'H' && cb == 'T' )
        {
            printf("T %.1f D %.1f H %.1f\n",(float)db,(float)toD(da,db),(float)da);
        }
    }
}
