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
    int n,m,k,a,b;
    cin>>n>>m>>k;

    for(int i=0;i<k;i++) cin>>a>>b;
    for(int i=0;i<k;i++) cin>>a>>b;

    cout<<n*m+n+m-3<<'\n';

    for(int i=1;i<n;i++) cout<<'U';
    for(int i=1;i<m;i++) cout<<'L';

    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(int j=1;j<m;j++)
            {
                cout<<'R';
            }
        }
        else
        {
            for(int j=1;j<m;j++)
            {
                cout<<'L';
            }
        }
        if(i!=n-1)cout<<'D';
    }

    cout<<'\n';
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