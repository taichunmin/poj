#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    while(getline(cin,str) && str[0]!='#')
    {
        int sum=0;
        for(int i=0;i<str.size();i++)
            sum += (str[i]==' '?0:(str[i]-'A'+1))*(i+1);
        cout<<sum<<endl;
    }
}
