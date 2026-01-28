#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M = 1e9 + 7;
const int N = 1e6 + 5;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve() 
{
    int n,m=0,dist=0,d1=0,d2=0,d=0;
    pair<int,int> a,b;
    map<int,int> mx,mn;
    
    cin>>n>>a.first>>a.second>>b.first>>b.second;
    vector<int> v(n);
    vector<pair<int,int>> vv;

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        m=max(m,v[i]);
    }

    dist=b.first-a.first;

    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        mn[v[i]]=infinity;
        mx[v[i]]=max(mx[v[i]],x);
        mn[v[i]]=min(mn[v[i]],x);
    }

    debug(dist);

    for(auto [x,y] : mx)
    {
        vv.push_back({y,mn[x]});
        if(y==mn[x]) continue;
        dist+=abs(y-mn[x]);
        debug(dist,x);
    }
    debug(mx,mn);
    debug(vv,dist);

    int s=a.second,i=0;
    
    while(1)
    {
        if(i==vv.size()) break;
        if(abs(vv[i].first-s)>abs(vv[i].second-s))
        {
            d1+=abs(vv[i].second-s);
            s=vv[i].first;
        }
        else
        {
            d1+=abs(vv[i].first-s);
            s=vv[i].second;
        }
        i++;
    }

    debug(d1);

   d1+=abs(s-b.second);

    

    cout<<dist+d1<<'\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}