#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    while(cin>>str,str[0]!='#')
    {
        bool ba = false;
        for(int i=str.size()-1;i>0;i--)
            if( str[i-1] < str[i] )
            {
                ba = true;
                int ia = -1;
                for(int j=i;j<str.size();j++)
                    if( str[j]>str[i-1] && ( ia==-1 || str[j]<str[ia] ) )
                        ia = j;
                while(ia+1<str.size() && str[ia]==str[ia+1])
                    ia++;
                swap(str[i-1],str[ia]);
                for(int j=(str.size()-i-1)/2;j>=0;j--)
                    swap(str[i+j],str[str.size()-j-1]);
                break;
            }
        if(ba) cout<<str<<endl;
        else cout<<"No Successor"<<endl;
    }
}
