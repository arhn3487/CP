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

class KruskalMST {
public:
    int n; // number of nodes
    vector<int> parent,min_edge;
    vector<tuple<int, int, int>> edges;

    KruskalMST(int nodes) {
        n = nodes;
        parent.resize(n);
        min_edge.assign(n,INT_MAX);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    void add_edge(int u, int v, int w) {
        edges.push_back({w, u, v});
    }

    int find_parent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find_parent(parent[u]);
    }

    bool union_sets(int u, int v,int w) {
        int pu = find_parent(u);
        int pv = find_parent(v);
        if (pu != pv) {
            parent[pu] = pv;
            min_edge[pv]=min({min_edge[pu],min_edge[pv],w});
            return true;
        }
        return false;
    }

    bool connected(int u,int v) {return find_parent(u)==find_parent(v);}

    int get_min(int u) {return min_edge[find_parent(u)];}

    int get_mst_weight() {
        sort(all(edges));
        int total_weight = 0;
        int ans=INT_MAX;
        for (auto [w, u, v] : edges) {
            if (union_sets(u, v,w)) {
                total_weight += w;
                if(connected(0,n-1))
                {
                    ans=min(ans,w+get_min(0));
                }
            }
        }
        return ans;
        return total_weight;
    }
};

void solve()
{
    int n,m;cin>>n>>m;
    auto k=KruskalMST(n);

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        k.add_edge(u,v,w);
    }

    cout<<k.get_mst_weight()<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}