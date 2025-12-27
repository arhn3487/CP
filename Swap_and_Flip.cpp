#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int one=0,zero=0;

    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            if(s[i]=='0') zero++;
            else one++;
        }
    }

    int need=one%2+zero%2;

    if(need%2==0) YES
    else NO
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