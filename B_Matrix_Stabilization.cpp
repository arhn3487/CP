#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n,vector<int>(m));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cin>>mat[i][j];
        }

        int left,right,up,down;
        bool f=true;

       
            //f=false;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++) 
                {
                    if(i>0)  up=mat[i-1][j];
                    else up=0;

                    if(i<n-1) down=mat[i+1][j];
                    else down=0;

                    if(j>0) left=mat[i][j-1];
                    else left=0;

                    if(j<m-1) right=mat[i][j+1];
                    else right=0;

                    int mx=max(max(left,right),max(up,down));
                    
                    if(mx<mat[i][j])
                    {
                        mat[i][j]=mx;
                        //f=false;
                    }
                }
            }
        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        //cout<<endl;
    }
}