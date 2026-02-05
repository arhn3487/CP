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
    int n,c,sum=0,ans=0;cin>>n>>c;
    vector<array<int,2>> v(n);

    for(auto &[x,y] : v) cin>>x>>y;

    for(int i=0;i<n;i++)
    {
        sum+=v[i][1];
        ans=max(ans,sum-v[i][0]);
        
        for(int j=n-1;j>i;j--)
        {
            int sum2=0;
            for(int k=j;k<n;k++)
            {
                sum2+=v[k][1];
            }
            debug(c-v[j][0],sum,sum2);
            int a = v[i][0];       
            int b = c - v[j][0];   
            int dist = a + b + min(a, b);


            //int dist=v[i][0]+(c-v[j][0])+min(v[j][0],c-v[i][0]);
            ans=max(ans,sum+sum2-dist);
        }
    }

    cout<<ans<<'\n';
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