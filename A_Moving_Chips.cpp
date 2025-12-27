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
        int n,f=0,l,cnt=0;
        cin>>n;
        l=n-1;
        int arr[n];

        for(int i=0;i<n;i++) cin>>arr[i];

        while(arr[l]==0)l--;
        while(arr[f]==0)f++;

        
        for(f;f<l;f++)
        {
            if(arr[f]==0) cnt++;
        }

        cout<<cnt<<endl;
    }
}