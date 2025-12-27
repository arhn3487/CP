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
    int n,a;
    string s;
    cin>>n>>a>>s;
    vector<int> v(n),seen(a,-1),seq;
    seen[a]=0;

    for(auto &x : v) 
    {
        cin>>x;
        x--;
    }

    while(1)
    {
        a=v[a];
        if(seen[a]!=-1)
        {
            int start=seen[a],cycle_len=seq.size()-start,mod=0;
            
            for(auto x : s) mod=(mod*10+(x-'0'))%cycle_len;
            cout<<seq[start+mod]<<'\n';
            return;
        }
        seen[a]=seq.size();
        seq.push_back(a);
    }
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