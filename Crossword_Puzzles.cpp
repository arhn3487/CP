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
    int n,m;
    string ans="";
    cin>>n>>m;
    vector<string> v(n);

    for(auto &x : v) cin>>x;

    for(int i=0;i<n;i++)
    {
        
        
        int j=0;
        while(j<m)
        {
            string tmp="";
            while(j<m && v[i][j]!='X') 
            {
                tmp.push_back(v[i][j]);
                j++;
            }
            if((ans.length()==0 || ans>tmp) && tmp.length()>1) ans=tmp;
            j++;
        }
        
    }
    for(int i=0;i<m;i++)
    {
        
        
        int j=0;
        while(j<n)
        {
            string tmp="";
            while(j<n && v[j][i]!='X') 
            {
                tmp.push_back(v[j][i]);
                j++;
            }
            if((ans.length()==0 || ans>tmp) && tmp.length()>1) ans=tmp;
            j++;
        }
        
    }

    cout<<ans<<'\n';
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
        cout<<"Case "<<i<<": ";
        solve();
    }
}