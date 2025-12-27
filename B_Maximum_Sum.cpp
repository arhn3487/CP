#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
//#include "D:/debug.h"
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

#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

struct Node
{
    int mx1=0,mx2=0;
};

vector<Node> seg;
vector<int> v;

void build(int i,int j,int node)
{
    //cout<<i<<endl;
    if(i==j)
    {
        seg[node].mx1=v[i];
        seg[node].mx2=0;
        return;
    }

    int mid=(i+j)/2;
    build(i,mid,2*node);
    build(mid+1,j,2*node+1);
    int arr[4];
    arr[0]=seg[2*node].mx1,arr[1]=seg[2*node].mx2,arr[2]=seg[2*node+1].mx1,arr[3]=seg[2*node+1].mx2;
    sort(arr,arr+4);
    seg[node].mx1=arr[3];
    seg[node].mx2=arr[2];
}

Node find(int i,int j,int range_i,int range_j,int node)
{
    if(range_i<=i && range_j>=j) return seg[node];
    if(j<range_i || range_j<i) return {0,0};

    //cout<<i<<" "<<j<<endl;

    int mid=(i+j)/2;
    Node left=find(i,mid,range_i,range_j,2*node);
    Node right=find(mid+1,j,range_i,range_j,2*node+1);

    vector<int> arr={left.mx1,left.mx2,right.mx1,right.mx2};
    sort(all(arr));
    //debug(left,right);
    return {arr[2],arr[3]};
}

void update(int i,int j,int index,int node,int val)
{
    if(i==j)
    {
        seg[node].mx1=val;
        seg[node].mx2=0;
        return;
    }

    int mid=(i+j)/2;

    if(index<=mid) update(i,mid,index,2*node,val);
    else update(mid+1,j,index,2*node+1,val);

    int arr[4];
    arr[0]=seg[2*node].mx1,arr[1]=seg[2*node].mx2,arr[2]=seg[2*node+1].mx1,arr[3]=seg[2*node+1].mx2;
    sort(arr,arr+4);
    seg[node].mx1=arr[3];
    seg[node].mx2=arr[2];
}

void solve()
{
    int n,q;
    cin>>n;
    v.resize(n);
    seg.assign(4*n, {0, 0});


    for(auto &i : v) cin>>i;
    build(0,n-1,1);

    cin>>q;

    while(q--)
    {
        char c;
        int a,b;
        cin>>c>>a>>b;
        a--;

        if(c=='Q')
        {
            b--;
            Node res =find(0,n-1,a,b,1);
            cout<<res.mx1+res.mx2<<'\n';
        }
        else update(0,n-1,a,1,b);
    }
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
