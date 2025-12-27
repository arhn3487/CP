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

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<vector<int>> a(n,vector<int>(m,0)),b(n,vector<int>(m,0));
        vector<int> v(n*m);
        for(int i =0;i<n*m;i++) v[i]=i+1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }

        if(n*m==1)
        {
            cout<<-1<<endl;
            continue;
        }

        if(m==1)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<m;j++) cout<<a[i%n][j]<<" ";
            }
            continue;;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<a[i][j%m]<<" ";
            }
            cout<<endl;
        }
    }
}