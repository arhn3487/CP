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
    int n;
    string s;
    cin>>n>>s;

    for(auto a0 : {'S','W'})
    {
        for(auto a1: {'S','W'})
        {
            string a(n,'?');
            a[0]=a0,a[1]=a1;

            for(int i=1;i<=n;i++)
            {
                if((s[i%n]=='o' && a[i%n]=='S') || (s[i%n]=='x' && a[i%n]=='W'))
                    a[(i+1)%n]=a[(n+i-1)%n];
                else
                    a[(i+1)%n]=a[(n+i-1)%n]=='S' ? 'W' :'S';
            }
            if(a0==a[0] && a[1]==a1)
            {
                cout<<a<<'\n';
                return;
            }
            //cout<<a<<'\n';
        }
    }

    cout<<-1<<'\n';
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