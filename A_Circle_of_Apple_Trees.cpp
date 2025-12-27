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
    int n,cnt=1,mn=INT_MAX,ind=-1;
    cin>>n;
    vector<int> v(n);
    set<int> st;

    //for(auto &x : v) cin>>x;

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        st.insert(v[i]);
    }

    // debug(ind);

    // int pre=v[ind];

    // for(int i=ind;i<n;i++)
    // {
    //     if(pre<v[i%n])
    //     {
    //         pre=v[i%n];
    //         cnt++;
    //     }
    // }

    print(st.size())
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