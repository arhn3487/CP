#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll int
const ll M=1e9+7;
//const ll infinity = LLONG_MAX;
ll dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
ll dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define prll(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    ll n,k;cin>>n>>k;
    ll sum=0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    vector<array<ll,3>> v(n);
    vector<ll> res(n);

    for(ll i=0;i<n;i++) cin>>v[i][0];
    for(ll i=0;i<n;i++) cin>>v[i][1],v[i][2]=i;

    sort(all(v));
    
    for(ll i=0;i<n;i++) 
    {
        res[v[i][2]]=sum;
        if(pq.size()<k)
        {
            pq.push(v[i][1]);
            sum+=v[i][1];
        }
        else if(pq.top()<v[i][1])
        {
            sum-=pq.top();
            pq.pop();
            sum+=v[i][1];
            pq.push(v[i][1]);
        }
    }

    for(auto x : res) cout<<x<<' ';
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    cin>>t;

    for(ll i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}