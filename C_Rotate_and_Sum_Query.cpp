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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

#define int long long

void solve()
{
    int n,q,ind=0;
    cin>>n>>q;
    vector<int> v(n),pre(n,0);

    for(auto &x : v) cin>>x;
    pre[0]=v[0];

    for(int i=1;i<n;i++) pre[i]=pre[i-1]+v[i];

    while(q--)
    {
        int c,l,r;
        cin>>c>>l;
        if(c==1)
        {
            ind=(ind+l)%n;
        }
        else
        {
            cin>>r;
            int lll=l+ind-1,rrr=r+ind-1;
            lll%=n,rrr%=n;
            if(lll<=rrr)
            {
                if(lll!=0) cout<<pre[rrr]-pre[lll-1]<<'\n';
                else cout<<pre[rrr]<<'\n';
            }
            else 
            {
                ll tmp= pre[n-1];
                if(lll!=0) tmp-=pre[lll-1];
                tmp+=pre[rrr];
                cout<<tmp<<'\n';
            }
        }
    }
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