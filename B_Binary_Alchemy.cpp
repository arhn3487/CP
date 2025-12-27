#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,e=1;
    cin>>n;
    vector<vector<int>> v(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++) cin>>v[i][j];
    }

    for(int i=1;i<=n;i++)
    {
        if(e>i) e=v[e][i];
        else e=v[i][e];
    }

    cout<<e<<endl;
}