#include<bits/stdc++.h>
//#include "D:/debug.h"
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
#define YES cout<<"Yes\n";
#define NO cout<<"No\n";

void solve()
{
    int n;
    bool f=true;
    cin>>n;
    //vector<int> v(n+1);

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        int a=__builtin_popcount(i);
        int b=__builtin_popcount(x);
        if(a!=b)
        {
            f=false;
        }
    }
    if(!f)  NO
    else YES
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