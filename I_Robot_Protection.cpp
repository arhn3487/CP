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

ll area(vector<pair<ll,ll>> &v)
{
    ll ar=0,n=v.size();
    for(int i=0;i<n;i++)
    {
        ar+=v[i].first*v[(i+1)%n].second-v[i].second*v[(i+1)%n].first;
    }

    return ar;
}

ll cross(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c)
{
    return (b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second);
}

void solve()
{
    ll n;
    while(cin>>n && n)
    {
        vector<pair<ll,ll>> v(n),lower,upper;

        for(auto &[x,y] : v) cin>>x>>y;
        sort(all(v));

        for(int i=0;i<n;i++)
        {
            while(lower.size()>=2 && cross(lower[lower.size()-2],lower.back(),v[i])<=0) lower.pop_back();
            lower.push_back(v[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(upper.size()>=2 && cross(upper[upper.size()-2],upper.back(),v[i])<=0) upper.pop_back();
            upper.push_back(v[i]);
        }

        upper.pop_back();
        lower.pop_back();

        lower.insert(lower.end(),upper.begin(),upper.end());

        double ar=area(lower);

        cout<<ar/2<<'\n';
    }

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