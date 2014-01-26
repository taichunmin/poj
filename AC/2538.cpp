#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char aa[46]={' ','\n',
               '1','2','3','4','5','6','7','8','9','0','-','=',
               'W','E','R','T','Y','U','I','O','P','[',']','\\',
               'S','D','F','G','H','J','K','L',';',39,
               'X','C','V','B','N','M',',','.','/','\0'};
    char bb[46]={' ','\n',
               '`','1','2','3','4','5','6','7','8','9','0','-',
               'Q','W','E','R','T','Y','U','I','O','P','[',']',
               'A','S','D','F','G','H','J','K','L',';',
               'Z','X','C','V','B','N','M',',','.','\0'};
    char cc;
    int aalon=strlen(aa);
    while(cin.get(cc))
    {
      for(int j=0;j<45;j++)
        if(aa[j]==cc)cout<<bb[j];
    }
}
