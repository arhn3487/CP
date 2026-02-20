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
const ll infinity = 1e18;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");


void solve() 
{
    int n,m,ans=infinity;cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m)),dpstart(n,vector<int>(m)),dpend(n,vector<int>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    
    dpstart[0][0]=a[0][0];
    dpend[n-1][m-1]=a[n-1][m-1];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!i && !j) continue;
            dpstart[i][j]=a[i][j]+max(((i-1>=0) ? dpstart[i-1][j] : -infinity),((j-1>=0) ? dpstart[i][j-1] : -infinity));
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 && j==m-1) continue;
            dpend[i][j]=a[i][j]+max(((j+1<m) ? dpend[i][j+1] :-infinity),((i+1<n) ? dpend[i+1][j] : -infinity));
        }
    }

    for(int i=0;i<n;i++)
    {
        int tmp=-infinity;
        vector<int> leftbest(m,-infinity),rightbest(m,-infinity);
        if(i+1<n)
        for(int j=0;j<m;j++)
        { 
            leftbest[j]=dpstart[i][j]+dpend[i+1][j];
            if(j) leftbest[j]= max(leftbest[j],leftbest[j-1]);
        }
        if(i-1>=0)
        for(int j=m-1;j>=0;j--)
        {   
            rightbest[j]=dpstart[i-1][j]+dpend[i][j];
            if(j+1<m)  rightbest[j]= max(rightbest[j],rightbest[j+1]);
        }
        for(int j=0;j<m;j++)
        { 
            tmp=max({(j>0) ? leftbest[j-1] : -infinity,(j<m-1) ? rightbest[j+1] : -infinity,dpstart[i][j]+dpend[i][j]-3*a[i][j]});
            ans=min(ans,tmp);
        }
    }

    print(ans)

    debug(dpstart);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}