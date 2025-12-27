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
    int n,k,cnt=0;cin>>n>>k;
    vector<int> v(n);

    if(k<n)
    {
        cout<<0<<'\n';
        return;
    }

    for(int i=0;i<n;i++) v[i]=i+1;
    swap(v[0],v.back());
    k-=(n-1);


    int st=1;
    while(cnt<k)
    {
        if(cnt>=k) break;
        for(int i=n-1;i>st;i--)
        {
            swap(v[i],v[i-1]);
            
            
            cnt++;
            if(cnt==k) break;
            debug(v,cnt);
        }
        //cnt++;
        st++;
        //debug(v);
    }

    for(auto x : v) cout<<x<<' ';
    cout<<'\n';
    
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