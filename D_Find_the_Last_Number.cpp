#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

int ask(int i,int x)
{
    cout<<"? "<<i<<" "<<x<<endl;
    int a;cin>>a;
    return a==1;
}

void solve()
{
    int n,bit=0;cin>>n;
    set<int> val,ind;

    for(int i=1;i<n;i++)
    {
        ind.insert(i);
        val.insert(i);
    }

    val.insert(n);

    while(val.size()>1)
    {
        set<int> one,zero;
        int expected_one=0,bit_val=(1<<bit);

        for(auto x : val)
            if(x & bit_val) expected_one++;
        
        for(auto x : ind)
        {
            if(ask(x,bit_val)) one.insert(x);
            else zero.insert(x);
        }

        if(expected_one>one.size())
        {
            set<int> tmp;
            for(auto x : val)
            {
                //debug(x);
                if(x&bit_val) tmp.insert(x);
            }
            swap(tmp,val);
            swap(one,ind);
        }
        else
        {
            set<int> tmp;
            for(auto x : val)
            {
                //debug(x);
                if((x&bit_val)==0) tmp.insert(x);
            }
            //debug(bit_val,tmp);
            swap(tmp,val);
            swap(zero,ind);
        }

        bit++;
        //debug(one,zero,val,ind);
    }

    cout<<"! "<<*val.begin()<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}

/*
101
001
011
100
010
*/