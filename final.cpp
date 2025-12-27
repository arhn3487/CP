#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX

map<string, string> direction;
map<string, vector<pair<string, int>>> graph;
set<string> all_citys;

int disconnected_cites(map<string,bool> visited);

//1->Shortest path: Find the shortest path from the starting city to the destination city.
void shortest_path_bfs(string start, string destination,map<string,bool> visited,map<string, int> dist)
{
    vector<string> path;
    map<string ,string> par;
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    visited[start]=true;

    while (!q.empty())
    {
        string node = q.front();
        q.pop();
        //path.push_back(node);

        for (auto neighbour : graph[node])
        {
            string neighbour_node = neighbour.first;
            if (dist[neighbour_node] == inf)
            {
                dist[neighbour_node] = dist[node] + 1;
                q.push(neighbour_node);
                visited[neighbour_node]=true;
                par[neighbour_node]=node;
            }
        }
    }
    for(auto str=destination ;str!="";str=par[str])
    {
        path.push_back(str);
    }
    reverse(path.begin(),path.end());
    cout<<"The distance from city "<<start<<" to "<<destination<<" is : "<<dist[destination]<<endl;
    cout<<"The path is :\n";
    for(auto x : path) cout<<x<<" ";
    cout<<endl;
}

//5->Longest Simple Path: Find the longest simple path (path without repeating vertices)///vool ase ai ta te
void longest_path_bfs(string start, string destination,map<string,bool> visited,map<string, int> dist)
{
    vector<string> path;
    map<string ,string> par;
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    visited[start]=true;
    for(auto &x : dist) x.second=0;

    while (!q.empty())
    {
        string node = q.front();
        q.pop();

        for (auto neighbour : graph[node])
        {
            string neighbour_node = neighbour.first;
            if (dist[neighbour_node] <dist[node]+1 && !visited[neighbour_node])
            {
                dist[neighbour_node] = dist[node] + 1;
                q.push(neighbour_node);
                visited[neighbour_node]=true;
                par[neighbour_node]=node;
            }
        }
    }
    for(auto str=destination ;str!="";str=par[str])
    {
        path.push_back(str);
    }
    reverse(path.begin(),path.end());
    cout<<"The distance from city "<<start<<" to "<<destination<<" is : "<<dist[destination]<<endl;
    cout<<"The path is :\n";
    for(auto x : path) cout<<x<<" ";
    cout<<endl;
}

//10->Flight Costs with BFS: Each flight has a cost, find the minimum cost path between two cities.

void minimum_cost_bfs(string start, string destination,map<string,bool> visited,map<string, int> dist)
{
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
    q.push({0, start});
    dist[start] = 0;
    visited[start]=true;

    while (!q.empty())
    {
        auto [c, node] = q.top();
        q.pop();

        for (auto neighbour : graph[node])
        {
            string neighbour_node = neighbour.first;
            int weight = neighbour.second;
            if (dist[neighbour_node] == inf)
            {
                dist[neighbour_node] = dist[node] + weight;
                q.push({dist[neighbour_node], neighbour_node});
                visited[neighbour_node]=true;
            }
        }
    }
    cout<<dist[destination]<<endl;
    //disconnected_cites(visited);
}

int disconnected_cites(map<string, bool> visited)
{
    vector<string> v;
    bool flag=false;
    for(auto city : all_citys)
    {
        if(visited[city]==false)
        {
            flag=true;
            v.push_back(city);
        }
    }

    if(flag)
    {
        cout<<"The list of disconnected city that cannot be reached from the starting city\n";
        for(int i=0;i<v.size();i++)
        {
            cout<<i+1<<" : "<<v[i]<<endl;
        }
        cout<<endl;
        //return;
    }
    else
    {
        cout<<"There are not disconnected city that cannot be reached from the starting city\n";
        //return;
    }
    return 0;
}

int main()
{
    map<string, int> dist;
    map<string,bool> visited;
    int n;
    cout << "Enter the number of input\n";
    cin >> n;
    string u, v;
    int cost;

    for (int i = 0; i < n; i++)
    {
        cin >> u >> v >> cost;
        direction[u] = v;
        direction[v] = u;
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
        dist[u] = inf;
        dist[v] = inf;
        all_citys.insert(u);
        all_citys.insert(v);
    }

    string start, destination;
    cout << "Enter the start and destination \n";
    cin>>start>>destination;
    minimum_cost_bfs(start,destination,visited,dist);
    cout<<endl;
    shortest_path_bfs(start,destination,visited,dist);
    cout<<endl;
    //6->Longest Simple Path: Find the longest simple path (path without repeating vertices)
    longest_path_bfs(start,destination,visited,dist);
    //5-> Multi-Source Shortest Path: Find the shortest path from any of a set of starting cities to a destination city.
    cout<<"\n\nMulti-Source Shortest Path\n\n";
    for(auto str : all_citys)
    {
        shortest_path_bfs(str,destination,visited,dist);
        //cout<<endl;
    }
}
