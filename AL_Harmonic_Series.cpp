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
    cin>>t;

    while(t--)
    {
        ll n,mx=0;
        cin>>n;
        ll arr[n],cnt[n+1]={},ans[n+1]={};

        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>n) continue;
            cnt[arr[i]]++;
        }

        for(ll i=1;i<=n;i++)
        {
            for(ll j=i;j<=n;j+=i)
            {
                ans[j]+=cnt[i];
            }
        }

        for(ll i=1;i<=n;i++)
        {
            mx=max(mx,ans[i]);
        }

        cout<<mx<<endl;
    }
}