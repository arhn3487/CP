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

void solve()
{
    ll n,cnt=0;cin>>n;
    vector<ll> v(n),pre(n);

    for(auto &x : v) cin>>x;

    pre[0]=v[0];

    for(int i=1;i<n;i++)
    {
        pre[i]=max(v[i],pre[i-1]);
    }

    for(int i=1;i<n;i+=2)
    {
        ll a=v[i-1],b=(i<n-1) ? v[i+1] : 0,c=max(a,b);
        //if(c<v[i]) continue;
        v[i]=pre[i];
        //cnt++;
    }

    //debug(v);

    for(int i=0;i<n;i+=2)
    {
        ll a=(i!=0) ? v[i-1] : INT_MAX,b=(i+1<n) ? v[i+1] :INT_MAX,c=min(a,b);
        if(v[i]<c) continue;
        
        cnt+=(v[i]-c+1);
        //debug(c,i,c-v[i]+1);
        v[i]=c-v[i];
    }

    //debug(v);

    cout<<cnt<<'\n';
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