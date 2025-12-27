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
    int n,mx=0,mn=INT_MAX,sum=0;
    cin>>n;
    vector<int>v(n),res;
    iota(v.begin(),v.end(),1);
    reverse(all(v));

    for(int i=0;i<n;i++) sum+=abs(v[i]-i-1);

    //cout<<sum<<endl;

    cout<<sum/2+1<<endl;

    // while(next_permutation(v.begin(),v.end()))
    // {
    //     int sum=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         sum+=abs(v[i]-i-1);
    //         if(mx<sum) 
    //         {
    //             res=v;
    //         }
    //         mx=max(sum,mx);
    //         mn=min(sum,mn);
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         cout<<v[i]<<" ";
    //     }
    //     cout<<"   "<<sum<<'\n';
    // }

    // cout<<mx<<" "<<mn<<'\n';

    
   // for(auto x : res) cout<<s
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