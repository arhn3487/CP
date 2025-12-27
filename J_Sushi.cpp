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

const int N=305;
double dp[N][N][N];
bool vis[N][N][N];
int n;

double rec(int c1,int c2,int c3)
{
    if(vis[c1][c2][c3]) return dp[c1][c2][c3];
    vis[c1][c2][c3]=true;
    if(c1==0 && c2==0 && c3==0) return 0;
    double ans=1;
    if(c1>0) ans+=(1.*c1/n)*rec(c1-1,c2,c3);
    if(c2>0) ans+=(1.*c2/n)*rec(c1+1,c2-1,c3);
    if(c3>0) ans+=(1.*c3/n)*rec(c1,c2+1,c3-1);
    double p0=1.-1.*(n-c1-c2-c3)/n;
    ans/=p0;
    return dp[c1][c2][c3]=ans;
}

void solve()
{
    cin>>n;
    int arr[4]={};
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        arr[a]++;
    }

    cout<<fixed<<setprecision(14);
    cout<<rec(arr[1],arr[2],arr[3]);
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