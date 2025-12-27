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
    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    for(int i=0;i<n-1;i++)
    {
        if(abs(v[i]-v[i+1])<=1)
        {
            cout<<0<<'\n';
            return;
        }
    }

    int ans=INT_MAX;

    for(int i=0;i<n;i++)
    {
        int left=i,right=n-i-1;

        if(left>1)
        {
            int cnt=1,mn=min(v[i-1],v[i-2]),mx=max(v[i-1],v[i-2]);

            for(int j=i-3;j>=0;j--)
            {
                if(v[i]>=mn && v[i]<=mx) ans=min(ans,cnt);
                cnt++;
                mn=min(mn,v[j]);
                mx=max(mx,v[j]);
            }

            if(v[i]>=mn && v[i]<=mx) ans=min(ans,cnt);
        }

        if(right>1)
        {
            int cnt=1,mn=min(v[i+1],v[i+2]),mx=max(v[i+1],v[i+2]);

            for(int j=i+3;j<n;j++)
            {
                if(v[i]>=mn && v[i]<=mx) ans=min(ans,cnt);
                cnt++;
                mn=min(mn,v[j]);
                mx=max(mx,v[j]);
            }

            if(v[i]>=mn && v[i]<=mx) ans=min(ans,cnt);
        }
    }

    ans = (ans == INT_MAX) ? -1 : ans;

    cout<<ans<<'\n';
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