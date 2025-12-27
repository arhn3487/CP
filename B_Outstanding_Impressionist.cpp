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

void solve()
{
    int n;
    cin>>n;
    vector<int> l(n),r(n),mp(2*n+1,0),v;

    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        if(l[i]==r[i]) mp[l[i]]++;
    }

    for(int i=1;i<=2*n;i++)
        if(mp[i]==0) v.push_back(i);
    
    for(int i=0;i<n;i++)
    {
        int ind1=upper_bound(all(v),r[i])-v.begin();
        int ind2=lower_bound(all(v),l[i])-v.begin();

        if(ind2<ind1 || (l[i]==r[i] && mp[l[i]]==1)) cout<<1;
        else cout<<0;
    }
    cout<<'\n';
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