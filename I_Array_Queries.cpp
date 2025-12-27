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

vector<int> v,seg;

void build(int i,int j,int node)
{
    //cout<<"ar\n";
    if(i==j) 
    {
        seg[node]=v[i];
        return;
    }
    int mid=(i+j)/2;
    build(i,mid,2*node);
    build(mid+1,j,2*node+1);
    seg[node]= min(seg[2*node],seg[2*node+1]);
}

int find(int qr_i,int qr_j,int range_i,int range_j,int node)
{
    //qj...ragi...qi...qj....rj
    // if(range_i>=qr_i && qr_j<=range_j) return seg[node];
    // if(qr_j<range_i || qr_i>range_j) return 0;

    if (qr_i <= range_i && range_j <= qr_j) return seg[node]; 
    if (qr_j < range_i || qr_i > range_j) return INT_MAX;

    int mid=(range_i+range_j)/2;
    int left=find(qr_i,qr_j,range_i,mid,2*node);
    int right=find(qr_i,qr_j,mid+1,range_j,2*node+1);

    return min(left,right);
}

void solve()
{
    int n,q;
    cin>>n>>q;
    v.resize(n);
    seg.assign(4*n,0);

    for(auto &x : v) cin>>x;

    build(0,n-1,1);

    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;

        print(find(a,b,0,n-1,1))
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<":\n";
        solve();
    }
}