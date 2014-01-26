#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
    string str;
    bool ba = false;
    while(getline(cin,str),str != "ENDOFINPUT")
    {
        if( str == "END" )
            ba = false;
        if(ba)
        {
            for(int i=0;i<str.size();i++)
            {
                printf("%c", ( (str[i]<'A' || str[i]>'Z') ? str[i] : (char)((str[i]-44)%26+'A') ) );
            }
            puts("");
        }
        if( str == "START" )
            ba = true;
    }
}
