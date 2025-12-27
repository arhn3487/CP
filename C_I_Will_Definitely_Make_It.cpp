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
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

void solve()
{
    int n,k;
    cin>>n>>k;
    int arr[n];

    for(auto &x : arr) cin>>x;

    int agai_asi=arr[k-1]-1;

    sort(arr, arr + n);

    int mx_gap=0;

    

    for(int i=1;i<n;i++) mx_gap=max(mx_gap, arr[i]-arr[i-1]);

    

    //cout<<mx_gap<<" "<<agai_asi<<endl;

    if(mx_gap-1<=agai_asi) cout<<"YES\n";
    else cout<<"NO\n";

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