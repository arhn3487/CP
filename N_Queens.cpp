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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

int n;

void print_(vector<string> &p)
{
    for(auto x : p) cout<<x<<'\n';
    print("");
}

void find(vector<int> &left,vector<int> &up,vector<int> &down,vector<string> &v,int col)
{
    if(col==n)
    {
        print_(v);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(left[row]==0 && up[row+col]==0 && down[n-1+col-row]==0)
        {
            v[row][col]='Q';
            left[row]=up[row+col]=down[n-1+col-row]=1;
            find(left,up,down,v,col+1);
            v[row][col]='.';
            left[row]=up[row+col]=down[n-1+col-row]=0;
        }
    }
}

void solve()
{
    cin>>n;
    string s(n,'.');
    vector<string> v(n,s);
    vector<int> left(n,0),up(2*n-1,0),down(2*n-1,0);


    find(left,up,down,v,0);
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