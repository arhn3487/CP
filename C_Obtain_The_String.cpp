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
    string s,t;
    cin>>s>>t;
    vector<vector<int>> v(26);

    for(int i=0;i<s.length();i++) v[s[i]-'a'].push_back(i);

    for(auto x : t)
    {
        if(v[x-'a'].empty())
        {
            print(-1)
            return;
        }
    }

    int op=1,cur_pos=-1;

    for(auto c : t)
    {
        int ind=c-'a';
        auto it=upper_bound(all(v[ind]),cur_pos);
        if(it==v[ind].end())
        {
            cur_pos=v[ind][0];
            op++;
        }
        else cur_pos=*it;
    }

    cout<<op<<'\n';
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