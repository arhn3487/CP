#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define int long long
const int M=1e9+7;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
//inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void rec(int i,int l,int r,int k,vector<int> &ans)
{
    if(l==r)
    {
        ans[l]=i;
        return;
    }

    int sz=r-l-1;

    if(sz<60 && (1LL<<sz)<k)
    {
        ans[r]=i;
        rec(i+1,l,r-1,k-(1LL<<sz),ans);
        return;
    }
    else
    {
        ans[l]=i;
        rec(i+1,l+1,r,k,ans);
        return;
    }
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> ans(n);
    if(n-1<60 && 1LL<<(n-1)<k)
    {
        cout<<-1<<'\n';
        return;
    }
    rec(1,0,n-1,k,ans);

    for(auto x : ans) cout<<x<<' ';
    cout<<'\n';
}

int32_t main()
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