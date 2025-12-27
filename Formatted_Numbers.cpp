#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
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
    string s;cin>>s;
    vector<string> v;
    reverse(all(s));

    for(int i=0;i<s.size();i++)
    {
        int cnt=0;
        string k="";
        while(cnt<3 && i<s.size())
        {
            k+=s[i];
            i++;
            cnt++;
        }
        i--;
        reverse(all(k));
        v.push_back(k);
        //debug(v);
    }

    reverse(all(v));

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
        if(i!=v.size()-1)  cout<<',';
    }
}

int main()
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