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
        int n,cnt=0,c=0;
        cin>>n;
        int arr[n];
        //int f[n];

        for(int i=0;i<n;i++) cin>>arr[i];
        //f[0]=arr[0],f[n-1]=arr[n-1];

        // for(int i=1;i<n/2;i++)
        // {
        //     if(arr[i]==f[i-1] || arr[n-i-1]==f[n-i])
        //     {
        //         f[i]=arr[n-i-1];
        //         f[n-i-1]=arr[i];
        //     }
        //     else 
        //     {
        //         f[i]=arr[i];
        //         f[n-i-1]=arr[n-i-1];
        //     }
        // }

        //if(n%2) f[n/2]=arr[n/2];

        for(int i=1;i<n/2;i++)
        {
            if(arr[i]==arr[i-1] || arr[n-i-1]==arr[n-i]) swap(arr[i],arr[n-i-1]);
        }


        // for(int i=0;i<n;i++) cout<<f[i]<<" ";
        // cout<<endl;

        for(int i=1;i<n;i++)
        {
            //if(f[i]==f[i-1]) cnt++;
            if(arr[i]==arr[i-1]) c++;
        }

        //cout<<cnt<<endl;
        cout<<c<<endl;
    }
}