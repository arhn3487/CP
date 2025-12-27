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
        int n,neg1=0;
        cin>>n;
        int a[n+2],b[n+1],c[n+2];

        for(int i=1;i<n;i++) cin>>b[i];
        sort(b+1,b+n);
        a[1]=1;

        for(int i=2;i<=n;i++)
        {
            a[i]=b[i-1]-a[i-1];
        }

        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
}