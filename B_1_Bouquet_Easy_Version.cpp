#include<bits/stdc++.h>
#include "D:/debug.h"
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
        ll n,m;
        cin>>n>>m;;
        vector<ll> v(n);

        for(int i =0;i<n;i++) cin>>v[i];

        sort(v.begin(),v.end());

        ll start=0,cnt=0,ans=0,sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=v[i];

            while(sum>m || (start<n && v[i]-v[start]>1))
            {
                sum-=v[start];
                start++;
            }
            ans=max(ans,sum);
        }

        cout<<ans<<endl;
    }
}