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
    int n,m;
    cin>>n;
    vector<int> a(n),b(n);
    map<int,int> need;

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) 
    {
        cin>>b[i];
        if(a[i]!=b[i]) need[b[i]]++;
    }
    cin>>m;
    bool flag=false;
    vector<int> d(m);
    for(int i=0;i<m;i++)
    {
        cin>>d[i];
        if(need[d[i]]) need[d[i]]--;
        else flag=true;
    }

    for(auto [x,y] : need)
    {
        if(y)
        {
            cout<<"NO\n";
            return;
        }
    }
    // if(a==b)
    // {
    //     YES
    //     return;
    // }
    // if(need[d[m-1]]==0)
    // {
    //     NO
    //     return;
    // }

    bool found=false;
    for(auto x : b)
    {
        if(x==d[m-1])
        {
           found=true;
           break;
        }
    }
    if(!found)
    {
        cout<<"NO\n";
        return;
    }
    YES
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