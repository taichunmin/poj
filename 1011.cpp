#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int p[500] = {2,3,5,7}, p_cnt =4;

bool is_prime( int ia )
{
    for(int i=0;i<p_cnt && p[i]*p[i]<=ia;i++)
        if( ia % p[i] == 0 )
            return false;
    return true;
}

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int bsearch_prime(int ia)
{
    void *ptr = bsearch(&ia, p, p_cnt, sizeof (int), cmp);
    return ptr==NULL ? -1 : (((int*)ptr)-p);
}

int first_prime( int ia )
{
    int tmp = bsearch_prime(ia);
    if( tmp != -1 )
        return tmp;
    for(int i=0;i<p_cnt && p[i]*p[i]<=ia;i++)
        if( ia % p[i] == 0 )
            return i;
}

void build_prime()
{
    for( int i=11, j=2; i<=3200; i+=j, j=6-j )
        if( is_prime(i) )
            p[ p_cnt++ ] = i;
}

vector<int> prime_factor( int n )
{
    vector<int> pf;
    pf.assign(p_cnt,0);
    while(n>1)
    {
        int ia = first_prime(n);
        pf.at(ia)++;
        n /= p[ia];
    }
    return pf;
}

void factor_dfs( vector<int> &f, vector<int> &pf, int ia = 1, int pos = 0 )
{
//    printf("ia=%d, pos=%d\n",ia,p[pos]);
    bool ba=true;
    for(int i=pos;i<pf.size();i++)
        if(pf.at(i)!=0)
        {
            ba = false;
            int exp = pf.at(i);
            pf.at(i)=0;
//            cout<<p[i]<<"^"<<exp<<endl;
            for(int j=0;j<=exp;j++,ia*=p[i])
                factor_dfs(f,pf,ia,i+1);
            pf.at(i)=exp;
            break;
        }
    if(ba)
        f.push_back(ia);
}

vector<int> factor( int n )
{
    vector<int> f, pf;
    pf = prime_factor(n);
    factor_dfs( f, pf );
    sort(f.begin(),f.end());
    return f;
}

void debug_vector(vector<int> pf)
{
    for(int i=0;i<pf.size();i++)
        cout<<pf.at(i)<<' ';
    cout<<endl;
}

bool backet( vector<int> sticks, int backet_max )
{
//    printf("backet size = %d\n",backet_max);
    int unused = sticks.size();
    vector<bool> used;
    used.assign( unused, false );
    while( unused > 0 )
    {
        int space = backet_max;
        for(int i=0;i<sticks.size() && space > 0;i++)
            if( !used.at(i) && space >= sticks.at(i) )
            {
                used.at(i) = true;
                space -= sticks.at(i);
                unused--;
//                printf("pick sticks[%d] = %d\n",i,sticks.at(i));
            }
        if(space!=0)
            return false;
    }
    return true;
}

int main()
{
    build_prime();
//    debug_vector(prime_factor(10));
//    debug_vector(factor(24));
    vector<int> sticks, fact;
    sticks.reserve(64);
    int T,ia;
    while(cin>>T,T)
    {
        int sum = 0;
        sticks.resize(0);
        while(T--)
        {
            cin>>ia;
            sticks.push_back(ia);
            sum += ia;
        }
        sort(sticks.rbegin(),sticks.rend());
        debug_vector(sticks);
        fact = factor(sum);
//        debug_vector(fact);
        for( int i=0;i<fact.size();i++ )
            if( fact.at(i)>=sticks.at(0) && backet(sticks,fact.at(i)) )
            {
                cout<<fact.at(i)<<endl;
                break;
            }
    }
}
