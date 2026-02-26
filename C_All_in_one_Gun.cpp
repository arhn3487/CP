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
const ll infinity = 1e15;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve() 
{
    int n,h,k,total=0,ans=0;cin>>n>>h>>k;
    vector<int> v(n);

    for(auto &x : v)
    {
        cin>>x;
        total+=x;
    }
    int bar=h/total;
    bar--;
    bar=max(bar,0LL);
    int dam=(h/total)*total;
    int extra=h-dam;
    ans=(h/total)*n+(bar)*k;

    debug(extra,total,ans);
    if(extra)
    {
        if(ans)
        ans+=k;
        vector<int> mx(n,v[n-1]),mn(n,v[0]);

        for(int i=1;i<n;i++)
        {
            mn[i]=min(mn[i-1],v[i]);
        }

        for(int i=n-2;i>=0;i--)
        {
            mx[i]=max(mx[i+1],v[i]);
        }

        int sec_dem=0;

        debug(ans);
        for(int i=0;i<n;i++)
        {
            sec_dem+=v[i];
            int t_d=sec_dem+((i+1<n) ? max(0LL,mx[i+1]-mn[i]) : 0);
            //t_d=max(t_d,sec_dem);
            if(t_d>=extra)
            {
                ans+=(i+1);
                break;
            }
        }

        debug(ans);

        debug(mn);
        debug(mx);
    }
    print(ans)
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