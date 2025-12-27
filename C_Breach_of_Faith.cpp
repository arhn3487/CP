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

void solve()
{
    int n;
    ll s=0;
    cin>>n;

    vector<int> a(n*2),boro,soto;

    for(int i=0;i<2*n;i++) cin>>a[i];

    sort(all(a));

    for(int i=1;i<n;i++) {soto.push_back(a[i]);s-=a[i];}//n-1
    for(int i=n;i<2*n-1;i++) {boro.push_back(a[i]);s+=a[i];}//n
    boro.push_back(a[0]);
    soto.push_back(a[2*n-1]);

    cout<<boro.size()<<"b"<<soto.size()<<endl;
    ll a1=s+a[0]+a[2*n-1];
    cout<<a1<<' ';
    // for(int i=0;i<n;i++) 
    // {
    //     cout<<' '<<boro[i]<<' '<<soto[i];
    // }
    //cout<<a[0]<<" "<<a[2*n-1]<<'\n';
    print("");
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
        //cout<<"Case "<<i<<": ";
        solve();
    }
}