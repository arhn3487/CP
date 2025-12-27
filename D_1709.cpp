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
    int n;cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<pair<int,int>> res;

    //  for(int i=0;i<n;i++)
    // {
    //     for(int j=i;j<n;j++)
    //     {
    //         if(a[j]>b[j])
    //         {
    //             swap(a[j], b[j]);
    //             res.push_back({3,j});
    //         }
    //     }
    // }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j], a[j+1]);
                res.push_back({1,j+1});
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(b[j]<b[j+1])
            {
                swap(b[j], b[j+1]);
                res.push_back({2,j+1});
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n-1;j++)
    //     {
    //         if(b[j]<n)
    //         {
    //             swap(a[j], b[j]);
    //             res.push_back({2,j+1});
    //         }
    //     }
    // }

    for(int i=0;i<n;i++)
    {
        if(a[i]>n)
        {
            swap(a[i], b[i]);
            res.push_back({3,i+1});
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j], a[j+1]);
                res.push_back({1,j+1});
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(b[j]<b[j+1])
            {
                swap(b[j], b[j+1]);
                res.push_back({2,j+1});
            }
        }
    }
   

    cout<<res.size()<<"\n";

    for(auto [x, y] : res)
    {
        cout<<x<<" "<<y<<"\n";
    }
    for(auto x : a) cout<<x<<" ";
    cout<<"\n";
    for(auto x : b) cout<<x<<" ";
    cout<<"\n";
    cout<<"\n";
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