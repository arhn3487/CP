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
//#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<array<int,2>> mv=
{
    {0,1},{0,3},{1,2},{1,4},{2,5},{3,4},{3,6},{4,5},{4,7},{5,8},{6,7},{7,8}
};

int fun(int u,int i,int j)
{
    string s =to_string(u);
    swap(s[i],s[j]);
    return stoi(s);
}

void solve()
{
    int n=0,tgt=123456789,cnt=0;
    unordered_map<int,int> dis;

    for(int i=0;i<9;i++)
    {
        int a;cin>>a;
        n*=10;
        n+=a;
    }

    //debug(n);

    dis[n]=0;

    queue<int> q;
    q.push(n);

    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        

        for(auto [i,j] : mv)
        {
            int v=fun(p,i,j);
            if(!dis.count(v))
            {
                dis[v]=dis[p]+1;
                q.push(v);
            }

            if(v==tgt)
            {
                cout<<dis[v]<<'\n';
                return;
            }
        }

    }

    cout<<-1<<'\n';
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