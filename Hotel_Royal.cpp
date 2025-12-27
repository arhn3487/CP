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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

#define int long long

void solve()
{
    int n,m,ans=0;cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));

    int total[m];

    for(int i=0;i<n;i++)
    {
        int o;cin>>o;
        for(int j=0;j<o;j++)
        {
            int a,b;cin>>a>>b;
            a--;
            grid[i][a]+=b;
        }
    }

    for(auto &x : total) cin>>x;

    for(int i=0;i<(1<<n);i++)
    {
        int tmp=i,cnt=__builtin_popcountll(i),f=1;
        // for(int j=0;j<=n;j++) 
        //     if((i&(1<<j))) cnt++;
        if(cnt<ans) continue;

        for(int k=0;k<m;k++)
        {
            int cc=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                cc+=grid[j][k];
            }

            if(cc>total[k]) 
            {
                f=0;
                break;
            }
        }

        if(f) ans=max(ans,cnt);

    }

    cout<<ans<<'\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}