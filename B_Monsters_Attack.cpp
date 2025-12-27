#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define int long long
const int M=1e9+7;
//const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
//inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k,a,used=0,rem=0,flag=0;
        cin>>n>>k;

        int arr[n+1],b[n+1]={0};

        for(int i=1;i<=n;i++) cin>>arr[i];

        for(int i=1;i<=n;i++)
        {
            cin>>a;
            b[abs(a)]+=arr[i];
        }

        for(int i=1;i<=n;i++)
        {
            rem+=k;

            if(b[i]>rem)
            {
                flag=1;
                break;
            }

            rem-=b[i];
        }

        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
}