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
    int n,s;cin>>n>>s;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(n==1)
    {
        cout<<abs(s-v[0])<<"\n";
        return;
    }
    int left=abs(v[0]-s), right=abs(v[n-1]-s);
    if(v[0]>s) left=0;
    if(v[n-1]<s) right=0;
    cout<<2*min(left,right)+max(left,right)<<"\n";
    //cout<<"l "<<left<<" r "<<right<<"\n";
    //cout<<2*min(s-1,n-s)+max(n-s,s-1)<<"\n";
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