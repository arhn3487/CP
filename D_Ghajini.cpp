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


#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
int n,d;
vector<int> seg_mn,seg_mx,v;

int build1(int i,int j,int node)
{
    if(i==j) return seg_mx[node]=v[i];
    int mid=(i+j)/2;
    int left=build1(i,mid,2*node);
    int right = build1(mid+1,j,2*node+1);

    return seg_mx[node]=max(left,right);
}

int build2(int i,int j,int node)
{
    if(i==j) return seg_mn[node]=v[i];
    int mid=(i+j)/2;
    int left=build2(i,mid,2*node);
    int right = build2(mid+1,j,2*node+1);

    return seg_mn[node]=min(left,right);
}

int find_mx(int qi,int qj,int range_i,int range_j,int node)
{
    //print("arafat")
    if(qi<=range_i && range_j<=qj) return seg_mx[node];
    if(qi>range_j || qj<range_i) return INT_MIN;
    int mid=(range_i+range_j)/2;

    int left=find_mx(qi,qj,range_i,mid,2*node);
    int right=find_mx(qi,qj,mid+1,range_j,2*node+1);

    //cout<<left<<right<<endl;

    return max(left,right);
}

int find_mn(int qi,int qj,int range_i,int range_j,int node)
{
    //print("arafat")
    if(qi<=range_i && range_j<=qj) return seg_mn[node];
    if(qi>range_j || qj<range_i) return INT_MAX;
    int mid=(range_i+range_j)/2;

    int left=find_mn(qi,qj,range_i,mid,2*node);
    int right=find_mn(qi,qj,mid+1,range_j,2*node+1);

    //cout<<left<<right<<endl;

    return min(left,right);
}

void solve()
{
    cin>>n>>d;
    v.resize(n);
    seg_mn.assign(4*n,INT_MAX);
    seg_mx.assign(4*n,0);

    for(auto &x : v) cin>>x;

    build1(0,n-1,1);
    build2(0,n-1,1);

    int ans=0;

    for(int i=0;i<n-d;i++)
    {
        int res=abs(find_mn(i,i+d-1,0,n-1,1)-find_mx(i,i+d-1,0,n-1,1));
        ans=max(res,ans);
    }
    print(ans)
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
        cout<<"Case "<<i<<": ";
        solve();
    }
}
