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

vector<ll> v,dp;
ll n,cost=infinity,k;

ll rec(ll ind)
{
    //debug(ind,c);
    
    if(ind==n-1) return 0;
    if(dp[ind]!=infinity) return dp[ind];
    ll a=infinity,b=infinity;
    for(int i=1;i<=k;i++)
    {
        if(ind+i<n) a=abs(v[ind+i]-v[ind])+rec(ind+i);
        dp[ind]=min(dp[ind],a);
    }
    
    return dp[ind];
} 

void solve()
{
    cin>>n>>k;
    v.assign(n,0);
    dp.assign(n+1,infinity);
    for(int i=0;i<n;i++) cin>>v[i];
    //dp[0]=0;
    cout<<rec(0);
    //for(auto x : dp) cout<<x<<" ";
    // cout<<'\n';
    //cout<<cost<<endl;
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