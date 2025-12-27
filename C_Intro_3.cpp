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

vector<int> v,dp;
int n,cost=INT_MAX;

int rec(int ind)
{
    //debug(ind,c);
    
    if(ind==n-1) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int a=INT_MAX,b=INT_MAX;
    if(ind+1<n)a=abs(v[ind+1]-v[ind])+rec(ind+1);
    if(ind+2<n)b=abs(v[ind+2]-v[ind])+rec(ind+2);
    //cout<<a<<" "<<b<<endl;
    return dp[ind]=min(a,b);
} 

void solve()
{
    cin>>n;
    v.assign(n,0);
    dp.assign(n+1,-1);
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