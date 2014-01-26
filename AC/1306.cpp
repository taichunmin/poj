#include<iostream>
#include<cmath>
using namespace std;
unsigned long long c=1;
bool q[100];

int main()
{
    unsigned long long n,m;
    while(cin>>n>>m)
    {
      if(n==0 || m==0) break;
      for(int y=1;y<m;y++) q[y]=1;
      for(unsigned long long t=0;t<m;t++)
      {
          c*=(n-t);
          for(int p=2;p<=m;p++)
              if(c%p==0 && q[p-1]==1)
                  {
                      c/=p;
                      q[p-1]=0;
                  }
      }
      cout<<n<<" things taken "<<m<<" at a time is "<<c<<" exactly.\n";
      c=1;
      }
        //system("pause");
}

