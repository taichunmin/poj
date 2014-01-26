#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string haab[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
string tzolkin[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int haab2day(int d, string str_m, int y)
{
    int m;
    for(m=0;m<19;m++)
        if(haab[m]==str_m)
            break;
    return y*365 + m*20 + d;
}

int main()
{
    int T,ia,ib;
    char garbage;
    string str;
    cin>>T;
    cout<<T<<endl;
    while(T--)
    {
        cin>>ia>>garbage>>str>>ib;
        ia = haab2day( ia, str, ib );
        cout<<ia%13+1<<" "<<tzolkin[(ia%20+20)%20]<<" "<<ia/260<<endl;
    }
}
