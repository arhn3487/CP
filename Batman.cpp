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

int dp[51][51][51];
string st1,st2,st3;

int func(int i,int j,int k)
{
    if(i<0 || j<0 || k<0) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(st1[i]==st2[j] && st2[j]==st3[k]) return dp[i][j][k]=1+func(i-1,j-1,k-1);
    return dp[i][j][k]=max({func(i-1,j,k),func(i,j-1,k),func(i,j,k-1)});
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    cin>>st1>>st2>>st3;

    int ans=func(st1.length()-1,st2.length()-1,st3.length()-1);
    print(ans)
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
        cout<<"Case "<<i<<": ";
        solve();
    }
}