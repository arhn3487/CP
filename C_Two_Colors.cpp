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

    vector<int> v(m);
    for(int i=0;i<m;i++)
    {
        cin>>v[i];
        v[i]=min(v[i],n-1);
    }

    sort(all(v));

    ll sum=0,ptr=m-1,ans=0;

    for(int i=0;i<m;i++)
    {
        while(ptr>=0 && v[i]+v[ptr]>=n)
        {
            sum+=v[ptr];
            ptr--;
        }
        ans+=(m-ptr-1)*(v[i]-n+1)+sum;
    }

    for(int i=0;i<m;i++)
    {
        if(2*v[i]>=n) ans-=2*v[i]-n+1;
    }
    print(ans)
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