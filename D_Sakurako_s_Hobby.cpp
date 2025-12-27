#include<bits/stdc++.h>
#include "D:/debug.h"
using namespace std;

vector<int> v;
vector<bool> vis;
vector<int> res;
string s;
int n,cnt;

void dfs(int start)
{
    //cout<<sta
    if(vis[start]) return;
    vis[start]=true;

    //cout<<start<<" "<<s[start]<<" "<<cnt<<endl;

    if(s[start]=='0')
    {
        cnt++;
        dfs(v[start]-1);
    }
    else dfs(v[start]-1);

    res[start]=cnt;
}

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

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
        cin>>n;
        v.resize(n);
        res.clear();
        res.assign(n,0);
        vis.assign(n,false);
        for(int i=0;i<n;i++) cin>>v[i];
        cin>>s;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                //cout<<i<<" ";
                cnt=0;
                dfs(i);
                //cout<<res[i]<<endl;
            }
        }

        for(int i=0;i<n;i++) cout<<res[i]<<" ";
        cout<<endl;
    }
}