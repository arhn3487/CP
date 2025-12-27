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
    int n;
    bool f=false,f1=true;
    string s,t;
    cin>>n>>s>>t;
    vector<int> v;

    for(int i=0;i<n;i++)
    {
        if(f && s[i]=='0')
        {
            v.push_back(i);
            s[i]='1';
        }
        // if(s[i]!=t[i] && !f)
        // {
        //     print(-1)
        //     return;
        // }
        if(s[i]=='1') f=true;
    }

    for(int i=0;i<n;i++)
    {
        if(s[i]!='1')
        {
            if(s[i]!=t[i])
            {
                print(-1)
                return;
            }
        }
        else break;
    }

    for(int i=n-1;i>0;i--)
    {
        if(s[i]!=t[i])
        {
            v.push_back(i);
        }
    }

    cout<<v.size()<<'\n';
    for(auto x :v) cout<<x<<" ";
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