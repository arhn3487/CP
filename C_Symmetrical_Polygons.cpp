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
    ll n,cnt=0,sum=0;cin>>n;
    map<ll,ll> mp;
    vector<ll> v;
    
    for(int i=0;i<n;i++)
    {
        ll a;cin>>a;
        mp[a]++;
    }

    for(auto [x,y] : mp)
    {
        sum+=x*y;
        cnt+=y;
        if(y&1LL)
        {
            cnt--;
            sum-=x;
            v.push_back(x);
        } 
    }

    if(cnt==0)
    {
        cout<<0<<'\n';
        return;
    }

    if(v.empty())
    {
        if(cnt>2) cout<<sum<<'\n';
        else cout<<0<<'\n';
        return;
    }

    ll ans1=sum,ans2=sum,cnt1=0,cnt2=0,ans=0;

    for(auto x : v)
    {
        if(x<sum) 
        {
            ans1=max(ans1,sum+x);
            cnt1=1;
        }
    }

    for(int i=0;i<v.size();i++)
    {
        ll tmp=sum+v[i];
        ll ind=lower_bound(all(v),tmp)-v.begin();
        ind--;
        //debug(ind);
        if(ind>i)
        {
            ans2=max(ans2,tmp+v[ind]);
            cnt2=1;
        }
    }

    if(cnt==2)
    {
        if(cnt1 || cnt2) cout<<max(ans1,ans2)<<'\n';
        else cout<<0<<'\n';
        return;
    }

    // if(cnt2 && cnt)
    // {
    //     cout<<max(ans1,ans2)<<'\n';
    //     return;
    // }

    // debug(ans1,ans2,cnt);

    cout<<max(ans1,ans2)<<'\n';
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