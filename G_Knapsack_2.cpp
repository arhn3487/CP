#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e5+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

vector<int> v,w;
ll dp[101][M];

ll mn_finder(int ind,ll cost_left)
{
    //cout<<cost_left<<" "<<ind<<endl;
    if(cost_left==0) return 0;
    if(ind<0) return 1e15;
    //cout<<"ABC\n";
    //cout<<dp[ind][cost_left]<<endl;
    if(dp[ind][cost_left]!=-1) return dp[ind][cost_left];
    //cout<<"ARAFT\n";

    //not take
    ll not_take=mn_finder(ind-1,cost_left);
    ll take=1e15;
    if(cost_left-v[ind]>=0) take=mn_finder(ind-1,cost_left-v[ind])+w[ind];
    return dp[ind][cost_left]=min(take,not_take);
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    ll n,wt;
    cin>>n>>wt;
    v.resize(n);
    w.resize(n);

    for(int i=0;i<n;i++) cin>>w[i]>>v[i];

    ll mx_val=1e5;

    for(int i=1e5;i>=0;i--)
    {
        ll ans=mn_finder(n-1,i);
        //cout<<ans<<"\n";
        if(ans<=wt)
        {
            cout<<i;
            return;
        }
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