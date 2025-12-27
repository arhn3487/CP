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

void solve()
{
    ll n,ans=0;cin>>n;
    vector<array<ll,3>> tmp_ans(n),v(n);
    
    for(int i=0;i<n;i++) cin>>v[i][0]>>v[i][1]>>v[i][2];

    tmp_ans=v;

    for(int i=1;i<n;i++)
    {
        ll tt=0;
        
        for(int j=0;j<3;j++)
        {
            ll mx=0;
            for(int k=0;k<3;k++)
            {
                if(j!=k) mx=max(mx,tmp_ans[i-1][k]);
            }
            tmp_ans[i][j]+=mx;
        }
    }

    //debug(tmp_ans);

    for(int i=0;i<3;i++) ans=max(ans,tmp_ans[n-1][i]);

    cout<<ans<<'\n';

}

int main()
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