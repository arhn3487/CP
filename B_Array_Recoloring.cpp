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
    ll n,k,s=0;
    cin>>n>>k;
    vector<ll> v(n);

    for(int i=0;i<n;i++) cin>>>v[i];

    if(k==1)
    {
        int a,b;

        s=v[0]+v[n-1];

        for(int i=1;i<n-1;i++)
        {
            s=max(s,v[i]+max(v[0],v[n-1]));
        }
        print(s)
        return;
    }

    sort(rall(v));

    int i=0;

    while(i<=k)
    {
        s+=v[i];
        i++;
    }

    print(s)
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