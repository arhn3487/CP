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

ll n,s;
vector<ll> v;

ll find(ll k)
{
    vector<ll> vec(n);
    ll sum=0;
    for(int i=0;i<n;i++) vec[i]=v[i]+(i+1)*k;
    sort(all(vec));

    //debug(k,vec);

    for(int i=0;i<k;i++) sum+=vec[i];
    return sum;
}

void solve()
{
    ll min_cost=LLONG_MAX,mx_element=0;
    cin>>n>>s;
    v.resize(n);

    for(auto &x : v) cin>>x;

    ll lo=0,hi=n;

    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        ll sum=find(mid);

        if(s>=sum)
        {
            //s=sum;
            lo=mid+1;
            //debug(mid,mx_element,sum);
            if(mid>=mx_element)
            {
                if(mid==mx_element) min_cost=min(min_cost,sum);
                else min_cost=sum;
                mx_element=mid;
            }
        }
        else
        {
            hi=mid-1;
        }
    }

    cout<<mx_element<<" "<<min_cost<<'\n';
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