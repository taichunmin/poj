#include<iostream>
#include<cstring>
using namespace std;

char ca[10][61];
string ans;
int ia;

bool fa(int left, int right)
{
    for(int i=1;i<ia;i++)
    {
        bool no_match = true;
        for(int j=0; j<60 && no_match;j++)
        {
            bool ba=true;
            for(int k=0;k<right-left+1;k++)
                if( ca[i][j+k] != ca[0][k+left] )
                {
                    ba = false;
                    break;
                }
            if( ba ) no_match = false;
        }
        if(no_match) return false;
    }
    return true;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>ia;
        for(int i=0;i<ia;i++)
            cin>>ca[i];
        ans="";
        for(int i=0;i<60;i++)
            for(int j=i+2;j<60;j++)
                if( fa(i,j) && j-i+1>=ans.size() )
                {
                    string str;
                    str.assign(ca[0],i,j-i+1);
                    if(j-i+1>ans.size() || ans>str)
                        ans=str;
                }
        if(ans.size()<3)
            cout<<"no significant commonalities"<<endl;
        else cout<<ans<<endl;
    }
}
