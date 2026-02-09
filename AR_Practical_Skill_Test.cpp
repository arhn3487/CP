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
    int h,w,d,q;cin>>h>>w>>d;
    vector<array<int,2>> v(w*h+1);
    vector<int> ans(w*h+1,0);

    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            int a;cin>>a;
            v[a]={i,j};
        }
    }

    for(int i=d+1;i<=w*h;i++)
    {
        int dd=abs(v[i][0]-v[i-d][0])+abs(v[i][1]-v[i-d][1]);
        ans[i]=ans[i-d]+dd;
    }

    cin>>q;

    while (q--)
    {
        int l,r;cin>>l>>r;
        cout<<ans[r]-ans[l]<<'\n';
    }
    
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