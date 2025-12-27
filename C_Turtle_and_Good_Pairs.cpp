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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    int n;
    cin>>n;
    priority_queue<pair<int,char>> pq;
    string s,ans="";
    cin>>s;
    map<char,int> mp;

    for(auto ch : s)
    {
        mp[ch]++;
    }

    for(auto x : mp) pq.push({x.second,x.first});

    while(pq.size()>1)
    {
        auto x1=pq.top();
        pq.pop();
        auto x2=pq.top();
        pq.pop();

        ans+=x1.second;
        ans+=x2.second;

        if(x1.first!=1) pq.push({x1.first-1,x1.second});
        if(x2.first!=1) pq.push({x2.first-1,x2.second});
    }

    if(pq.size())
    {
        auto x1=pq.top();
        for(int i=0;i<x1.first;i++) ans+=x1.second;
    }

    cout<<ans<<'\n';
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