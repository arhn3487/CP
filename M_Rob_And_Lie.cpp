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
    int n,cnt=0;cin>>n;
    map<int,int> mp;
    vector<set<int>> v(n+1);

    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        int l=-a+i,r=a+i;
        if(l>0 && l<=n) v[l].insert(i);
        if(r>0 && r<=n) v[r].insert(i);
        if(l>0 && l<=n) mp[l]++;
        if(r>0 && r<=n) mp[r]++;
        // mp[-a+i]++;
        // mp[-a-i]++;
    }

    debug(v);

    for(int i=0;i<=n;i++)
    {
        if(v[i].size()==n-1) cnt++;
    }

    if(cnt!=1)
    {
        cout<<-1<<'\n';
        return;
    }
    for(int i=0;i<=n;i++)
    {
        if(v[i].size()==n-1) 
        {
            cout<<i<<'\n';
            return;
        }
    }

    // for(auto [x,y] : v)
    // {
    //     if(y.size()==n-1)
    //     {
    //         cout<<abs(x)<<'\n';
    //         return;
    //     }
    // }

    cout<<-1<<'\n';

    
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
        //cout<<"Case "<<i<<": ";
        solve();
    }
}