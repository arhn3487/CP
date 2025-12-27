#include<bits/stdc++.h>
//#include "D:/debug.h"
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
    int n;
    cin>>n;
    vector<vector<ll>> v(n,vector<ll>(3));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++) cin>>v[i][j];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            ll mx=0;
            for(int k=0;k<3;k++)
            {
                if(j!=k)
                {
                    mx=max(mx,v[i-1][k]);
                }
            }
            v[i][j]+=mx;
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<3;j++) cout<<v[i][j]<<' ';
    //     cout<<'\n';
    // }

    ll ans=0;

    for(int i=0;i<3;i++) ans=max(ans,v[n-1][i]);
    cout<<ans;
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