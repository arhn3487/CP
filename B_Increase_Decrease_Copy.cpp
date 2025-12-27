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
        ll n,op=0,p,mx=0,mn=INT_MAX;
        cin>>n;
        ll a[n],b[n+1];

        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(ll i=0;i<n;i++)
        {
            cin>>b[i];
            op+=abs(b[i]-a[i]);
        }
        cin>>p;
        bool flag=false;
        ll near=LLONG_MAX,dif=LLONG_MAX;

        for(ll i=0;i<n;i++)
        {
            //mx=max(a[i],b[i]);
            //mn=min(a[i],b[i]);
            if(p>=min(a[i],b[i]) && p<=max(a[i],b[i])) 
            {
                flag=true;
                break;
            }
            ll x=abs(a[i]-p);
            ll y=abs(b[i]-p);
            if(dif>x)
            {
                dif=x;
                near=a[i];
            }
            if(dif>y)
            {
                dif=y;
                near=b[i];
            }
        }

        if(flag)
        {
            cout<<op+1<<endl;
            continue;
        }
        else
        {
            cout<<op+1+dif<<endl;
        }
    }
}