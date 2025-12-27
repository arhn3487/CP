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
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

const int N=1e5+3;

unordered_map<int,int> freq[N];
map<int,int> cnt[N];
int col[N];
vector<int> adj[N];
vector<pair<int,int>> query[N];
multiset<int> ms[N];
int ans[N];

void dfs(int p,int u)
{
    freq[u][col[u]]++;
    cnt[u][1]=1;
    //ms[u].insert(1);
    for(auto x : adj[u])
    {
        if(x==p) continue;
        dfs(u,x);

        if(freq[u].size()<freq[x].size()) 
        {
            swap(freq[u],freq[x]);
            swap(cnt[u],cnt[x]);
            //swap(ms[u],ms[x]);
        }


        for(auto [col,fr] : freq[x]) 
        {
            // int &cur=freq[u][col];
            // if(cur>0) ms[u].erase(ms[u].lower_bound(cur));
            // cur+=fr;
            // ms[u].insert(cur);
            //freq[u][col]+=fr;

            int pre_cnt=freq[u][col];
            if(pre_cnt>0)
            {
                cnt[u][pre_cnt]--;
                if(cnt[u][pre_cnt]==0) cnt[u].erase(pre_cnt);
            }

            freq[u][col]+=fr;
            cnt[u][freq[u][col]]++;
        }
    }

    for(auto [h,ind] : query[u])
    {
        auto it=cnt[u].lower_bound(h);
        int res=0;
        for(auto x=it;x!=cnt[u].end();x++) res+=x->second;
        ans[ind]=res;
    }
    
}

void solve()
{
    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++) cin>>col[i];

    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0;i<q;i++)
    {
        int a,h;
        cin>>a>>h;a--;
        query[a].push_back({h,i});
    }

    dfs(-1,0);

    //for(auto [ind,h] : query) cout<<ans[ind]<<'\n';
    for(int i=0;i<q;i++) cout<<ans[i]<<'\n';
}

int main()
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