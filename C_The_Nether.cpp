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

int ask(int node,const vector<int> v)
{
    cout<<"? "<<node<<' '<<v.size()<<' ';
    for(auto x : v) cout<<x<<' ';
    cout<<endl;
    int res;cin>>res;
    return res;
}

void solve()
{
    int n,last=-1;
    cin>>n;
    vector<vector<int>> v(n+1);
    vector<int> vec(n),ans;
    for(int i=0;i<n;i++) vec[i]=i+1;

    for(int i=1;i<=n;i++)
    {
        int res=ask(i,vec);
        v[res].push_back(i);
    }

    /*for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> ";
        for(auto x : v[i]) cout<<x<<' ';
        cout<<endl;
    }*/

    for(int i=n;i>=1;i--)
    {
        if(v[i].empty()) continue;
        if(last==-1)
        {
            last=v[i][0];
            ans.push_back(last);
            //debug(ans);
            continue;
        }

        for(int j : v[i])
        {
            if(ask(last,{j,last})==2)
            {   
                ans.push_back(j);
                last=j;
                break;
            }
        }
        //debug(ans);
    }

    cout<<"! "<<ans.size()<<' ';
    for(auto x : ans) cout<<x<<' ';
    cout<<endl;
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
