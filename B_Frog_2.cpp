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
    ll n,k;cin>>n>>k;
    vector<ll> v(n),ans(n,infinity);

    for(auto &x : v) cin>>x;
    ans[0]=0;
    for(int i=1;i<n;i++)
    {
        int cnt=k;
        for(int j=i-1;j>=0 && cnt;j--,cnt--)
        {
            ans[i]=min(ans[i],ans[j]+abs(v[i]-v[j]));
        }
        //ans[i]=min(ans[i-1]+abs(v[i]-v[i-1]),ans[i-2]+abs(v[i]-v[i-2]));
    }

    cout<<ans[n-1]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}