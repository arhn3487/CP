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
    ll n,lost=0,found=0;cin>>n;
    vector<ll> a(n),b(n),c(n);

    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    for(auto &x : c) cin>>x;

    for(int i=0;i<n;i++)
    {
        if((a[i]<c[i]) || (b[i]>c[i]) || ((c[i]-a[i])%2 !=0)) 
        {
            yes(0)
            return;
        }

        lost+=(a[i]-c[i]);
        found+=(c[i]-b[i]);
    }

    cout<<(lost==2*found?"YES\n":"NO\n");
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