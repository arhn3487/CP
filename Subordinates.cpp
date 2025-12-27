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

int dfs(vector<int> &sub,vector<vector<int>> &v,int ind)
{
    int res=0;
    for(auto x : v[ind])
    {
        res+=dfs(sub,v,x);
    }

    sub[ind]=res;
    return sub[ind]+1;
}

void solve()
{
    int n;
    cin>>n;
    
    vector<vector<int> > v(n+1);
    vector<int> sub(n +1,0);

    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;

        v[a].push_back(i);
    }

    dfs(sub,v,1);

    for(int i=1;i<=n;i++) cout<<sub[i]<<' ';
    cout<<'\n';
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