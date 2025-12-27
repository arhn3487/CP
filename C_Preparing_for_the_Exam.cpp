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

void solve()
{
    int n,m,k,a;
    cin>>n>>m>>k;
    map<int,bool> pare;
    map<int,bool> parena;
    vector<int> v(m);

    for(int i=0;i<m;i++)
    {
        cin>>v[i];
    }

    for(int i=0;i<k;i++)
    {
       cin>>a;
       pare[a]=true;
    }

    if(k<=n-2)
    {
        for(int i=0;i<m;i++) cout<<'0';
        cout<<'\n';
        return;
    }
    if(k==n)
    {
        for(int i=0;i<m;i++) cout<<'1';
        cout<<'\n';
        return;
    }

    int l=-1;

    for(int i=1;i<=n;i++)
    {
        if(pare[i]==false) 
        {
            parena[i]=true;
            l=i;
        }
    }

    for(int i=0;i<m;i++)
    {
        if(v[i]==l)cout<<'1';
        else cout<<'0';
    }
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