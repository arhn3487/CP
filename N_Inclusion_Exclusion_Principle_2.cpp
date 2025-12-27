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

int n,m;

void solve()
{
    vector<int> jor,bijor,v(m);

    for(int i=0;i<m;i++) cin>>v[i];

    for(int i=0;i<(1<<m);i++)
    {
        int num=1,cnt=0;
        for(int j=0;j<m;j++)
        {
            if(i&(1<<j))
            {
                cnt++;
                num=lcm(num,v[j]);
            }
        }

       // cout<<cnt<<"     "<<num<<endl;
        if(cnt && cnt%2==1) bijor.push_back(num);
        else if(cnt) jor.push_back(num); 
    }

    // for(auto x : jor) cout<<x<<' ';
    // cout<<'\n';
    // for(auto x : bijor) cout<<x<<' ';
    // cout<<'\n';

    ll ans=0;

    for(auto x : bijor)
    {
        ans+=n/x;
    }
    for(auto x : jor)
    {
        ans-=n/x;
    }

    cout<<n-ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin>>n>>m)
    {
        solve();
    }
}