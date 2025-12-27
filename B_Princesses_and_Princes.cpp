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

void solve()
{
    int n;
    cin>>n;

    vector<vector<int>> v(n+1);
    vector<bool> abilable_prince(n+1,true),in_list(n+1,false);
    vector<int>a,b;

    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        
        for(int j=0;j<k;j++)
        {
            int a;cin>>a;
            v[i].push_back(a);
            //in_list[a]=true;
        }
    }

    for(int i=1;i<=n;i++)
    {
        bool f=true;
        for(auto prince : v[i])
        {
            if(abilable_prince[prince])
            {
                abilable_prince[prince]=false;
                f=false;
                break;
            }
        }
        if(f) a.push_back(i);
    }

    for(int i=1;i<=n;i++)
        if(abilable_prince[i]) b.push_back(i);
    
    if(!a.size())
    {
        print("OPTIMAL")
        return;
    }
    print("IMPROVE")
    for(int i=0;i<a.size();i++) 
    {
        cout<<a[i]<<" "<<b[i]<<'\n';
        //cout<<'\n';
        return;
    }
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