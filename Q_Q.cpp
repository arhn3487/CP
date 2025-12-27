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
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

void solve()
{
    int n,k;cin>>n>>k;
    vector<array<double,2>> v(n);

    for(auto &[x,y] : v) cin>>x>>y;
    double lo=0.0,high=100.0;

    for(int i=1;i<=100;i++)
    {
        double mid=(lo+high)/2.0,sum=0;
        vector<double> tmp(n);

        for(int i=0;i<n;i++) tmp[i]=v[i][0]*(v[i][1]-mid);

        sort(rall(tmp));

        for(int i=0;i<k;i++) sum+=tmp[i];

        if(sum>=0) lo=mid;
        else high =mid;
    }

    cout<<fixed<<setprecision(10)<<lo<<'\n';
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