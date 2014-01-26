#include<iostream>
using namespace std;
/*
string fa(string sa)
{
  for(int i=0;i<sa.size()/2;i++)
    swap(sa[i],sa[sa.size()-i-1]);
  return sa;
}
*/
string fb(string sa)
{
  int ib;
  for(int i=0;i<sa.size();i++)
  {
    ib=(sa[i]-'0');
    if(i+(ib>9)>sa.size()-1)sa.append(i+(ib>9)+1-sa.size(),'0');
    if(ib/10)sa[i+1]+=ib/10;
    sa[i]=ib%10+'0';
  }
  return sa;
}

string fc(string sa,string sb)
{
  bool ba=true;
  for(int i=sa.size()-1;i>-1;i--)
    if(sa[i]!='0')
    {
      sa.assign(sa,0,i+1);
      ba=false;
      break;
    }
  if(ba)sa="0";
  ba=true;
  for(int i=sb.size()-1;i>-1;i--)
    if(sb[i]!='0')
    {
      sb.assign(sb,0,i+1);
      ba=false;
      break;
    }
  if(ba)sb="0";
  ba=true;
  int ia=(sa.size()>sb.size()?sa.size():sb.size()),ib;
  string sc(ia,'0');
  for(int i=0;i<ia;i++)
    sc[i]=(i<sa.size()?sa[i]:'0')-'0'+(i<sb.size()?sb[i]:'0');
  sc=fb(sc);
  for(int i=0;i<sc.size();i++)
    if(sc[i]!='0')
    {
      sc.assign(sc,i,sc.size()-i);
      ba=false;
      break;
    }
  if(ba)return "0";
  return sc;
}

int main()
{
  string sa,sb;
  int ta;
  cin>>ta;
  for(int ti=0;ti<ta;ti++)
  {
    cin>>sa>>sb;
    cout<<fc(sa,sb)<<endl;
  }
  //system("pause");
}
