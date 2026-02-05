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
    int n,d,a,cnt=0,s=0;cin>>n>>d>>a;
    deque<array<int,2>> dq;
    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        int p,q;cin>>p>>q;
        mp[p]=max(q,mp[p]);
    }

    debug(mp);

    for(auto [x,y] : mp)
    {
        while(dq.size() && dq.front()[0]<x) 
        {
            s-=dq.front()[1];
            dq.pop_front();
        }
        //int sz=dq.size();
        y-=s;

        if(y>0)
        {
            int boom_needed=ceil(y/(a*1.0));
            cnt+=boom_needed;
            s+=boom_needed*a;
            dq.push_back({x+2*d,boom_needed*a});
        }
        
        // while(y>0)
        // {
        //     dq.push_back(x+2*d);
        //     cnt++;
        //     y-=a;
        // }   
        debug(dq,x,cnt);
    }

    cout<<cnt<<'\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}