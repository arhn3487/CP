#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll M=1e9+7;
const ll infinity = LLONG_MAX;
ll dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
ll dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<vector<ll>> adj;
vector<ll> vis;

void dfs(ll x)
{
    //cout<<"arafat\n"<<x<<endl;
    if(vis[x]) return;
    vis[x]=true;
    for(auto l : adj[x]) dfs(l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,s1,s2,t1,t2,f,s;
    cin>>n>>s1>>s2>>t1>>t2;

    auto dist = [&](ll x1,ll y1,ll x2 ,ll y2)
    {
        ll x=x1-x2;
        ll y=y1-y2;

        ll res=x*x+y*y;

        return res;
    };

    vector<array<ll,3>> v(n);
    adj.resize(n);
    vis.assign(n,false);

    for(ll i=0;i<n;i++) 
    {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
        if ((v[i][0]-s1)*(v[i][0]-s1)+(v[i][1]-s2)*(v[i][1]-s2)==v[i][2]*v[i][2]) f=i;
        if ((v[i][0]-t1)*(v[i][0]-t1)+(v[i][1]-t2)*(v[i][1]-t2)==v[i][2]*v[i][2]) s=i;
    }

    if(f==s) 
    {
        cout<<"Yes\n";
        return 0;
    }

    for(ll i=0;i<n;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            //cout<<dist(v[i][0],v[i][1],vll][0],v[j][1])<<endl;
            ll r_dif= v[i][2]-v[j][2];
            ll r_sum= v[i][2]+v[j][2];
            ll c1c2=dist(v[i][0],v[i][1],v[j][0],v[j][1]);

            if(c1c2<=r_sum*r_sum && c1c2>=r_dif*r_dif)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // for(ll i=0;i<n;i++)
    // {
    //     cout<<i<<"-> ";
    //     for(auto x : adj[i]) cout<<x<<" ";
    //     cout<<endl;
    // }

    dfs(f);

    if(vis[s]) cout<<"Yes\n";
    else cout<<"No\n";
}