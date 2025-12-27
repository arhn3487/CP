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
        int arr[n];

        for(int i=0;i<n;i++) cin>>arr[i];
        bool f=true;

        for(int i=1;i<n;i++)
        {
            //cout<<arr[i]<<" "<<arr[i-1]<<" "<<abs(arr[i]-arr[i-1])<<endl;
            if(abs(arr[i]-arr[i-1])!=5 && abs(arr[i]-arr[i-1])!=7)
            {
                //cout<<"arafaty\n";
                f=false;
            }
        }

        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}