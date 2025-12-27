#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
ll dx[]={2,2,-2,-2,1,1,-1,-1};
ll dy[]={1,-1,1,-1,2,-2,2,-2};

void dijestra(ll a,ll b,ll c,ll d)
{
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq;
    pq.push({0,{a,b}});
    vector<vector<ll>> cost(8,vector<ll>(8,infinity));
    cost[a][b]=0;

    while(!pq.empty())
    {
        ll parent_cost=pq.top().first;
        ll parent_x=pq.top().second.first;
        ll parent_y=pq.top().second.second;
        pq.pop();

        if(parent_cost>cost[parent_x][parent_y]) continue;

        for(ll i=0;i<8;i++)
        {
            ll child_x=parent_x+dx[i];
            ll child_y=parent_y+dy[i];

            if(child_x<8 && child_x>=0 && child_y<8 && child_y>=0 && cost[child_x][child_y]>parent_cost+parent_x*child_x+parent_y*child_y)
            {
                cost[child_x][child_y]=parent_cost+parent_x*child_x+parent_y*child_y;
                pq.push({cost[child_x][child_y],{child_x,child_y}});
            }
        }
    }
    if(cost[c][d]==infinity) cout<<-1<<endl;
    else cout<<cost[c][d]<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a,b,c,d;
    
    while(cin>>a>>b>>c>>d)
    {
        dijestra(a,b,c,d);
    }
}
