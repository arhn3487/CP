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

    int m,n,r;
    cin>>m>>n>>r;

    vector<vector<int>> v(m,vector<int>(n)),mat;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>v[i][j];

    int k=min(n,m)/2;
    
    for(int i=0;i<k;i++)
    {
        vector<int> tmp;
        for(int j=i;j<n-i-1;j++)
            tmp.push_back(v[i][j]);
        for(int j=i;j<m-1-i;j++)
            tmp.push_back(v[j][n-i-1]);
        for(int j=n-i-1;j>i;j--)
            tmp.push_back(v[m-1-i][j]);
        for(int j=m-i-1;j>i;j--)
            tmp.push_back(v[j][i]);
        
        mat.push_back(tmp);
    }

    // for(auto p : mat)
    // {
    //     for(auto x : p) cout<<x<<" ";
    //     cout<<endl;
    // }

    //r%=(min(n,m));

    for(int i=0;i<k;i++)
    {
        vector<int> tmp=mat[i];
        int sz=tmp.size();
        int ind=r%sz;

        for(int j=i;j<n-i-1;j++)
            v[i][j]=tmp[ind],ind=(ind+1)%sz;
        for(int j=i;j<m-1-i;j++)
            v[j][n-i-1]=tmp[ind],ind=(ind+1)%sz;
        for(int j=n-i-1;j>i;j--)
            v[m-1-i][j]=tmp[ind],ind=(ind+1)%sz;
        for(int j=m-i-1;j>i;j--)
            v[j][i]=tmp[ind],ind=(ind+1)%sz;
    }

    for(int i=0;i<m;i++)
        {for(int j=0;j<n;j++)
            {cout<<v[i][j]<<" ";}
    cout<<endl;}
}