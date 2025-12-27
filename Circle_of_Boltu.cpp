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

ll dist(array<int,2> p,array<int,2> q)
{
    ll a=p[0]-q[0],b=p[1]-q[1];
    a*=a;b*=b;
    return a+b;
}

void solve()
{
    ll n,ans=0;
    cin>>n;
    vector<array<int,2>> v(n);

    for(auto &[x,y] : v) cin>>x>>y;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans=max(ans,dist(v[i],v[j]));
        }
    }

    print(ans)
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
        cout<<"Case "<<i<<": ";
        solve();
    }
}