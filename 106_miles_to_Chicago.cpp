#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = DBL_MAX;
ll n;

void dijkstra(vector<vector<pair<ll,double>>> &graph)
{
    vector<double> distance(n+1,0);
    distance[1]=1;
    priority_queue<pair<double,ll>,vector<pair<double,ll>>,greater<pair<double,ll>>> pq;
    pq.push({1,1});

    while(!pq.empty())
    {
        //cout<<"arafat"<<endl;
        auto [parent_weight,parent]=pq.top();
        pq.pop();

        for(auto [child,child_weight] : graph[parent])
        {
            if(child_weight*parent_weight>distance[child])
            {
                distance[child]=child_weight*parent_weight;
                pq.push({distance[child],child});
            }
        }
    }
    cout<<fixed<<setprecision(6)<<distance[n]*100<<" percent"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll u,u2;
    double w;
    while(cin>>n && n)
    {
        ll m;
        cin>>m;
        vector<vector<pair<ll,double>>> v(n+1);
        
        
        for(ll i=0;i<m;i++)
        {
            //cout<<m<<endl;
            cin>>u>>u2>>w;
            w/=100.0;
            v[u2].push_back({u,w}); 
            v[u].push_back({u2,w});
            //cout<<"inp"<<endl;
        }
        //cout<<"ar"<<endl;
        dijkstra(v);
    }
}