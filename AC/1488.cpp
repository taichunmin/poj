#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

char str[500];
bool m=0;

void aa(int i,unsigned int strl)
{
    for(int j=0;j<strl;j++)
      if(str[j]=='\"')
      {
        str[j]=m?('\''):('`');
        for(int k=strl;k>j;k--)
          str[k]=str[k-1];
        str[j+1]=m?('\''):('`');
        m=m?0:1;
        break;
      }
}

int main()
{
    while(cin.getline(str,100))
    {
        for(int i=0;i<strlen(str);i++)
          aa(i,strlen(str));
        cout<<str<<endl;
        for(int i=0;i<500;i++)
          str[i]=0;
    }
//    system("pause");
}
