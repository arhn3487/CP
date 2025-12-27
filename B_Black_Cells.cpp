#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        ll arr[n+10];
        ll ans=infinity;

        for(int i=1;i<=n;i++) cin>>arr[i];

        if(n==1) ans=1;
        else if(n%2==0)
        {   
            ans=1;
            for(int i=1;i<n;i+=2)
            {
                ans=max(ans,arr[i+1]-arr[i]);
                //cout<<ans<<endl;
            }
        }
        else
        {
            for(int lagbena=1;lagbena<=n;lagbena+=2)
            {
                ll mx=1;
                for(int i=1;i<=n;i+=2)
                {
                    if(i==lagbena) i--;
                    else mx=max(arr[i+1]-arr[i],mx);
                }
                ans=min(mx,ans);
            }
        }

        cout<<ans<<endl;
    }
}