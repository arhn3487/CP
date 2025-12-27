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
    bool pos=true;
    int n;
    cin>>n;
    vector<pair<int,int>> v(n),res(n);
    vector<int> d(n);

    for(auto &x : d) cin>>x;

    for(auto &[x,y] : v) cin>>x>>y;

    for(int i=1;i<n;i++)
    {
        if(v[i].second<v[i-1].first || v[i].first>v[i-1].second)
        {
            cout<<-1<<'\n';
            return;
        }
        v[i].first = max(v[i].first, v[i-1].first);
        v[i].second = min(v[i].second, v[i-1].second);
    }

    int hi=0,lo=0;

    for(int i=0;i<n;i++)
    {
        if(d[i]==1) lo++,hi++;
        else if(d[i]==-1) hi++;

        int valid_lo=max(lo,v[i].first);
        int valid_hi=min(hi,v[i].second);

        debug(valid_lo, valid_hi,lo,hi);

        if(valid_lo>valid_hi)
        {
            pos=false;
            break;
        }

        res[i]={valid_lo, valid_hi};
        lo=valid_lo,hi=valid_hi;
    }

    cout<<lo<<" "<<hi<<'\n';
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
