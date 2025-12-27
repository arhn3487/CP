#include<bits/stdc++.h>
//#include "D:/debug.h"
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

int ultimate_parent(int a,vector<int> &parent)
{
    if(parent[a]==a) return a;
    return parent[a]=ultimate_parent(parent[a],parent);
}

void union_(int a,int b,vector<int> &parent,vector<int> &sz)
{
    //cout<<a<<" "<<b<<" union\n";
    a=ultimate_parent(a,parent);
    b=ultimate_parent(b,parent);

    if(a==b) return;

    if(sz[a]>sz[b]) swap(a,b);
    parent[a]=b;
    sz[b]+=sz[a];
}

void solve()
{
    int n,m1,m2,ans=0;
    cin>>n>>m1>>m2;
    vector<int> parent_f(n+1),parent_g(n+1),size_g(n+1,1),size_f(n+1,1);
    vector<pair<int,int>> v;

    for(int i=0;i<=n;i++) parent_f[i]=i,parent_g[i]=i;

    for(int i=0;i<m1;i++)
    {
        int x,y;
        cin>>x>>y;
        // x--;
        // y--;
        v.push_back({x,y});
    }

    for(int i=0;i<m2;i++)
    {
        int x,y;
        cin>>x>>y;
        // x--;
        // y--;
        union_(x,y,parent_g,size_g);
    }

    // for(auto x : parent_g) cout<<x<<' ';
    // cout<<"\n";

    for(auto [x,y] : v)
    {
        if(ultimate_parent(x,parent_g)==ultimate_parent(y,parent_g))
        {
            //cout<<x<<" "<<y<<"bal\n";
            union_(x,y,parent_f,size_f);
        }
        else ans++;
        //cout<<x<<" "<<y<<" "<<ans<<" grp\n";
    }
    

    set<int> l,k;

    for(int i=1;i<=n;i++)
    {
        l.insert(ultimate_parent(i,parent_g));
        k.insert(ultimate_parent(i,parent_f));
        //cout<<i<<"->"<<ultimate_parent(i,parent_f)<<
    }


    cout<<ans+k.size()-l.size()<<'\n';
    //cout << ans + k.size() - l.size() << '\n';

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