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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve()
{
    int a,b,q;cin>>a>>b>>q;
    vector<int> s(a),t(b);

    for(int i=0;i<a;i++) cin>>s[i]; 
    for(int i=0;i<b;i++) cin>>t[i]; 

    for(int i=0;i<q;i++)
    {
        int x,ans1=infinity;cin>>x;
        auto ss=lower_bound(s.begin(),s.end(),x)-s.begin();
        auto tt=lower_bound(t.begin(),t.end(),x)-t.begin();
        debug(ss,tt);

        for(int j=-1;j<1;j++)
        {
            for(int k=-1;k<1;k++)
            {
                int ii=ss+j,jj=tt+k;
                if(ii<0 or ii>=a or jj<0 or j>=b) continue;
                debug(ii,jj);
                int p1=s[ii],p2=t[jj];
                debug(p1,p2);
                if(p1<=x && p2<=x) ans1=min(ans1,abs(x-min(p1,p2)));
                else if(p1>=x && p2>=x) ans1=min(ans1,abs(max(p1,p2)-x));
                else ans1=min(ans1,2*abs(p2-p1)-max(abs(x-p1),abs(x-p2)));

            }
        }

        cout<<ans1<<'\n';
    }
}
//100 600
//400 900 1000

int32_t main()
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