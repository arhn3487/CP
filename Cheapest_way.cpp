#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

unordered_map<string,int> mp;
unordered_map<string,vector<pair<string,ll>>> graph;
unordered_map<string,ll> dist;
unordered_map<string,string> path;
ll cst=0;

ll dijkstra(string s,string s1)
{
    priority_queue<pair<ll,string>,vector<pair<ll,string>>,greater<pair<ll,string>>> pq;
    pq.push({0,s});
    dist[s]=0;

    while(!pq.empty())
    {
        string parent = pq.top().second;
        ll parent_weight = pq.top().first;
        pq.pop();

        if(parent_weight>dist[parent]) continue;

        for(auto child : graph[parent])
        {
            string child_node = child.first;
            ll child_weight = child.second;

            if(child_weight+parent_weight<dist[child_node]) 
            {
                dist[child_node]=child_weight+parent_weight;
                pq.push({dist[child_node],child_node});
                path[child_node]=parent;
            }
        }
    }
    return dist[s1];
}

inline void print_path(string &s,string &s1)
{
    cst+=mp[s1];
    if(path[s1]=="") {cout<<s1<<" ";return;}
    print_path(s,path[s1]);
    cout<<s1<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        ll n,a;
        string str,str1;
        cin>>n;
        cst=0;
        mp.clear();
        dist.clear();
        graph.clear();
        path.clear();

        while(n--)
        {
            cin>>str>>a;
            mp[str]=a;
            dist[str]=infinity;
        }
        
        cin>>n;

        while(n--)
        {
            cin>>str>>str1>>a;
            graph[str].push_back({str1,2*a});
            graph[str1].push_back({str,2*a});
        }

        ll q;
        cin>>q;

        cout<<"Map #"<<i<<endl;
        for(int j=1;j<=q;j++)
        {
            
           cin>>str>>str1>>a;
           ll cost = dijkstra(str,str1);
           cout<<"Query #"<<j<<endl;
            
           print_path(str,str1);
           cout<<endl;
           cost+=cst;
           cout<<"Each passenger has to pay : "<<fixed<<setprecision(2)<<(cost*0.1+cost)/a<<" taka"<<endl;
        }
        cout<<"\n";
    } 
}