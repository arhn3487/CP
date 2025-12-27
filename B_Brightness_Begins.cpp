#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
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
    cin>>t;

    while(t--)
    {
        ll n,k=4e18;
        cin>>n;
        ll left=1,right=4e18;

        while(left<=right)
        {
            ll mid=(left+right)/2;
            ll on=mid-(int)sqrtl(mid);
            if(on<n) left=mid+1;
            else
            {
                right=mid-1;
                k=mid;
            }
            
        }

        cout<<k<<endl;
    }
}

1000000000000000000
1000000001000000000