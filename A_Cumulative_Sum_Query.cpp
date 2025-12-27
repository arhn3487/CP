#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<int>v,seg;

int build(int start,int end,int node)
{
    if(start==end) return seg[node]=v[start]; 

    int mid=(start+end)/2;
    int left = build(start,mid,2*node);
    int right = build(mid+1,end,2*node+1);

    return seg[node]=left+right; // seg[node]=seg[2*node]+seg[2*node+1] can be used
}

void update(int start,int end,int node,int ind,int val)
{
    if(start==end && end==ind) seg[node]+=val; //end == ind is optional

    int mid=(start+end)/2;
    if(ind<=mid) update(start,mid,2*node,ind,val); //update the left sub-tree
    else update(mid+1,end,2*node+1,ind,val); //update the right sub-tree
    
    seg[node]=seg[2*node]+seg[2*node+1]; //update the root for left and right sub-tree
}

int query(int start,int end,int node,int l,int r)
{   
    //l for left of range in query r for right of range in query
    if(r<start || l>end) return 0; // l..r...start...end or start...end...l...r
    if(l<=start && r>=end) return seg[node]; //l...start...end...r

    int mid=(start+end)/2;
    int left = query(start,mid,2*node,l,r);
    int right = query(mid+1,end,2*node+1,l,r);
    return left+right;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    v.resize(n+1);
    seg.assign(4*n,0);

    for(int i=1;i<=n;i++) cin>>v[i];
    build(1,n,1);

    //for(auto x : seg) cout<<x<<" ";

    int q,l,r;
    cin>>q;

    while(q--)
    {
        cin>>l>>r;
        cout<<query(1,n,1,l+1,r+1)<<endl;
    }
}