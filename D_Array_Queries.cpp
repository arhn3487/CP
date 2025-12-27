#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<int> v,seg;

void build(int left,int right,int node)
{
    if(left==right) 
    {
        seg[node]=v[left];
        return;
    }
    int mid=(left+right)/2;
    build(left,mid,2*node);
    build(mid+1,right,2*node+1);
    seg[node]=min(seg[2*node],seg[2*node+1]);
}

int get_min(int left,int right,int node,int l,int r)
{
    if(l>right || r<left) return INT_MAX;
    if(left>=l && r>=right) return seg[node]; //left l r right

    int mid=(left+right)/2;
    int x=get_min(left,mid,2*node,l,r);
    int y=get_min(mid+1,right,2*node+1,l,r);

    return min(x,y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    //cout<<t<<endl;;

    for(int tc=1;tc<=t;tc++)
    {
        int n,q;
        cin>>n>>q;
        v.resize(n+1);
        seg.assign(4*n,0);

        for(int i=1;i<=n;i++) cin>>v[i];
        //cout<<"sdfgh\n";
        build(1,n,1);

        cout<<"Case "<<tc<<":\n";

        while(q--)
        {
            int l,r;
            cin>>l>>r;

            cout<<get_min(1,n,1,l,r)<<endl;
        }
    }

    //cout<<"ghj\n";
}