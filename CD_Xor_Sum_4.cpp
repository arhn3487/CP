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
    int n,ans=0;cin>>n;
    vector<int> v(n);

    for(auto &x : v) cin>>x;
    vector<array<int,64>> st(n);

    for(int i=62;i>=0;i--)
    {
        int cnt=0;
        for(int j=n-1;j>=0;j--)
        {
            if(v[j]&(1LL<<i)) cnt++;
            st[j][i]=cnt;
        }
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=61;j>=0;j--)
        {
            int ss=st[i+1][j];
            ll num=(1LL<<j);
            num%=M;
            ll tmp=(v[i]&(1LL<<j)) ? (n-1-i-ss) : ss;
            tmp*=num;
            tmp%=M;
            ans+=tmp;
            ans%=M;
        }
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