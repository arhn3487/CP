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
const int M=1e9+7;
//const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
//inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(i%2) v[i]*=-1;
    }

    mp[v[0]]++;
    mp[0]++;

    for(int i=1;i<n;i++)
    {
        int num=v[i]+v[i-1];
        if(mp[num])
        {
            //cout<<i<<" "<<num<<'\n';
            YES
            return;
        }
        v[i]=num;
        mp[num]++;
    }

    NO
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