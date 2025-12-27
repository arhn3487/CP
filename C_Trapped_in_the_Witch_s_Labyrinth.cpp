#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,m,ans=0;
        cin>>n>>m;

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<string> v(n);
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++) cin>>v[i];

        if(n*m==1)
        {
            cout<<0<<'\n';
            continue;
        }

        for(int i=0,j=0;i<n;i++) if(v[i][j]=='L') vis[i][j]=true,q.push({i,j}),vis[i][j]=true;
        for(int i=0,j=m-1;i<n;i++) if(v[i][j]=='R') vis[i][j]=true,q.push({i,j}),vis[i][j]=true;
        for(int i=0,j=0;i<m;i++) if(v[j][i]=='U') vis[j][i]=true,q.push({j,i}),vis[j][i]=true;
        for(int i=0,j=n-1;i<m;i++) if(v[j][i]=='D') vis[j][i]=true,q.push({j,i}),vis[j][i]=true;

    //     for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if ((i == 0 && v[i][j] == 'U') || (i == n - 1 && v[i][j] == 'D') ||
    //             (j == 0 && v[i][j] == 'L') || (j == m - 1 && v[i][j] == 'R')) {
    //             q.push({i, j});
    //             vis[i][j] = 1;
    //         }
    //     }
    // } // n*m

        
        while(!q.empty())
        {
            auto [i,j] = q.front();
            q.pop();

            if(i-1>=0 && !vis[i-1][j] && v[i-1][j]=='D') vis[i-1][j]=true,q.push({i-1,j});
            if(i+1<n && !vis[i+1][j] && v[i+1][j]=='U') vis[i+1][j]=true,q.push({i+1,j});
            if(j-1>=0 && !vis[i][j-1] && v[i][j-1]=='R') vis[i][j-1]=true,q.push({i,j-1});
            if(j+1<m && !vis[i][j+1] && v[i][j+1]=='L') vis[i][j+1]=true,q.push({i,j+1});

            auto check = [&](int ii,int jj)
            {
                if(ii<0 || jj<0 || ii>=n || jj>=m) return;
                if(vis[ii][jj] || v[ii][jj]!='?') return;
                if(ii-1>=0 && !vis[ii-1][jj]) return;
                if(ii+1<n && !vis[ii+1][jj]) return;
                if(jj-1>=0 && !vis[ii][jj-1]) return;
                if(jj+1<m && !vis[ii][jj+1]) return;
                
                vis[ii][jj]=true;
            };

            check(i+1,j);
            check(i-1,j);
            check(i,j+1);
            check(i,j-1);
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j])
                    ans++;

        cout<<ans<<'\n';

    }
}