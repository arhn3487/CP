#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
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
        ll x,y,z,k,c=0;
        cin>>x>>y>>z>>k;

        for(ll i=1;i<=x;i++)
        {
            for(ll j=1;j<=y;j++)
            {
                if(k%(i*j)) continue;
                ll l=k/(i*j);
                if(l>z) continue;
                if(k<(i*j)) continue;
                c=max(c,(x-i+1)*(y-j+1)*(z-l+1));
            }
        }

        cout<<c<<endl;
    }
}