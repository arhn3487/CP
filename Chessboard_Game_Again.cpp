#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<vector<int>> dp;

int rec(int i,int j)
{
    //cout<<"arafat\n";
    if(i<1 || j<1 || i>15 || j>15) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    int a = rec(i-2,j+1);
    int b = rec(i-2,j-1);
    int c = rec(i+1,j-2);
    int d = rec(i-1,j-2);

    return dp[i][j]=!(a&b&c&d);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        bool res=true;

        while(n--)
        {
            int x,y;
            cin>>x>>y;

            dp.assign(16,vector<int>(16,-1));

            rec(x,y);

            res&=(dp[x][y]==1);
        }

        if(res) cout<<"First\n";
        else cout<<"Second\n";
    }
}