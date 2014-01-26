#include<iostream>
using namespace std;

int main()
{
    int aa[9];
    while(cin>>aa[0])
    {
      for(int i=1;i<9;i++)cin>>aa[i];
      bool emply=1;
      for(int i=0;i<9;i++)
        if(aa[i]!=0)
        {
          emply=0;
          break;
        }
      if(emply)
      {
        cout<<'0'<<endl;
        continue;
      }
      bool a[9]={0};
      bool first=1;
      for(int i=0;i<9;i++)
        if(aa[i]!=0)
        {
          if(aa[i]<0)
          {
            a[i]=true;
            aa[i]*=-1;
          }
          if(first)
          {
            if(a[i])cout<<'-';
            first=!first;
          }
          else
            cout<<(a[i]?" - ":" + ");
          if(aa[i]!=1)
            cout<<aa[i];
          if(i<8)
            cout<<'x';
          if(i<7)
            cout<<'^'<<(8-i);
          if(i==8 && aa[i]==1)cout<<'1';
        }
      cout<<endl;
    }
    //system("pause");
}
