#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<char> ans;
vector<int> g[26];

void dfs(int start,vector<int> &vis)
{
    vis[start]=1;
    ans.push_back(start+'a');

    for(auto child : g[start])
    {
        if(!vis[child]) dfs(child,vis);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        vector<int> vis(26,0);
        ans.clear();
        for(int i=0;i<26;i++) g[i].clear();
        int start=-1,flag=0;
        string str;
        cin>>str;
        int l=str.length();

        for(int i=0;i<l-1;i++)
        {
            int c = str[i]-'a';
            int d = str[i+1]-'a';
            if(find(g[c].begin(),g[c].end(),d)!=g[c].end())g[c].push_back(d);
            if(find(g[d].begin(),g[d].end(),c)!=g[d].end())g[d].push_back(c);
        }

        for(int i=0;i<26;i++)
        {
            if(g[i].size()>2) flag=1;
            else if(g[i].size()==1) start=i;
        }

        if(flag)
        {
            cout<<"NO"<<endl;
            continue;
        }

        dfs(start,vis);
        
        cout<<"YES"<<endl;
        for(auto ch : ans)
        {
            cout<<ch;
        }
        cout<<endl;
    }
}