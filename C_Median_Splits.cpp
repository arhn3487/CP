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

bool find(vector<int> &v,int n,int k)
{
    int k_theke_boro=0,k_theke_choto=0,k_theke_boro_1=0,k_theke_choto_1=0,ind1=INT_MAX,ind2=INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(v[i]>=k) k_theke_boro++;
        else k_theke_choto++;
        if(k_theke_boro<=k_theke_choto)
        {
            ind1=i;
            break;
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        if(v[i]>=k) k_theke_boro_1++;
        else k_theke_choto_1++;
        if(k_theke_boro_1<=k_theke_choto_1)
        {
            ind2=i;
            break;
        }
    }

    cout<<ind1<<" "<<ind2<<endl;
    return ind2-ind2>1;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);

    for(int &x : v) cin>>x;

    int res1=find(v,n,k);
    reverse(all(v));
    for(auto x : v) cout<<x<<" ";
    cout<<endl;
    int res2=find(v,n,k);

    if(res1 || res2) YES
    else NO
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