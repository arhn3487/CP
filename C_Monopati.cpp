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
    int n,mx=-1,mn=infinity,cnt=0;cin>>n;
    vector<array<int,2>> v(n),upore(n),niche(n);//mx,mn
    //set<array<int,2>> st;
    vector<int> ans(2*n+1,infinity);

    for(int i=0;i<n;i++) 
    {
        cin>>v[i][0];
        mx=max(v[i][0],mx);
        mn=min(v[i][0],mn);
        upore[i][0]=mx;
        upore[i][1]=mn;
    }
    for(int i=0;i<n;i++) cin>>v[i][1];

    
    mx=-1,mn=infinity;
    for(int i=n-1;i>=0;i--)
    {
        mx=max(v[i][1],mx);
        mn=min(v[i][1],mn);
        niche[i][0]=mx;
        niche[i][1]=mn;
    }

    for(int i=0;i<n;i++)
    {
        int u_max=max(upore[i][0],niche[i][0]),u_min=min(upore[i][1],niche[i][1]);
        //int l=u_min,r=2*n-u_max+1;
        // if(u_min && u_max)
        //     st.insert({u_min,u_max});
        // // cnt+=l*r;
        // // debug(cnt,l,r,u_max,u_min,i);
        // debug(u_max,u_min);
        if(u_min && u_max)
            ans[u_min]=min(ans[u_min],u_max);
    }

    // debug(ans);

    // for(int i=0;i<n;i++) cerr<<upore[i][0]<<' ';
    // cerr<<'\n';
    // for(int i=0;i<n;i++) cerr<<upore[i][1]<<' ';
    // cerr<<'\n';
    // for(int i=0;i<n;i++) cerr<<niche[i][0]<<' ';
    // cerr<<'\n';
    // for(int i=0;i<n;i++) cerr<<niche[i][1]<<' ';

    // debug(st);

    int tmp=infinity;

    for(int i=2*n;i>=1;i--)
    {
        if(ans[i]==infinity && tmp==infinity) continue;
        tmp=min(tmp,ans[i]);
        cnt+=(2*n-tmp+1);
    }

    // for(auto [x,y] : st)
    // {
    //     debug(2*n-y+1);
    //     cnt+=(x*(2*n-y+1));
    // }

    cout<<cnt<<'\n';
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