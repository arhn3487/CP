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

string s1,s2,s3;
int l,n,m;
vector<vector<vector<int>>> dp;

int lcs(int i,int j,int k)
{
    if(i<0 || j<0 || k<0) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(s1[i]==s2[j] && s2[j]==s3[k]) return dp[i][j][k]=1+lcs(i-1,j-1,k-1);
    else if(s1[i]==s2[j]) return dp[i][j][k]=lcs(i-1,j-1,k);
    else if(s2[j]==s3[k]) return dp[i][j][k]=lcs(i,j-1,k-1);
    else if(s1[i]==s3[k]) return dp[i][j][k]=lcs(i-1,j,k-1);
    else return dp[i][j][k]=max({lcs(i-1,j,k),lcs(i,j-1,k),lcs(i,j,k-1)});
}

void solve()
{
    cin>>s1>>s2>>s3;
    l=s1.length(),m=s2.length(),n=s3.length();
    dp.assign(l, vector<vector<int>>(m, vector<int>(n, -1)));
    //int dp[l][m][n];
    //memset(dp,-1,dp.size());
    cout<<lcs(l-1,m-1,n-1)<<'\n';
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