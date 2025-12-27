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
const int N=3005;
double dp[N][N];
bool vis[N][N];
vector<double> v(N);

double rec(int ind,int ch)
{
    if(ind==n)
    {
        if(ch>n-ch) return 1.0;
        else return 0.0;
    }
    if(vis[ind][ch]) return dp[ind][ch];
    vis[ind][ch]=true;
    //if(ind==n-1) return dp[ind][ch]=rec(ind+1,ch)*v[ind]+rec(ind+1,ch)*(1.0-v[ind]);
    return dp[ind][ch]=rec(ind+1,ch+1)*v[ind]+rec(ind+1,ch)*(1.0-v[ind]);
}


void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<fixed<<setprecision(10);
    cout<<rec(0,0)<<'\n';
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