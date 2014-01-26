#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;

typedef vector<bool> poly_S;
poly_S poly[3];

void print_poly( poly_S pa )
{
    printf("%d",pa.size());
    for(int i=pa.size()-1;i>=0;i--)
        printf(" %d",(int)pa.at(i));
    puts("");
}

poly_S xor_poly( poly_S pa, poly_S pb )
{
    poly_S pc;
    pc.assign(MAX( pa.size(), pb.size() ),false);
    for(int i=0;i<pc.size();i++)
        pc.at(i) = ( i<pa.size()?pa.at(i):0 ) ^ ( i<pb.size()?pb.at(i):0 );
    return pc;
}

poly_S mul_poly( poly_S pa, poly_S pb )
{
    poly_S pc;
    pc.assign( pa.size()+pb.size()-1, false );
    for(int i=0;i<pa.size();i++)
        for(int j=0;j<pb.size();j++)
            pc.at(i+j) = pc.at(i+j) ^ (pa.at(i) * pb.at(j));
    return pc;
}

poly_S mod_poly( poly_S pa, poly_S pb )
{
    poly_S pc = pa;
    for( int i=pc.size()-pb.size(); i>=0; i-- )
    {
        if( pc.at(i+pb.size()-1) )
            for(int j=0;j<pb.size();j++)
                pc.at(i+j) = pc.at(i+j) ^ pb.at(j);
    }
    while( !pc.at(pc.size()-1) ) pc.pop_back();
    return pc;
}

int main()
{
    int T,ia,ib; cin>>T;
    while(T--)
    {
        for(int i=0;i<3;i++)
        {
            cin>>ia;
            poly[i].assign(ia,false);
            for(int j=ia-1;j>=0;j--)
            {
                cin>>ib;
                poly[i].at(j) = (bool)ib;
            }
        }
        print_poly(mod_poly(mul_poly(poly[0],poly[1]),poly[2]));
    }
}

/*
99
7 1 0 1 0 1 1 1
8 1 0 0 0 0 0 1 1
9 1 0 0 0 1 1 0 1 1

 */
