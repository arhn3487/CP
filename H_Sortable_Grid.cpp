#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

vector<int>v,seg,segmn;
void build(int start,int end,int node) 
{ 
    if(start==end) {seg[node]=v[start];segmn[node]=v[start];return;  }

    //cerr<<"a";
 
    int mid=(start+end)/2; 
    build(start,mid,2*node); 
    build(mid+1,end,2*node+1); 
 
    seg[node]=max(seg[2*node],seg[2*node+1]); 
    segmn[node]=min(segmn[2*node],segmn[2*node+1]); 
} 
 
void update(int start,int end,int node,int ind,int val) 
{ 
    if(start==end) {seg[node]=val;segmn[node]=val;return; }                                                                                                                                                           
 
    int mid=(start+end)/2; 
    if(ind<=mid) update(start,mid,2*node,ind,val); 
    else update(mid+1,end,2*node+1,ind,val); 
     
    seg[node]=max(seg[2*node],seg[2*node+1]); 
    segmn[node]=min(segmn[2*node],segmn[2*node+1]);
} 
 
ll query(int start,int end,int node,int l,int r) 
{    
    if(r<start || l>end) return -1e18; 
    if(l<=start && r>=end) return seg[node];
    ll mid=(start+end)/2; 
    ll left = query(start,mid,2*node,l,r); 
    ll right = query(mid+1,end,2*node+1,l,r); 
    return max(left,right); 
}



ll querymn(int start,int end,int node,int l,int r) 
{    
    if(r<start || l>end) return infinity;  
    if(l<=start && r>=end) return segmn[node];
    int mid=(start+end)/2; 
    ll left = querymn(start,mid,2*node,l,r); 
    ll right = querymn(mid+1,end,2*node+1,l,r); 

    return min(left,right); 
}

void solve()
{
    ll n,m,q;cin>>n>>m>>q;
    vector<string> grid(n);

    for(auto &x : grid) cin>>x;
    v.assign(m,0);
    seg.resize(4*m);
    segmn.resize(4*m);

    for(int i=0;i<m;i++)
    {
        ll o=0;
        for(int j=0;j<n;j++)
        {
            if(grid[j][i]=='1') o++;
        }
        v[i]=o;
    }

    //cerr<<"ARAFAT\n";
    build(0,m-1,1);
    //debug(v);
    //debug(seg);

    while(q--)
    {
        ll a,b;cin>>a>>b;
        a--,b--;
        int val=(grid[a][b]=='1') ? -1 : 1;
        grid[a][b]=(grid[a][b]=='1') ? '0' : '1';
        v[b]+=val;
        update(0,m-1,1,b,v[b]);
        //debug(seg);
        //cout<<"ARAFAT\n";

        bool ok=true;
        
        if(query(0,m-1,1,0,b-1)>v[b]) ok =false;
        if(querymn(0,m-1,1,b+1,m-1)<v[b]) ok =false;

       


        // if(b-1 >= 0) ok = (query(0, m-1, 1, 0, b-1) <= v[b]);
        // if(b+1 < m) ok = ok && (querymn(0, m-1, 1, b+1, m-1) >= v[b]);

        
        yes(ok)
    }
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