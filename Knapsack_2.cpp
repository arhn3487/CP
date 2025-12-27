#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll int
const int M=1e9+7;
//const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
//inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

ll knapsack(ll max_wt,int ind,vector<ll> &val,vector<ll> &wt,map<pair<ll,ll>,ll> &dp)
{
    pair<ll,ll> p={ind,max_wt};
    if(dp[p]) return dp[p];
    if(ind==0)
    {
        if(max_wt>=wt[0]) return val[0];
        else return 0;
    }

    ll not_take=0+knapsack(max_wt,ind-1,val,wt,dp);
    ll take=LLONG_MIN;
    if(max_wt>=wt[ind]) take=val[ind]+knapsack(max_wt-wt[ind],ind-1,val,wt,dp);
    return dp[p]=max(take,not_take);
}

void solve()
{
    ll n,w;
    cin>>n>>w;
    vector<ll> v(n),wt(n);
    map<pair<ll,ll>,ll> dp;

    for(int i=0;i<n;i++)
        cin>>wt[i]>>v[i];
    
    cout<<knapsack(w,n-1,v,wt,dp);
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