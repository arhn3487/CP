#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
const int M=1e9+7;
//const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
//inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    int n,m,ans=0;cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    //int row[n],col[m];
    vector<pair<int,int>> row(n,{0,0}),col(m,{0,0});
    vector<int> brr;
    int arr[101]={};
    for(int i=0;i<n;i++) 
    {
        int mx=0,cnt=0;
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            mx=max(mx,grid[i][j]);
            arr[grid[i][j]]++;
        }
        cnt=count(all(grid[i]),mx);
        row[i]={mx,cnt};
    }

    for(int i=1;i<=100;i++) if(arr[i]) {ans=i;brr.push_back(i);}
    sort(all(brr));
    for(int i=0;i<m;i++) 
    {
        int mx=0,cnt=0;
        for(int j=0;j<n;j++)
        {
            mx=max(mx,grid[j][i]);
        }
        for(int j=0;j<n;j++)
        {
            if(grid[j][i]==mx) cnt++;
        }
        col[i]={mx,cnt};
    }

    int hg=ans;
    
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<m;c++)
        {
            //if(grid[r][c]!=hg) continue;
            int mx=max(row[r].first,col[c].first);
            if(mx!=brr.back()) continue;
            int mx_cnt=arr[mx];
            int cc=0;
            if(row[r].first==mx) cc=row[r].second;
            if(col[c].first==mx) cc+=col[c].second;
            if(grid[r][c]==mx) cc--;
            if(cc<mx_cnt) continue;
            //auto sobcheye_boro=upper_bound(all(brr),mx);
            //debug(r,c,cc);
            ans=min(ans,mx-1);
        }
    }

    cout<<ans<<'\n';
}

int32_t main()
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