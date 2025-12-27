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
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

int f=0,n;
string s;

void dfs(int even,int odd,int total,int flag,vector<int> &v,int last)
{
    //cerr<<"ARAFAT\n";
    if(f) return;
    if(total==n)
    {
        if(f) return;
        yes(1)
        for(auto x : v) cout<<x<<' ';
        cout<<'\n';
        f=1;
        return;
    }
    if(flag)
    {
        for(int i=0;i<10;i++)
        {
            if((s[i]=='1') && ((even+i+1)>odd) && (last!=i+1)) 
            {
                v.push_back(i+1);
                dfs(even+i+1,odd,total+1,flag^1,v,i+1);
                v.pop_back();
            }
        }
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            if((s[i]=='1') && ((odd+i+1)>even) && (last!=i+1)) 
            {
                v.push_back(i+1);
                dfs(even,odd+i+1,total+1,flag^1,v,i+1);
                v.pop_back();
            }
        }
    }
}

void solve()
{
    cin>>s>>n;
    vector<int> v;
    dfs(0,0,0,1,v,0);
    if(!f) yes(0)
}

int32_t main()
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