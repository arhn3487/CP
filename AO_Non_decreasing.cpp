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

int n;
int v[55];

int find(int x)
{
    for(int i=1;i<=n;i++)
        if(v[i]==x) return i;
}

void solve()
{
    int mx=INT_MIN,mn=INT_MAX;cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        mx=max(mx,v[i]);
        mn=min(mn,v[i]);
    } 

    cout<<2*n-2<<'\n';
    if(mx>abs(mn))
    {
        int ind=find(mx);

        for(int i=1;i<=n;i++)
        {
            if(i!=ind)
                cout<<ind<<' '<<i<<'\n';
        }

        for(int i=2;i<=n;i++)
            cout<<i-1<<' '<<i<<'\n';
    }
    else
    {
        int ind=find(mn);

        for(int i=1;i<=n;i++)
        {
            if(i!=ind)
                cout<<ind<<' '<<i<<'\n';
        }

        for(int i=n-1;i>=1;i--)
            cout<<i+1<<' '<<i<<'\n';
    }

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