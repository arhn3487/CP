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

vector<int> par;

int find_par(int u)
{
    if(par[u]==u) return u;
    return par[u]=find_par(par[u]);
}

bool union_(int a,int b)
{
    a=find_par(a);
    b=find_par(b);

    if(a!=b)
    {
        par[a]=b;
        return true;
    }
    return false;
}

void solve() 
{
    int n,m,ans=0;cin>>n>>m;
    par.resize(n+1);
    set<int> st;
    for(int i=0;i<=n;i++) par[i]=i;
    for(int i=0;i<m;i++)
    {
        int x,y,z;cin>>x>>y>>z;
        union_(x,y); 
    }

    for(int i=1;i<=n;i++)
    {
        st.insert(find_par(i));
    }

    cout<<st.size()<<'\n';
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