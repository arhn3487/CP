#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
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

vector<int> v,seg;

int build(int i,int j,int node)
{
    if(i==j) return seg[node]=v[i];
    int mid=(i+j)/2;
    int left=build(i,mid,2*node);
    int right=build(mid+1,j,2*node+1);

    return seg[node]=left&right;
}

int query(int qi,int qj,int range_i,int range_j,int node)
{
    if(range_j<qi || range_i>qj || range_j<range_i) return -1;
    if(qi<=range_i && range_j<=qj) return seg[node];
    int mid=(range_i+range_j)/2;
    int left=query(qi,qj,range_i,mid,2*node);
    int right=query(qi,qj,mid+1,range_j,2*node+1);

    return (left & right);
}

void solve()
{
    int n,k;
    cin>>n>>k;
    v.resize(n);
    seg.assign(4*n,0);

    for(auto &x : v) cin>>x;

    build(0,n-1,1);

    for(int i=0;i<n;i++)
    {
        int l=i-k,r=i+k,res;
        if(k>=n/2) res=query(0,n-1,0,n-1,1);
        else if(l<0) res = query(0, r, 0, n-1, 1) & query(n + l, n-1, 0, n-1, 1);
        else if(r>=n) res = query(l, n-1, 0, n-1, 1) & query(0, r-n, 0, n-1, 1);

        // else if(l<0) res=query(0,n-1,0,r,1) & query(n+l,n-1,0,n-1,1);
        // else if(r>=n) res=(query(0,r-n,0,n-1,1) & query(l,n-1,0,n-1,1));
        else res= query(l,r,0,n-1,1);
        cout<<res<<" ";
    }
    print("")
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
