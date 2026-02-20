#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

#define ll long long

void solve()
{
    int n,ans=1e18,nibo=0;
    cin>>n;
    vector<int> v(n),l;
    vector<set<int>> adj(50); 
    vector<int> vv={8,15,16,23,42};

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        adj[v[i]].insert(i);
        //last[v[i]]=i;
    }
    if(adj[4].empty())
    {
        cout<<n<<'\n';
        return;
    }

    vector<int> itr;

    for(auto x : adj[4])
    {
        itr.push_back(x);
    }



    for(int i=0;i<adj[4].size();i++)
    {
        int el=i+1,lll=itr[i];
        for(auto x : vv)
        {
            //cerr<<adj[x][i]<<' '<<lll<<"ll"<<'\n';
            auto kk=adj[x].lower_bound(lll);
            if(kk==adj[x].end())
            {
                cout<<n-i*6<<'\n';
                return;
            }
            
            
            lll=*kk;
            adj[x].erase(kk);
            cerr<<lll<<' '<<x<<'\n';
        }
    }
    cout<<n-adj[4].size()*6<<'\n';
}

int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}