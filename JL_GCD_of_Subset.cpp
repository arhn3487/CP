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
    int n,k,mx=0;cin>>n>>k;
    unordered_map<int,int> b,c,d;
    vector<int> v(n);

    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        v[i]=a;
        b[a]++;
        mx=max(mx,a);
    }

    debug(b);

    for(int i=1;i<=mx;i++)
    {
        for(int j=i;j<=mx;j+=i)
        {
            if(b.find(j)==b.end()) continue;
            c[i]+=b[j];
        }
    }

    debug(b);

    for(int i=1;i<=mx;i++)
    {
        if(c[i]<k) continue;
        for(int j=i;j<=mx;j+=i)
        {
            if(b.find(j)!=b.end()) d[j]=max(d[j],i);
        }
    }

    for(auto x : v)
    {
        cout<<d[x]<<'\n';
    }

    debug(d);
}

int32_t main()
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