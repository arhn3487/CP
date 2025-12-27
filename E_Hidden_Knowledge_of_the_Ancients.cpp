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
    ll n,k,l,r,i=0,j=0,ans1=0,ans2=0;cin>>n>>k>>l>>r;
    vector<int> v(n);
    map<int,int> mp;

    for(auto &x : v) cin>>x;

    while(j<n)
    {
        mp[v[j]]++;

        while(i<=j && mp.size()>k)
        {
            mp[v[i]]--;
            if(mp[v[i]]==0) 
            {
                mp.erase(v[i]);
                //i++;
            }
            i++;
        }

        ans1+=max(0LL,min(j-i+1,r)-l+1LL);
        j++;
    }

    k--;
    i=0,j=0;
    mp.clear();

    while(j<n)
    {
        mp[v[j]]++;

        while(i<=j && mp.size()>k)
        {
            mp[v[i]]--;
            if(mp[v[i]]==0) 
            {
                mp.erase(v[i]);
                
            }
            i++;
        }

        ans2+=max(0LL,min(j-i+1,r)-l+1LL);
        j++;
    }

    //debug(ans1,ans2);
    cout<<ans1-ans2<<'\n';
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