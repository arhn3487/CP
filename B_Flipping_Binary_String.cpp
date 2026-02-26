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
    int n;
    string s;
    cin>>n>>s;
    int o=count(all(s),'1'),z=n-o;
    if(o%2==0)
    {
        cout<<o<<'\n';
        for(int i=0;i<n;i++) 
            if(s[i]=='1')
                cout<<i+1<<' ';
        cout<<'\n';
    }
    else if(z%2)
    {
        cout<<z<<'\n';
        for(int i=0;i<n;i++) 
            if(s[i]=='0')
                cout<<i+1<<' ';
        cout<<'\n';
    }
    else cout<<-1<<'\n';
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