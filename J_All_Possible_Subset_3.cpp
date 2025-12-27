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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

vector<ll> v;

void gen(int four,int seven)
{
    string str="";
    while(four--)
    {
        str+='4';
    }
    while ((seven--))
    {
        str+='7';
    }

    v.push_back(stoll(str));

    while(next_permutation(all(str)))
    {
        ll p=stoll(str);
        v.push_back(p);
    }
    
}

void solve()
{
    int n;
    cin>>n;
    cout<<*lower_bound(all(v),n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;
    for(int i=2;i<=12;i++)
    {
        gen(i/2,i/2);
    }

    sort(v.begin(),v.end());

    // for(auto x : v) cout<<x<<' ';
    // cout<<'\n';

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}