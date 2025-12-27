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
    int n;cin>>n;
    set<array<int,3>> pq0,pq1;
    set<pair<int,int>> st;
    vector<int> t(n);

    for(auto &x : t) cin>>x;

    auto push =[&](int x,int y)
    {
        if(st.find({x,y})!=st.end()) return;
        st.insert({x,y});

        pq0.insert({3*x+3*y+2,3*x+1,3*y+1});

        pq1.insert({3*x+3*y+2,3*x+1,3*y+1});
        pq1.insert({3*x+3*y+3,3*x+2,3*y+1});
        pq1.insert({3*x+3*y+3,3*x+1,3*y+2});
        pq1.insert({3*x+3*y+6,3*x+2,3*y+2});
    };

    push(0,0);

    for(auto x : t)
    {
        if(x)
        {
            auto it=*pq1.begin();
            cout<<it[1]<<" "<<it[2]<<'\n';
            pq1.erase(it);
            pq0.erase(it);

            push(it[1]/3+1,it[2]/3+1);
            push(it[1]/3,it[2]/3+1);
            push(it[1]/3+1,it[2]/3);
        }
        else
        {
            auto it=*pq0.begin();
            cout<<it[1]<<" "<<it[2]<<'\n';
            pq1.erase(it);
            pq0.erase(it);

            push(it[1]/3+1,it[2]/3+1);
            push(it[1]/3,it[2]/3+1);
            push(it[1]/3+1,it[2]/3);
        }
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
