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
    int n,ans1=0,ans2=0;cin>>n;
    vector<int> a,b;

    for(int i=0;i<n;i++)
    {
        char x;cin>>x;
        (x=='a') ? a.push_back(i) : b.push_back(i);
    }

    if(a.empty() || b.empty())
    {
        cout<<0<<'\n';
        return;
    }

    int mid_a=a.size()/2,mid_b=b.size()/2;

    // debug(a);
    // debug(b);
    // debug(mid_a,mid_b);

    for(int i=mid_a-1,tmp=a[a.size()/2]-1;i>=0;i--)
    {
        
        ans1+=(tmp-a[i]);
        //debug(tmp,i,ans1);
        tmp--;
    }

    for(int i=mid_a+1,tmp=a[a.size()/2]+1;i<a.size();i++,tmp++)
    {
        ans1+=(a[i]-tmp);
        //debug(tmp,i);
    } 

    // debug(b);
    // debug(b[b.size()/2]);

    for(int i=mid_b-1,tmp=b[b.size()/2]-1;i>=0;i--)
    {
        //cout<<"ARAFAT\n";
        
        ans2+=(tmp-b[i]);
        //debug(tmp,i,ans2);
        tmp--;
    }

    for(int i=mid_b+1,tmp=b[b.size()/2]+1;i<b.size();i++,tmp++)
    {
        ans2+=(b[i]-tmp);
        //debug(tmp,i);
    } 

    cout<<min(ans1,ans2)<<'\n';

    //debug(a,b,ans1,mid_a);
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