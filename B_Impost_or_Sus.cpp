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
#define int long long
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

int fun(string s)
{
    stack<char> st;
    int cnt=0;
    if(s.back()=='u') 
    {
        cnt++;
        s.back()='s';
    }
    if(s[0]=='u')
    {
        cnt++;
        s[0]='s';
    }

    debug(cnt);

    st.push('s');
    int i=1;
    vector<char> v;
    s.push_back('s');

    for(auto x : s)
    {
        if(x=='u' && st.top()=='s') st.push(x);
        else if(x=='u' && st.top()=='u')
        {
            st.pop();
            cnt++;
        }
        if(x=='s' && st.top()=='u') st.pop();
        //debug(st,i);
        debug(x,cnt,i);
        i++;
    }
    return cnt;
}

void solve()
{
    string s;cin>>s;
    int a=fun(s);
    reverse(all(s));
    int b=fun(s);
    cout<<min(a,b)<<'\n';
    //cout<<b<<'\n';
}

int32_t main()
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