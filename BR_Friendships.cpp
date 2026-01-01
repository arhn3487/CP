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
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve()
{
    int n,k;cin>>n>>k;
    vector<array<int,2>> v;

    int possible =(n-1)*(n-2)/2;

    if(possible<k)
    {
        cout<<-1<<'\n';
        return;
    }

    for(int i=2;i<=n;i++)
    {
        v.push_back({1,i});
    }

    for(int i=2;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(possible==k)
            {
                i=n;
                break;
            }

            possible--;
            v.push_back({i,j});
        }
    }

    cout<<v.size()<<'\n';
    for(auto [x,y] : v) cout<<x<<' '<<y<<'\n';
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