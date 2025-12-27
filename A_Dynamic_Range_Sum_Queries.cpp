#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
const int M=2e5+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

#define int ll

vector<int>v(M),seg(4*M);
 
int build(int start,int end,int node) 
{ 
    if(start==end) return seg[node]=v[start];  
 
    int mid=(start+end)/2; 
    int left = build(start,mid,2*node); 
    int right = build(mid+1,end,2*node+1); 
 
    return seg[node]=left+right;
} 
 
void update(int start,int end,int node,int ind,int val) 
{ 
    if(start==end && end==ind) 
    {
        seg[node]=val; 
        return;
    }
    int mid=(start+end)/2; 
    if(ind<=mid) update(start,mid,2*node,ind,val); 
    else update(mid+1,end,2*node+1,ind,val);
    seg[node]=seg[2*node]+seg[2*node+1]; 
} 
 
int query(int start,int end,int node,int l,int r) 
{    
    if(r<start || l>end) return 0;  
    if(l<=start && r>=end) return seg[node]; 
 
    int mid=(start+end)/2; 
    int left = query(start,mid,2*node,l,r); 
    int right = query(mid+1,end,2*node+1,l,r); 
    return left+right; 
} 


void solve()
{
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++) cin>>v[i];

    build(0,n-1,1);
    //cerr<<"ARAFAT\n";
    

    // for(int i=0;i<n;i++)  cout<<v[i]<<' ';
    // cout<<'\n';

    while(q--)
    {
        int a,b,c;cin>>a>>b>>c;
        if(a==1)
        {
            //cerr<<"ARAFA  T\n";
            update(0,n-1,1,b-1,c);
            //cerr<<"ARAFA  T\n";
        }
        else cout<<query(0,n-1,1,b-1,c-1)<<'\n';
    }
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