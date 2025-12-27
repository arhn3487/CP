#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");
int ax,ay,bx,by,n,m,k,total=0;
vector<string> grid;

int check(string s)
{
    int i=ax,j=ay,ind=0;

    //debug("arafat\n");
    while(ind<s.length())
    {
        
        
        if(s[ind]=='R') 
        {
            if(j+1<m && grid[i][j+1]!='1')
            {
                j++;
                total++;
            }
        }
        else if(s[ind]=='L')
        {
            if(j-1>=0 && grid[i][j-1]!='1')
            {
                j--;
                total++;
            }
        }
        else if(s[ind]=='U')
        {
           if(i-1>=0 && grid[i-1][j]!='1')
            {
                i--;
                total++;
            } 
        }
        else 
        {
           if(i+1<n && grid[i+1][j]!='1')
            {
                i++;
                total++;
            } 
        }

        

        ind++;
    }
    ax=i,ay=j;
    //debug(ax,ay);
    if(i<n && j<m && i>=0 && j>=0 && i==bx && j==by) return total;
    else return INT_MAX;
}

void solve()
{
    int ans=INT_MAX;
    cin>>n>>m;
    grid.resize(n);

    for(auto &x : grid) cin>>x;

    cin>>ax>>ay>>bx>>by>>k;

    //debug(k);

    while(k--)
    {
        string s;cin>>s;
        int tmp=check(s);
        //cout<<"BAL\n";
        if(tmp!=INT_MAX && ans==INT_MAX) ans=tmp;
    }

    cout<<ans<<'\n';
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