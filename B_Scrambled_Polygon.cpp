#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<vector>
#ifndef ONLINE_JUDGE
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M=1e9+7;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

int cross(pair<int,int> a,pair<int,int> b,pair<int,int> c)
{
    return (b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second);
}

void solve()
{
    int n,x,y;
    vector<pair<int,int> > v,lower,upper;

    //for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;

    while(cin>>x>>y)
    {
        v.push_back({x,y});
    }

    n=v.size();

    sort(all(v));

    for(int i=0;i<n;i++)
    {
        while(lower.size()>=2 && cross(lower[lower.size()-2],lower.back(),v[i])<=0) lower.pop_back();
        lower.push_back(v[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        while(upper.size()>=2 && cross(upper[upper.size()-2],upper.back(),v[i])<=0) upper.pop_back();
        upper.push_back(v[i]);
    }

    upper.pop_back();
    lower.pop_back();

    lower.insert(lower.end(),upper.begin(),upper.end());

    int ind=0,k=0;
    pair<int,int> p;
    p.first=0;
    p.second=0;
    while(ind<n && (lower[ind]!=p)) ind++;

    for(int i=ind;k<n;i++,k++) cout<<'('<<lower[i%n].first<<','<<lower[i%n].second<<')'<<'\n';
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