#include<iostream>
using namespace std;

int main()
{
    string sa,str;
    cin>>sa;cin.get();
    getline(cin,str);
    for(int i=0;i<str.size();i++)
        cout<<(('A'<=str[i] && str[i]<='Z')?(char)(sa[str[i]-'A']-32):(('a'<=str[i] && str[i]<='z')?sa[str[i]-'a']:str[i] ));
    cout<<endl;
}
