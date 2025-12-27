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
    int n,ans=INT_MAX;cin>>n;
    string s;cin>>s;
    vector<int> pre(n,0),suf(n,0);
    unordered_map<int,set<int>> mp;

    suf[n-1]= (s[n-1]=='a') ? 1 : -1;
    mp[suf[n-1]].insert(n-1);
    for(int i=n-2;i>=0;i--)
    {
        suf[i] = (s[i]=='a') ? suf[i+1]+1 : suf[i+1]-1;
        mp[suf[i]].insert(i);
        if(suf[i]==0) ans=min(ans,i);
        //debug(mp);
    }

    if(count(all(s),'a')*2==n)
    {
        cout<<0<<'\n';
        return;
    }

    //debug(mp);
    
    pre[0]=(s[0]=='b') ?1 : -1;

    for(int i=1;i<n;i++)
    {
        pre[i]= (s[i]=='b') ? pre[i-1]+1 :pre[i-1]-1;
        if(pre[i]==0) ans=min(ans,n-i-1);
    }

    for(int i=0;i<n;i++)
    {
        if(mp.count(pre[i]))
        {
            auto it=*mp[pre[i]].lower_bound(i);
            if(i<it)
            ans=min(ans,it-i-1);
            //debug(ans,i,it);
        }

    }

    ans=max(ans,0);
    ans=(ans==INT_MAX) ? -1 : ans;

    print(ans)
    
    // debug(suf);
    // debug(pre);
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