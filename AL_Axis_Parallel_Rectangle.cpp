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

void solve()
{
    ll n,k,best=LLONG_MAX;cin>>n>>k;
    vector<pair<ll,ll>> points(n);
    vector<ll> xx;

    for(auto &[x,y] : points) 
    {
        cin>>x>>y;
        xx.push_back(x);
    }

    sort(all(xx));
    xx.erase(unique(all(xx)),xx.end());

    for(ll i=0;i<n;i++)
    {
        for(ll j=i;j<n;j++)
        {
            ll lx=xx[i],rx=xx[j];

            vector<ll> yy;

            for(ll l=0;l<n;l++)
            {
                if(points[l].first>=lx && points[l].first<=rx) 
                    yy.push_back(points[l].second);
            }

            sort(all(yy));

            if(yy.size()<k) continue;

            ll minyspan=LLONG_MAX;

            for(ll l=k-1;l<yy.size();l++)
            {
                minyspan=min(minyspan,yy[l]-yy[l-(k-1)]);
            }

            best=min(best,minyspan*(rx-lx));
        }
    }


    cout<<best<<'\n';

}

int main()
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