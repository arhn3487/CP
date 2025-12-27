#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve()
{
    int n;cin>>n;
    vector<int> jor,bijor;

    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        if(a%2==0) jor.push_back(a);
        else bijor.push_back(a);
    }

    int b=bijor.size(),jr=n-b;

    if(bijor.empty())
    {
        for(int i=0;i<n;i++) cout<<0<<' ';
        cout<<'\n';
        return;
    }

    vector<int> res(n,0);
    sort(all(jor));
    sort(all(bijor));

    debug(n);

    res[0]=bijor.back();
    bijor.pop_back();

    if(jor.empty())
    {
        for(int i=1;i<n;i++)
        {
            res[i]=(res[i-1]==0) ? res[i-2] : 0;
        }

        for(auto x : res) cout<<x<<' ';
        cout<<'\n';
        return;
    }
    res[1]=jor.back()+res[0];
    jor.pop_back();

    debug(jor,bijor,n);

    for(int i=2;i<n;i++)
    {
        if(!jor.empty())
        {
            res[i]=res[i-1]+jor.back();
            jor.pop_back();
            continue;
        }
        if(b<3) res[i]=0;
        else res[i]=res[i-2];
        //res[i]=(res[i-1]==0) ? res[i-2] : 0;
        
    }

    for(auto x : res) cout<<x<<' ';
        cout<<'\n';
        return;
}

int32_t main()
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