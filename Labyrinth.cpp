#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
char ch[]={'D','L','U','R'};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
int n,m,f;
vector<vector<char>> v;
vector<vector<bool>> vis;
string s;
int p=INT_MAX;

bool valid(int i,int j)
{
    return i>=0 && j>=0 && i<n && j<m;
}

void dfs(int x,int y,string c)
{
    vis[x][y]=true;

    if(v[x][y]=='B')
    {
        int z=c.length();
        if(p>c.length())
        {
            //cout<<"araft\n";
            s=c;
            p=c.length();
        }
        cout<<c<<endl;
        return ;
    }

    for(int i=0;i<4;i++)
    {
        int a=x+dx[i];
        int b=y+dy[i];

        if(valid(a,b) && !vis[a][b] && (v[a][b]=='.' || v[a][b]=='B')) dfs(a,b,c+ch[i]);
    }
}

void solve()
{
    int p,q;
    cin>>n>>m;
    v.resize(n,vector<char>(m));
    vis.assign(n,vector<bool>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='A')
            {
                p=i,q=j;
            }
        }
    }

    dfs(p,q,"");
    if(s.length())
    {
        YES
        cout<<s.length()<<'\n'<<s<<endl;
    }
    else NO
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