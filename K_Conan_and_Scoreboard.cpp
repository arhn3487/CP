#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M = 1e9 + 7;
const int N = 1e6 + 5;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<vector<int>> solved, attempt, incorrect;

void solve() 
{
    int n,m,k,first=-1,last=-1,solid=1;cin>>n>>m>>k;
    vector<tuple<string,int,int,int>> v(k);
    solved.assign(n+1,vector<int>(m+1,0)),attempt.assign(n+1,vector<int>(m+1,0)),incorrect.assign(n+1,vector<int>(m+1,0));
    //int ans[n+1]={},kk[m+1]={};
    vector<int> ans(n+1, 0);
    vector<int> kk(m+1, 0);
    kk[0]=0;
    map<int,pair<string,int>> mp;

    for(int i=1;i<=n;i++)
    {
        mp[i]={"333:59",0};
    }

    for(int i=0;i<k;i++)
    {
        int a,b,c;
        string s;cin>>a>>b>>c>>s;
        v[i]=make_tuple(s,a,b,c);
        // attempt[a][b]++;
        // if(c==0 && solved[a][b]==0)incorrect[a][b]++;
        // if(c==1 && solved[a][b]!=1)
        // {
        //     solved[a][b]=1;
        //     ans[b]++;
        //     if(attempt[a][b]==1) kk[b]++;
        // }
        // cerr<<i<<" -> ";
        // for(int i=1;i<=m;i++) cerr<<kk[i]<<' ';
        // cerr<<'\n';
    }

    sort(all(v));
    

    for(int i=0;i<k;i++)
    {
        auto [s,a,b,c]=v[i];
        //v[i]=make_tuple(s,a,b,c);
        attempt[a][b]++;
        if(c==0 && solved[a][b]==0)incorrect[a][b]++;
        if(c==1 && solved[a][b]!=1)
        {
            solved[a][b]=1;
            ans[b]++;
            if(attempt[a][b]==1) kk[b]++;
            if(mp[a].first>s) mp[a]={s,b};
            //else mp[a].second++;
        }
        // cerr<<i<<" -> ";
        // for(int i=1;i<=m;i++) cerr<<kk[i]<<' ';
        // cerr<<'\n';
    }

    for(int i=1;i<=n;i++)
    {
        if(mp[i].second==0) mp[i].second=-1;
        cout<<mp[i].second<<' ';
    }

    cout<<'\n';

    pair<int,int> Relentless={-1,1};

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(solved[i][j])
            {
                // Correct logic to avoid invalid states
                if (incorrect[i][j] > Relentless.first) {Relentless = {incorrect[i][j], j};}
                else if (incorrect[i][j] == Relentless.first) 
                {
                    if (j < Relentless.second) Relentless.second = j;
                }
                // if(incorrect[i][j]>Relentless.first && j<=Relentless.second) 
                // {
                //     Relentless={incorrect[i][j],j};
                // }
            }
        }
    }

    


    for(int i=1;i<=m;i++)
    {
        //cerr<<kk[i]<<' ';
        if(kk[i]>kk[solid]) solid=i;
    }

    //solid=kk[solid];
    //debug(v);

    for(auto [a,b,c,d] : v)
    {
        //cerr<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
        if(d==1)
        {
            if(first==-1) first=c;
            last=c;
        } 
    }

    cout<<first<<' '<<last<<' '<<solid<<' '<<Relentless.second<<'\n';

    debug(first,last,solid,Relentless);

    //for(int i)
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}