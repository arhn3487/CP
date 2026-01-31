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
    int n,cnt=0;cin>>n;
    string s;cin>>s;
    vector<int> v(n+1,1);

    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            v[i]=0;
            if(i+1<=n) v[i+1]=0;
            if(i-1>=0) v[i-1]=0;
            cnt++;
        }
    }
    v[n]=0;

    stack<int> st;
    debug(v,cnt);

    for(int i=1;i<n;i++) 
    {
        if(v[i]==0) continue;
        v[i]+=v[i-1];
    }
    
    for(int i=0;i<=n;i++)
    {
        if(v[i]==0)
        {
            if(i==0) continue;
            if(v[i-1]==1) 
            {
                cnt++;
            }
            else cnt+=v[i-1]/3+(v[i-1]%3>0);
        }
    }

    cout<<cnt<<'\n';

    debug(v);
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