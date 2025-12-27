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
const int M=1000005;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

int arr[M]={};

void solve()
{
    int n;
    cin>>n;
    

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a]++;
        arr[b+1]--;
    }

    int mx=arr[0];

    for(int i=1;i<M;i++)
    {
        arr[i]+=arr[i-1];
        mx=max(mx,arr[i]);
    }

    //for(int i=0;i<10;i++) cout<<i<<" -> "<<arr[i]<<"\n";

    cout<<mx<<'\n';
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