#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
//#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const ll M=1e9+7;
const ll infinity = LLONG_MAX;
ll dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
ll dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define prll(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

ll cross(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c)
{
    return (b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second);
}

long long signedArea2(const vector<pair<ll,ll>>& P) {
    // returns 2 * signed area of polygon P; positive => CCW, negative => CW
    long long A = 0;
    int m = (int)P.size();
    for (int i = 0; i < m; ++i) {
        int j = (i+1)%m;
        A += P[i].first * P[j].second - P[j].first * P[i].second;
    }
    return A;
}

ll area(const vector<pair<ll,ll>> v)
{
    int m=v.size();
    ll a=0;

    for(int i=0;i<m;i++)
    {
        a+=v[i].first*v[(i+1)%m].second-v[i].second*v[(i+1)%m].first;
    }
    return a;
}

void solve()
{
    ll n;

    while (cin>>n && n)
    {
        vector<pair<ll,ll>> points(n);
        
        for(auto &[x,y] : points) cin>>x>>y;
        if(n==1)
        {
            cout<<1<<'\n'<<points[0].first<<' '<<points[0].second<<'\n';
            continue;
        }
        sort(all(points));
        

        vector<pair<ll,ll>> lower,upper;

        for(ll i=0;i<n;i++)
        {
            while(lower.size()>=2 && cross(lower[lower.size()-2],lower.back(),points[i])<=0) lower.pop_back();
            lower.push_back(points[i]);
        }
        for(ll i=n-1;i>=0;i--)
        {
            while(upper.size()>=2 && cross(upper[upper.size()-2],upper.back(),points[i])<=0) upper.pop_back();
            upper.push_back(points[i]);
        }

        upper.pop_back();
        lower.pop_back();

        lower.insert(lower.end(),upper.begin(),upper.end());

        if(*lower.begin()==*lower.rbegin()) lower.pop_back();

        //  if (lower.size() > 1) {
        //     long long A2 = signedArea2(lower);
        //     if (A2 < 0) reverse(lower.begin(), lower.end()); // if clockwise, reverse to make CCW
        // }

        if(lower.size()>1)
        {
            ll a=area(points);
            if(a<0) reverse(all(points));
        }

        cout<<lower.size()<<'\n';

        for(auto [x,y] : lower) cout<<x<<' '<<y<<'\n';
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    //cin>>t;

    for(ll i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}