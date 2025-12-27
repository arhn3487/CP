#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

void solve()
{
    int n;cin>>n;
    vector<int> v(n),t;
    vector<vector<int>> vv;

    for(auto &x : v) 
    {
        cin>>x;
    }

    for(int i=0;i<n;i++)
    {
        if(t.empty())
        {
            t.push_back(v[i]);
            //continue;
        }
        int j=i+1;
        while(j<n && v[i]<v[j])
        {
            //j++;
            //debug(v[i],v[j]);
            t.push_back(v[j]);
            j++;
        }
        i=j-1;
        vv.push_back(t);
        t.clear();
    }

    vector<int> boro(vv.size()),soto(vv.size());
    int k=0;

    for(auto x : vv)
    {
        int mx=0,mn=n+1;

        for(auto xx : x)
        {
            mx=max(mx,xx);
            mn=min(mn,xx);
        }
        boro[k]=mx;
        soto[k]=mn;
        k++;
    }

    int ss=soto[0];
    vector<bool> connected(n,false);

    for(int i=1;i<boro.size();i++)
    {
        debug(boro[i],ss);
        if(boro[i]>ss) 
        {
            connected[i]=true;
            ss=min(ss,soto[i]);
            continue;
        }
        // yes(0)
        // return;
    }

    int mx=0;

    debug(connected);

    for(int i=soto.size()-1;i>=0;i--)
    {
        cerr<<i<<' ';
        if(!connected[i])
        {
            if(mx>soto[i])
            {
                connected[i]=true;
            }
            else
            {
                yes(0)
                return;
            }
        }
        mx=max(boro[i],mx);
    }


    yes(1)

    debug(boro,soto);

    //for(int i=)


    debug(vv);
}

int32_t main()
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