#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve()
{
    int n,m,k;cin>>n>>m>>k;
    vector<string> v(n);
    vector<vector<int>> side(n+1,vector<int>(m,0)),up(n+1,vector<int>(m,0));
    ///int side[n][m],up[n][m];

    for(auto &x : v) cin>>x;

    debug(v);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='.') continue;
            int cnt=0,k=j,l;
            while(v[i][j]=='#') cnt++,j++;
            l=j-1;
            debug(cnt);
            while(l>=k) side[i][l]=cnt,l--;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[j][i]=='.') continue;
            int cnt=0,k=j,l;
            while(j<n && v[j][i]=='#') cnt++,j++;
            l=j-1;
            debug(cnt);
            while(l>=k) up[l][i]=cnt,l--;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cerr<<side[i][j];
        }
        cerr<<'\n';
    }
    cerr<<"\n\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cerr<<up[i][j];
        }
        cerr<<'\n';
    }
    cerr<<'\n';

    //debug(up);
}

int32_t main()
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