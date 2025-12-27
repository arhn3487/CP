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

int ask(int a,int b)
{
    cout<<"? "<<a<<' '<<b<<endl;
    int k;cin>>k;
    return k;
}

void solve()
{
    int n,q,ans=0;cin>>n>>q;
    vector<int> left(n+1,infinity),right(n+1,-1);

    for(int i=0;i<q;i++)
    {
        int a,b;cin>>a>>b;
        left[b]=min(a,left[b]);
        right[a]=max(b,right[a]);
    }

    int k=ask(1,n/2) ? 1 : 0;

    if(!k)
    {
        for(int i=n/2+1;i<=n;i++)
        {
            if(left[i]!=infinity)
                ans=max(ans,ask(left[i],i));
        }
    }
    else 
    {
        for(int i=1;i<=n/2;i++)
        {
            if(right[i]!=-1)
                ans=max(ans,ask(i,right[i]));
        }
    }

    cout<<"! "<<ans<<endl;
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