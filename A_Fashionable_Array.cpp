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
    int n,mn=INT_MAX;
    cin>>n;
    vector<int> v(n);

    for(auto &x : v) cin>>x;

    sort(all(v));

    for(int i=0;i<=n-1;i++)
    {
        if(v[i]%2==v[n-1]%2)
        {
            //cout<<i<<'\n';
            mn=min(mn,i);
           // return;
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        if(v[0]%2==v[i]%2)
        {
            //cout<<n-i-1<<'\n';
            mn=min(n-i-1,mn);
            //return;
        }
    }
    //cout<<n-1<<'\n';
    cout<<mn<<'\n';
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