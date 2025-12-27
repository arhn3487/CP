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
    int a,b;cin>>a>>b;
    // if(a<b)
    // {
    //     cout<<-1<<'\n';
    //     return;
    // }
    vector<int> v(32,0),k;

    for(int i=0;i<32;i++)
    {
        int flag=(1<<i);
        if((a&flag) == (b& flag)) continue;
        if(((a&flag) != (b&flag)) && (a>=flag)) 
        {
            //debug(i);
            k.push_back(flag);
            a=a^flag;
        }
        else
        {
            //debug(i);
            cout<<-1<<'\n';
            return;
        }
    }

    cout<<k.size()<<'\n';
    for(auto x: k) cout<<x<<' ';

    // //reverse(all(v));
    // int i=31;
    // while(v.back()==0) 
    // {
    //     v.pop_back();
    //     i--;
    // }

    // for(auto x : v) a=a^x;
    // debug(k);

    // cout<<v.size()<<'\n';

    // //for(int i=0;i<5;i++) cout<<v[i]<<' ';
    // for(auto x : v) cout<<x<<' ';
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