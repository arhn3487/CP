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

set<ll> st;

ll func(int ind,vector<ll > &v)
{
    if(ind==0)
    {
        st.insert(v[0]);
        return v[0];
    }
    ll take=v[ind]+func(ind-1,v);
    ll not_take=func(ind-1,v);
    st.insert(take);
    st.insert(not_take);
}

void solve()
{
    int n;
    cin>>n;
    vector<ll> vec(n);

    for(int i=0;i<n;i++) cin>>vec[i];

    func(n-1,vec);
    cout<<st.size()<<" ";

    for(auto it=st.begin();it!=st.end();it++) cout<<*it<<' ';
    cout<<'\n';
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