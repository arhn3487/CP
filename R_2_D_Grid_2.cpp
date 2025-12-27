#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m)),mx(n,vector<int>(m,INT_MIN)),mn(n,vector<int>(m,INT_MAX));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    
    mx[0][0]=mn[0][0]=v[0][0];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>0 && j>0)
            {
                mn[i][j]=min(mn[i][j-1],mn[i-1][j])+v[i][j];
                mx[i][j]=max(mx[i][j-1],mx[i-1][j])+v[i][j];
            }
            else if(i>0)
            {
                mn[i][j]=mn[i-1][j]+v[i][j];
                mx[i][j]=mx[i-1][j]+v[i][j];
            }
            else if(j>0)
            {
                mn[i][j]=mn[i][j-1]+v[i][j];
                mx[i][j]=mx[i][j-1]+v[i][j];
            }
        }
    }

    if((n+m)%2)
    {
        if(mn[n-1][m-1]<=0 && mx[n-1][m-1]>=0) YES
        else NO
    }
    else NO
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}