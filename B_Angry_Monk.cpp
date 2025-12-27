#include<bits/stdc++.h>
#include "D:/debug.h"
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
        ll n,k,sum=0;
        cin>>n>>k;
        ll arr[k];

        for(int i=0;i<k;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+k);

        k--;
        for(int i=0;i<k;i++)
        {
            if(arr[i]==1)sum++;
            else sum+=arr[i]+arr[i]-1;
        }
        cout<<sum<<endl;
    }
}