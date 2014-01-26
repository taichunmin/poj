#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int gang[200002];
int ia;

int find_gang( int ia )
{
    if(gang[ia]<0)
        return ia;
    return gang[ia] = find_gang(gang[ia]);
}

int main()
{
    int T, t0;
    cin>>T;
    while(T--)
    {
        cin>>ia>>t0;
        char ca;
        int ic,id;
        memset(gang,-1,sizeof(gang));
        while(t0--)
        {
            cin>>ca>>ic>>id;
            if(ca=='D')
            {
                gang[ find_gang(ic) ] = find_gang( id+ia );
                gang[ find_gang(id) ] = find_gang( ic+ia );
            }
            else
            {
                if( find_gang(ic) == find_gang(id) )
                    puts("In the same gang.");
                else if( find_gang(ic) == find_gang(id+ia) )
                    puts("In different gangs.");
                else puts("Not sure yet.");
            }
        }
    }
}
