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
    int n;cin>>n;
    vector<int> a(n),b(n);

    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    sort(all(a));

    for(int i=1;i<n;i++) b[i]+=b[i-1];

    int lo=0,hi=1e9,ans=0;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        int ase=(a.end()-lower_bound(all(a),mid));
        // auto it=lower_bound(all(b),ase);
        // if(*it!=ase) it--;
        // int kk= it-b.begin();
        int kk = upper_bound(all(b), ase) - b.begin();

        if(kk>0)
        {
            ans=max(ans,kk*mid);
            lo=mid+1;
        }
        else hi=mid-1;
        //ans=max(ans,mid*kk);
    }

    cout<<ans<<'\n';
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