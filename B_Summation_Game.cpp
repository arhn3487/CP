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
    int n,k,x,ans=INT_MIN;
    cin>>n>>k>>x;
    vector<int> v(n),pre(n,0);

    for(int i=0;i<n;i++) cin>>v[i];

    sort(all(v));
    pre[0]=v[0];

    for(int i=1;i<n;i++) pre[i]=v[i]+pre[i-1];

    for(int remove=0;remove<=k;remove++)
    {
        if(remove==n) 
        {
            ans=max(0,ans);
            break;
        }

        int after_remove_sum=pre[n-remove-1];
        int can_negefy=min(x,n-remove);
        int last_rem_ind=n-remove-1;
        int negefy_till=max(0,last_rem_ind-can_negefy+1);

        int gain,negefy_window_sum;

        if(negefy_till==0)
        {
            negefy_window_sum=pre[last_rem_ind];
            gain=-negefy_window_sum;
        }
        else
        {
            negefy_window_sum=pre[last_rem_ind]-pre[negefy_till-1];
            gain=pre[negefy_till-1]-negefy_window_sum;
        }


        ans=max(ans,gain);
        
    }

    print(ans)
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