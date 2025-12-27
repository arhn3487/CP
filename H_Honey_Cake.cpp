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
    ll a,b,c,n;cin>>a>>b>>c>>n;
    ll vol=a*b*c;

    if(vol%n)
    {
        cout<<-1<<'\n';
    }

    map<ll,bool> da,db,dc;

    for(int i=1;i*i<M;i++)
    {
        if(a%i==0)
        {
            da[i]=true;
            if(i*i!=a) da[a/i]=true;
        }
        if(b%i==0)
        {
            db[i]=true;
            if(i*i!=b) db[b/i]=true;
        }
        if(c%i==0)
        {
            dc[i]=true;
            if(i*i!=c) dc[c/i]=true;
        }
    }

    debug(da);
    debug(db);
    debug(dc);
    debug(vol);

    ll aaa=vol/n;
    debug(aaa);

    for(auto [x,y] : da)
    {
        for(auto [p,q] : db)
        {
            debug(x);
            ll need=aaa/(p*x);
            debug(x,p,need);
            if(dc.find(need)!=dc.end())
            {
                debug(x,p,need);
                cout<<a/x-1<<' '<<b/p-1<<' '<<c/need-1<<'\n';
                return;
            }
        }
    }

    cout<<-1<<'\n';

    debug(da,db,dc);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}