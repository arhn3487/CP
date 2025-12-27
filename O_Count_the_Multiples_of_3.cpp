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
//const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
//inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

vector<array<int,3>({0,0,0})> seg,lazy;
vector<int> v;

void build(int i,int j,int node)
{
    if(i==j){
        seg[node][v[i]]++;
    }
    int mid=(i+j)>>1;
    build(i,mid,2*node);
    build(mid+1,j,2*node+1);

    for(int i=0;i<3;i++) seg[node][i]=seg[2*node][i]+seg[2*node+1][i];
}

void propagate(int i,int j,int node)
{
    if(lazy[node]!=array<int,3>{0,0,0})
    {
        for(int k=0;k<3;k++) seg[node][k]+=lazy[node][k]*(j-i+1);
        if(i!=j){
            for(int k=0;k<3;k++){
                lazy[2*node][k]+=lazy[node][k];
                lazy[2*node+1][k]+=lazy[node][k];
            }
        }
        lazy[node]=array<int,3>{0,0,0};
    }
    
}

void update(int i,int j,int range_i,int range_j,int node,int val)
{
    //cout<<"ARAFAT\n";
    propagate(range_i,range_j,node);
    if(i>range_j || j<range_i) return;
    if(i<=range_i && j>=range_j) 
    {   
        array<int,3> a=lazy[node];
        for(int i=1;i<4;i++) seg[node][i%3]=a[i-1];
        propagate(range_i,range_j,node);
        return;
    }

    int mid=(range_i+range_j)>>1;
    update(i,j,range_i,mid,2*node,val);
    update(i,j,mid+1,range_j,2*node+1,val);
    //seg[node]=seg[2*node]+seg[2*node+1];
    for(int i=0;i<3;i++) seg[node][i]=seg[2*node][i]+seg[2*node+1][i];
}




int query(int qi,int qj,int range_i,int range_j,int node)
{
    //cout<<qi<<" "<<qj<<" "<<range_i<<" "<<range_j<<'\n';
    propagate(range_i,range_j,node);
    if(qi>range_j || qj<range_i) return 0;
    if(qi<=range_i && qj>=range_j) return seg[node];
    int mid=(range_i+range_j)>>1;

    return query(qi,qj,range_i,mid,2*node)+query(qi,qj,mid+1,range_j,2*node+1);
}

void solve()
{
    int n,q;
    cin>>n>>q;
    v.resize(n);
    seg.assign(4*n,0);
    lazy.assign(4*n,0);

    for(auto &x : v)
    {
        cin>>x;
        x%=3;
    }
    build(0,n-1,1);

    while(q--)
    {
        int a,x,y,z,res;
        cin>>a;
        if(a==0)
        {
            cin>>x>>y>>z;
            update(x,y,0,n-1,1,z);
        }
        else{
            cin>>x>>y;
            res=query(x,y,0,n-1,1);
            print(res)
        }
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
        cout<<"Case "<<i<<":\n";
        solve();
    }
}