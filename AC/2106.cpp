/*
    陷阱； ! 的運算順序不一樣，請測試 !!!!F、!!!F
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

vector<bool> bost;
vector<char> chst;

int sign_priority(char ca)
{
    switch(ca)
    {
    case '(':
        return 1;
    case ')':
        return 2;
    case '|':
        return 3;
    case '&':
        return 4;
    case '!':
        return 5;
    default:
        return -1;
    }
}

void do_op( char ca )
{
    bool ba;
    switch(ca)
    {
    case '!':
        bost.back() = !bost.back();
        break;
    case '&':
        ba = bost.back();
        bost.pop_back();
        bost.back() = bost.back() & ba;
        break;
    case '|':
        ba = bost.back();
        bost.pop_back();
        bost.back() = bost.back() | ba;
        break;
    }
}

void debug()
{
    cout<<"bost: ";
    for(int i=0;i<bost.size();i++)
        cout<<(int)bost.at(i)<<" ";
    cout<<endl<<"chst: ";
    for(int i=0;i<chst.size();i++)
        cout<<chst.at(i)<<" ";
    cout<<endl;
}

int main()
{
    string str;
    int t0=0;
    char ca;
    while(getline(cin,str))
    {
        istringstream ssin(str);
        while(ssin>>ca)
        {
            int pri = sign_priority(ca);
            if(pri==-1)
                bost.push_back( (ca=='V') );
            else
            {
                while( chst.size()>0 && ca != '(' && sign_priority(ca) <= sign_priority( chst.back() ) )
                {
                    if( ca=='!' && chst.back()==ca )
                        break;
                    do_op( chst.back() );
                    chst.pop_back();
                }
                if( ca == ')' )
                    chst.pop_back();
                else chst.push_back(ca);
            }
//            cout<<endl<<"ca="<<ca<<endl;
//            debug();
        }
        while( chst.size()>0 )
        {
            do_op( chst.back() );
            chst.pop_back();
        }
        printf("Expression %d: %c\n", ++t0, bost.back()?'V':'F');
        bost.resize(0);
        chst.resize(0);
    }
}
