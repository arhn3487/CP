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
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<int> seg(4*(1<<18)),v(1<<18);

void build(int l,int r,int ind,int is_or)
{
    if(l==r) 
    {
        seg[ind]=v[l];
        return;
    }

    int mid=(l+r)/2;

    build(l,mid,2*ind,!is_or);
    build(mid+1,r,2*ind+1,!is_or);
    
    if(is_or) seg[ind]=seg[2*ind]|seg[2*ind+1];
    else seg[ind]=seg[2*ind]^seg[2*ind+1];
}

void update(int l,int r,int ind,int p,int val,int is_or)
{
    if(l==r) 
    {
        seg[ind]=val;
        return;
    }

    int mid=(l+r)/2;

    if(p<=mid)update(l,mid,2*ind,p,val,!is_or);
    else update(mid+1,r,2*ind+1,p,val,!is_or);
    
    if(is_or) seg[ind]=seg[2*ind]|seg[2*ind+1];
    else seg[ind]=seg[2*ind]^seg[2*ind+1];
}
void solve()
{
    int n,q;cin>>n>>q;
    int k=(1<<n)-1,g=n%2;

    for(int i=0;i<(1<<n);i++) cin>>v[i];

    build(0,k,1,n%2);

    while (q--)
    {
        int a,b;cin>>a>>b;
        update(0,k,1,a-1,b,n%2);
        cout<<seg[1]<<'\n';
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