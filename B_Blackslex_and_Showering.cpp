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
    ll n,sum=0,mn=infinity;cin>>n;
    vector<int> v(n);

    for(auto &x : v) cin>>x;

    for(int i=1;i<n;i++)
    {
        sum+=abs(v[i]-v[i-1]);
    }

    debug(sum);

    for(int i=1;i<n-1;i++)
    {
        mn=min(mn,sum-abs(v[i]-v[i-1])-abs(v[i]-v[i+1])+abs(v[i+1]-v[i-1]));
    }

    mn=min(mn,sum-abs(v[1]-v[0]));
    mn=min(mn,sum-abs(v[n-1]-v[n-2]));

    cout<<mn<<'\n';
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