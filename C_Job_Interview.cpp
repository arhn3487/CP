#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve()
{
    int n,m;cin>>n>>m;
    int tot=n+m;
    vector<ll> p(tot+1),t(tot+1),ans(tot+1),mx(tot+1),pro(tot+1,0),tst(tot+1,0),tst_sum(tot+1),pro_sum(tot+1);

    for(int i=0;i<=tot;i++) cin>>p[i];
    for(int i=0;i<=tot;i++) cin>>t[i];

    for(int i=0;i<n+m+1;i++)
    {
        mx[i]=max(p[i],t[i]);
        if(mx[i]==p[i]) pro[i]++;
        else tst[i]++;
    }

    pro[0]=(p[0]>t[0]);
    tst[0]=1-pro[0];

    for(int i=1;i<=tot;i++)
    {
        pro[i]+=pro[i-1];
        tst[i]+=tst[i-1];
    }
    tst_sum[tot]=t[tot];
    pro_sum[tot]=p[tot];
    for(int i=tot-1;i>=0;i--) 
    {
        tst_sum[i]=t[i]+tst_sum[i+1];
        pro_sum[i]=p[i]+pro_sum[i+1];
    }

    for(int i=1;i<=tot;i++) mx[i]+=mx[i-1];

    // debug(p,t);
    // debug(pro);
    // debug(tst);
     debug(mx);
    debug(pro_sum,tst_sum);


    for(int i=0;i<=tot;i++)
    {
        int pk=(p[i]>t[i]) ? n+1 : n;
        int tk=(pk==n) ? m+1: m;
        if(!n)  pk=0;
        if(!m) tk=0;
        auto it=lower_bound(all(pro),pk)-pro.begin()+1,it2=lower_bound(all(tst),tk)-tst.begin()+1;
        debug(pk,tk,it,it2);
        if(it<it2)
        {
            debug(mx[it-1],tst_sum[it]);
            ans[i]=mx[it-1]+tst_sum[it]-t[i];
        }
        else 
        {
            debug(mx[it2-1],pro_sum[it2]);
            ans[i]=mx[it2-1]+pro_sum[it2]-max(p[i],t[i]);
            
        }
    }

    for(auto x : ans) cout<<x<<' ';
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