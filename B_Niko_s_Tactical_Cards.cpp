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
    int n,k=0;cin>>n;
    vector<int> a(n),b(n),dpneg[n],dppos[b];

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    dpa[0]=-a[0];
    dpb[0]=b[0];

    for(int i=1;i<n;i++)
    {
        dpneg[i]=min({dpneg[i-1]-a[i],b[i]-dpneg[i-1],dppos[i-1]-a[i],b[i]-dppos[i-1]});
        dpneg[i]=max({dpneg[i-1]-a[i],b[i]-dpneg[i-1],dppos[i-1]-a[i],b[i]-dppos[i-1]});
    }

    cout<<max(dpneg[n-1],dppos[n-1])<<'\n';
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
