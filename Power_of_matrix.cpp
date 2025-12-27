#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

void multiplication(vector<vector<int>> &mat,vector<vector<int>> &mat2,int m_size)
{
    vector<vector<int>> tmp(m_size, vector<int>(m_size, 0));
    for(int i=0;i<m_size;i++)
        for(int j=0;j<m_size;j++)
            for(int k=0;k<m_size;k++)
                tmp[i][j] = (tmp[i][j] + 1LL * mat[i][k] * mat2[k][j] % M) % M;
    
    mat=tmp;
}

void exp(vector<vector<int>> &mat,int p,int m_size)
{
    vector<vector<int>> result(m_size,vector<int>(m_size,0));
    for(int i=0;i<m_size;i++) result[i][i]=1;

    while(p>0){
        if(p%2) multiplication(result,mat,m_size);
        multiplication(mat,mat,m_size);
        p/=2;
    }
    mat=result; 
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
        int n,m_size;
        cin>>m_size>>n;
        vector<vector<int>> mat(m_size,vector<int>(m_size,0));

        for(int i=0;i<m_size;i++)
            for(int j=0;j<m_size;j++)
                cin>>mat[i][j];

        exp(mat,n,m_size);

        for(int i=0;i<m_size;i++)
        {
            for(int j=0;j<m_size;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }        
    }
}