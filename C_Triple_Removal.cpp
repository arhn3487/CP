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
    int n,q;cin>>n>>q;
    vector<int> v(n),pre(n,0),dp(n,1);

    for(auto &x : v) cin>>x;

    for(int i=1;i<n;i++) pre[i]=pre[i-1]+v[i];

    for(int i=1;i<n;i++)
        if(v[i]!=v[i-1]) dp[i]+=dp[i-1];
    
    //debug(pre);

    while(q--)
    {
        int l,r;cin>>l>>r;
        --l,--r;
        int sz=(r-l+1),o=pre[r]-pre[l]+v[l];
        //debug(o,sz);
        if((sz%3!=0) || (o%3!=0))
        {
            cout<<-1<<'\n';
            continue;
        }

        int ans=sz/3;
        if(r-dp[r]<l) ans++;

        cout<<ans<<'\n';
    }
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