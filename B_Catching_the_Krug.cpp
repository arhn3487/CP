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
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

bool check(ll n, ll rK, ll cK, ll rD, ll cD, ll T) {
    vector<pair<ll, ll>> vec;
    
    vec.push_back(make_pair(rK - T, cK));
    vec.push_back(make_pair(rK + T, cK));
    vec.push_back(make_pair(rK, cK - T));
    vec.push_back(make_pair(rK, cK + T));
    
    ll dist = T - rK;
    if (dist >= 0) {
        vec.push_back(make_pair(0, max(0LL, cK - dist)));
        vec.push_back(make_pair(0, min(n, cK + dist)));
    }
    
    dist = T - (n - rK);
    if (dist >= 0) {
        vec.push_back(make_pair(n, max(0LL, cK - dist)));
        vec.push_back(make_pair(n, min(n, cK + dist)));
    }
    
    dist = T - cK;
    if (dist >= 0) {
        vec.push_back(make_pair(max(0LL, rK - dist), 0));
        vec.push_back(make_pair(min(n, rK + dist), 0));
    }
    
    dist = T - (n - cK);
    if (dist >= 0) {
        vec.push_back(make_pair(max(0LL, rK - dist), n));
        vec.push_back(make_pair(min(n, rK + dist), n));
    }
    
    for (auto p : vec) {
        ll r = p.first;
        ll c = p.second;
        if (r < 0 || r > n || c < 0 || c > n) continue;
        if (max(abs(r - rD), abs(c - cD)) > T) {
            return false;
        }
    }
    return true;
}

void solve()
{
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    
    ll low = 0, high = 3 * n, result = -1;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        
        if (check(n, a, b, c, d, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << result << '\n';
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
        solve();
    }
}