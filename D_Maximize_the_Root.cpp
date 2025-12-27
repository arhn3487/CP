#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<int> a,d;
vector<vector<ll>> graph;
vector<bool> vis;

ll dfs(ll node)
{
    
    ///else return a[node];
    if(graph[node].size()==0) return a[node];
    vis[node]=true;
    ll mn=LLONG_MAX;
    for(auto neighbour : graph[node])
    {
        if(!vis[neighbour])
        {
            mn=min(mn,dfs(neighbour));
        }
    }

    //cout<<node<<" "<<mn<<endl;

    if(node==1) return a[node]+mn;
    if(mn<a[node]) return mn;
    else return (a[node]+mn)/2;
}

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
        ll n,x;
        cin>>n;

        a.assign(n+1,0);
        d.assign(n+1,0);
        graph.assign(n+1,vector<ll>());
        vis.assign(n+1,false);

        for(ll i=1;i<=n;i++) cin>>a[i];
        for(ll j=2;j<=n;j++) 
        {
            cin>>x;
            graph[x].push_back(j);
            //graph[x].push_back(j);
        }
        vis[0]=true;
        ll result=dfs(1);
        cout<<result<<endl;
    }
}