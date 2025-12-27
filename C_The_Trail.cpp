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
    ll n,m,cnt=0,x=0,y=0;
    string str;
    cin>>n>>m>>str;
    ll arr[n][m];
    vector<ll> r(n,0),c(m,0);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            r[i]+=arr[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i]+=arr[j][i];
        }
    }

    while(cnt<n+m-1)
    {
        if(str[cnt]=='D')
        {
            arr[x][y]=-r[x];
            r[x]+=arr[x][y];
            c[y]+=arr[x][y];
            x++;
        }
        else
        {
            arr[x][y]=-c[y];
            r[x]+=arr[x][y];
            c[y]+=arr[x][y];
            y++;
        }
        cnt++;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
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