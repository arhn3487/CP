#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const int infinity = 1000000;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        int n,m,q;
        cin>>n>>m>>q;

        if(n==0 && m==0 && q==0) return 0;

        int g[n][n];

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                g[i][j]=(i==j ? 0 : infinity);

        
            

        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            //edges.push_back({u,v,w});

            g[u][v]=min(g[u][v],w);
        }
        //cout<<g[3][3]<<"ghjkl\n";

        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(g[i][k]!=infinity && g[k][j]!=infinity && g[i][j]>g[i][k]+g[k][j])
                        g[i][j]=g[i][k]+g[k][j];
        
        for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				for (int k=0;g[i][j]!=-infinity && k<n;k++)
					if (g[k][k]<0 && g[i][k]!=infinity && g[k][j]!=infinity)
						g[i][j] = -infinity;
                

        while(q--)
        {
            int u,v;
            cin>>u>>v;
            if(g[u][v]==infinity) print("Impossible")
            else if(g[u][v]==-infinity) print("-Infinity")
            else print(g[u][v]);
        }

        cout<<'\n';
    }
}