#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        ll n,m,ans=0;
        cin>>n>>m;
        vector<pair<ll,ll>> flower(n);

        for(int i=0;i<n;i++) cin>>flower[i].first;

        for(int i=0;i<n;i++)
        {
            cin>>flower[i].second;
            ll take=min(m/flower[i].first,flower[i].second);
            ans=max(take*flower[i].first,ans);
        }

        sort(flower.begin(),flower.end());

        //cout<<ans<<endl;

        for(int i=1;i<n;i++)
        {
            if(flower[i].first-flower[i-1].first==1)
            {
                
                ll take=min(m/flower[i-1].first,flower[i-1].second);
                ll extra=m-take*flower[i-1].first;
                ll addable=min(extra/flower[i].first,flower[i].second);
                ll extra2=extra-addable*flower[i].first;
                ans=max(ans,take*flower[i-1].first+addable*flower[i].first+min({extra2,flower[i].second-addable,take}));
                //debug(i,take,extra,addable,ans);
            }
        }

        cout<<ans<<endl;
    }
}
