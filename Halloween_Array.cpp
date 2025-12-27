#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    int n,l,r,a,d=0;
    cin>>n>>l>>r;
    map<int,int> mp;
    vector<int> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        mp[v[i]]++;
        if(mp[v[i]]==2) d=1;
    }

    if(d==1)
    {
        if(l==0) YES
        else NO
        return;
    }

    ll res=1;

    if(n<=10)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                res=res*(v[i]^v[j]);
                if(res>r)
                {
                    NO
                    return;
                }
            }
        }

        if(l<=res && res<=r)
        {
            YES
            return;
        }
        NO;
        return;
       
    }

    NO
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