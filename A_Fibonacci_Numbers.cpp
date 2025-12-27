#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void multiplication(vector<vector<int>> &mat,vector<vector<int>> &mat2,int m_size) 
{ 
    vector<vector<int>> tmp(m_size, vector<int>(m_size, 0)); 
    for(int i=0;i<m_size;i++) 
        for(int j=0;j<m_size;j++) 
            for(int k=0;k<m_size;k++) 
                tmp[i][j] = (tmp[i][j] + 1LL * mat[i][k] * mat2[k][j] % M) % M; 
     
    mat=tmp; 
} 
 
void expp(vector<vector<int>> &mat,int p,int m_size) 
{ 
    vector<vector<int>> result(m_size,vector<int>(m_size,0)); 
    for(int i=0;i<m_size;i++) result[i][i]=1; 
 
    while(p>0){ 
        if(p%2) multiplication(result,mat,m_size); 
        multiplication(mat,mat,m_size); 
        p/=2; 
    } 

    cout<<result[0][0];
    mat=result;  
} 

void solve()
{
    int n;
    cin>>n;

    if(!n)
    {
        cout<<0;
        return;
    }

    vector<vector<int>>p={{1,1},{1,0}};
    expp(p,n-1,2);

}

int32_t main()
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